from django.http import JsonResponse
from django.core.exceptions import ValidationError
from django.core.cache import cache
from django.utils import timezone
from django.views import View
from django.db import transaction
from os import getenv
import pyotp
import requests
import jwt
import json

from authentication.decorators import token_required
from authentication.models import User, OTPSecret

"""
42 OAuth2의 흐름
1. https://api.intra.42.fr/oauth/authorize 사용자를 연결한다.
2. 사용자가 권한을 부여하는 화면이 반환된다.
3. 제공된 client_id를 포함한 authorize URL을 사용한다.
4. 사용자가 권한을 부여하는경우, redirect uri로 리다이렉션 되며, "code"를 반환한다.
5. https://api.intra.42.fr/oauth/token URI에 POST요청으로
    { client_id, client_secret, code, redirect_uri }
    인자를 넘겨준다. 서버 측에서 보안 연결을 통해 수행되야 한다.
6. 받은 "code"를 활용하여 /oauth/token URI를 통해 access_token 을 반환받는다.
7. access_token을 header에 추가하여 API request를 구성한다.
    curl -H "Authorization: Bearer YOUR_ACCESS_TOKEN" /
        https://api.intra.42.fr/v2/me
"""

"""
backend 인증 로직
1. frontend에서 redirectURI를 통하여 얻은 "code"를 받는다
2. "code"를 access_token으로 exchange한다.
3. access_token을 사용하여 /v2/me 에서 정보를 받는다.
4. email 정보를 사용하여 2FA를 실행한다
5. 첫번째 로그인의 경우 OTP에 필요한 secret을 생성하고
    URI로 QR code를 그린다
6. QR code를 사용해 google authenticator 등록
7. OTP 입력 및 검증
"""
TOKEN_EXPIRES= 7200
#TODO: this value for dev need to fix
LOCK_ACCOUNT = 15
MAX_ATTEMPTS = 5
API_URL = getenv("API_URL")
JWT_SECRET = getenv("JWT_SECRET")
INTRA_UID = getenv("INTRA_UID")
INTRA_SECRET_KEY = getenv("INTRA_SECRET_KEY")
REDIRECT_URI = getenv("REDIRECT_URI")
STATE = getenv("STATE")


"""
TODO
OTP 주의사항
1. HTTPS 통신 사용
2. OTP브루트포스 방지 (타임스탬프 확인)
3. 스로틀 속도 제한
"""

class UserInfo(View):
    @token_required
    def get(self, request, access_token):
        user_info = cache.get(f'user_data_{access_token}')
        if not user_info:
            return JsonResponse({"error": "Invalid token"}, status=401)
        data = {
            'id': user_info['id'],
            'email': user_info['email'],
            'login': user_info['login'],
            'usual_full_name': user_info['usual_full_name'],
            'image_link': user_info['image_link'],
        }
        return JsonResponse(data, status=200)

class OAuthView(View):
    @token_required
    def delete(self, request, access_token):
        """
        access_token 삭제
        """
        cache.delete(f'user_data_{access_token}')
        return JsonResponse({"message": "logout success"}, status=200)

    def post(self, request):
        """
        frontend에서 /oauth/authorize 경로로 보낸 후 redirection되어서 오는 곳.
        querystring으로 code를 가져온 후 code를 access_token으로 교환
        access_token을 cache에 저장해서 expires_in을 체크한다.
        """
        body = json.loads(request.body.decode('utf-8'))
        code = body.get("code")
        if not code:
            return JsonResponse({"error": "No code value in querystring"}, status=400)
        data = {
            "grant_type": "authorization_code",
            "client_id": INTRA_UID,
            "client_secret": INTRA_SECRET_KEY,
            "code": code,
            "redirect_uri": getenv("REDIRECT_URI"),
            "state": getenv("STATE"),
        }
        try:
            response = requests.post(f'{API_URL}/oauth/token', data=data)
            response_data = response.json()
            if response.status_code != 200:
                return JsonResponse(response_data, status=response.status_code)

            access_token = response_data.get("access_token")
            if not access_token:
                return JsonResponse({"error": "No access token in response"}, status=400)

            # TODO: async(get_user_info), return Response
            success, response = self.get_user_info(access_token)
            if success == False:
                return JsonResponse({"error": response}, status=500)
            encoded_jwt = jwt.encode({"access_token": access_token}, JWT_SECRET, algorithm="HS256")
            return JsonResponse(
                {
                    "jwt": encoded_jwt,
                    "otp_verified": True if cache.get(f'otp_passed_{access_token}') else False,
                    "show_otp_qr": response
                }, status=200)

        except requests.RequestException as e:
            error_message = {"error": str(e)}
            return JsonResponse(error_message, status=500)

    def get_user_info(self, access_token):
        """
        access_token을 활용하여 user의 정보를 받아온다.
        정보를 받아와서 db에 있는지 확인한 후 없을 경우 생성
        """
        headers = { "Authorization": f'Bearer {access_token}' }
        response = requests.get(f'{API_URL}/v2/me', headers=headers)
        if response.status_code == 200:
            data = response.json()
            #TODO: asynchronous if can
            try:
                with transaction.atomic():
                    user_data = self.get_or_create_user(data)
                    otp_data = self.get_or_create_otp_secret(data['id'])
            except transaction.TransactionManagementError as e:
                return False, {"error": str(e)}

            self.set_cache(user_data, otp_data, access_token)
            return True, otp_data.is_verified
        return False, response.json()

    def set_cache(self, user_data, otp_data, access_token):
        # TODO seperate user and otp cache
        cache_value = {
            'id': user_data.id,
            'email': user_data.email,
            'login': user_data.login,
            'usual_full_name': user_data.usual_full_name,
            'image_link': user_data.image_link,
            'need_otp': user_data.need_otp,
            'secret': otp_data.secret,
        }
        cache.set(f'user_data_{access_token}', cache_value, TOKEN_EXPIRES)

    def get_or_create_user(self, data):
        user, _ = User.objects.get_or_create(
            id=data['id'],
            defaults={
                'email': data['email'],
                'login': data['login'],
                'usual_full_name': data['usual_full_name'],
                'image_link': data['image']['link'],
            }
        )
        return user

    def get_or_create_otp_secret(self, user_id):
        otp_secret, _ = OTPSecret.objects.get_or_create(
            user_id=user_id,
            defaults={
                'secret': pyotp.random_base32(),
                'attempts': 0,
                'last_attempt': None,
                'is_locked': False,
            }
        )
        return otp_secret


class QRcodeView(View):

    @token_required
    def get(self, request, access_token):
        try:
            user_data = self.get_user_data(access_token)
            secret = self.get_user_secret(user_data)
            uri = self.generate_otp_uri(user_data, secret)
            return JsonResponse({"otpauth_uri": uri}, status=200)
        except ValidationError as e:
            return JsonResponse({"error": str(e)}, status=400)

    # It check user data twice but still need
    def get_user_data(self, access_token):
        user_data = cache.get(f'user_data_{access_token}')
        if not user_data:
            raise ValidationError("User data not found")
        return user_data

    def get_user_secret(self, user_data):
        secret = user_data.get('secret')
        if not secret:
            raise ValidationError("User secret not found")
        return secret

    def generate_otp_uri(self, user_data, secret):
        return pyotp.totp.TOTP(secret).provisioning_uri(
            name=user_data['email'],
            issuer_name="pong_game"
        )


class OTPView(View):

    @token_required
    def post(self, request, access_token):
        """
        OTP 패스워드를 확인하는 view
        OTP 정보 확인 및 900초 지났을 경우 시도 횟수 초기화
        계정 잠금, 정보 없음, OTP인증 실패 확인

        cache를 사용하여 저장할 경우 퍼포먼스의 이득을 볼 수 있지만
        데이터의 정합성을 위해서 db를 확인한다.
        """
        user_data = cache.get(f"user_data_{access_token}")
        user_id = user_data.get('id')
        otp_data = self.get_otp_data(user_id)
        if not otp_data:
            return JsonResponse({"error": "Can't found OTP data."}, status=500)

        now = timezone.now()
        if otp_data['is_locked']:
            if otp_data['last_attempt'] and (now - otp_data['last_attempt']).total_seconds() > LOCK_ACCOUNT:
                otp_data['is_locked'] = False
                otp_data['attempts'] = 0
            else:
                return JsonResponse({"error": "Account is locked. try later"}, status=403)

        otp_data['attempts'] += 1
        otp_data['last_attempt'] = now
        if otp_data['attempts'] >= MAX_ATTEMPTS:
            otp_data['is_locked'] = True
            self.update_otp_data(user_id, otp_data)
            return JsonResponse({"error": "Maximum number of attempts exceeded. Please try again after 15 minutes."}, status=403)

        body = json.loads(request.body.decode('utf-8'))
        otp_code = body.get("input_password")
        if pyotp.TOTP(otp_data['secret']).verify(otp_code):
            otp_data['attempts'] = 0
            otp_data['is_locked'] = False
            otp_data['is_verified'] = True
            cache.set(f'otp_passed_{access_token}', user_data, timeout=TOKEN_EXPIRES)
            self.update_otp_data(user_id, otp_data)
            return JsonResponse({"success": "OTP authentication verified"}, status=200)

        self.update_otp_data(user_id, otp_data)
        return JsonResponse(
            {
                "error": "Incorrect password.",
                "remain_attempts": MAX_ATTEMPTS - otp_data['attempts']
            }, status=400)

    def get_otp_data(self, user_id):
        """
        DB에서 otp data를 받아옴
        """
        if not user_id:
            return None
        try:
            otp_secret = OTPSecret.objects.get(user_id=user_id)
            data = {
                'secret': otp_secret.secret,
                'attempts': otp_secret.attempts,
                'last_attempt': otp_secret.last_attempt,
                'is_locked': otp_secret.is_locked,
                'is_verified': otp_secret.is_verified
            }
        except OTPSecret.DoesNotExist:
            return None
        return data

    def update_otp_data(self, user_id, data):
        """
        OTP 시도 횟수 및 시간 저장
        5회 이상 시도 시 계정 잠금 및 초기화 시간 900초 소요
        """
        OTPSecret.objects.filter(user_id=user_id).update(
            attempts=data['attempts'],
            last_attempt=data['last_attempt'],
            is_locked=data['is_locked'],
            is_verified=data['is_verified']
        )

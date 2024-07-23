from django.urls import path

from . import auth

urlpatterns = [
    path('token', auth.OAuthView.as_view(), name='exchange_token'),
    path('otp/qrcode', auth.QRcodeView.as_view(), name='otp_qrcode'),
    path('otp/verify', auth.OTPView.as_view(), name='otp_verify'),
]
from django.test import TestCase, RequestFactory
from django.http import JsonResponse
from unittest.mock import patch
import json
from authentication.decorators import token_required

class TokenRequiredDecoratorTests(TestCase):
    def setUp(self):
        self.factory = RequestFactory()
        self.JWT_SECRET = "test_secret"

    @token_required
    def dummy_view(self, request, access_token):
        return JsonResponse({"access_token": access_token})

    def test_no_jwt_in_request(self):
        request = self.factory.get('/dummy-url')
        response = self.dummy_view(request)
        self.assertEqual(response.status_code, 401)
        self.assertEqual(json.loads(response.content.decode('utf-8')), {"error": "No jwt in request"})

    def test_invalid_jwt_format(self):
        request = self.factory.get('/dummy-url', HTTP_AUTHORIZATION='InvalidToken')
        response = self.dummy_view(request)
        self.assertEqual(response.status_code, 401)
        self.assertEqual(json.loads(response.content.decode('utf-8')), {"error": "Decoding jwt failed"})

    @patch('authentication.decorators.jwt.decode')
    def test_no_access_token_in_jwt(self, mock_jwt_decode):
        mock_jwt_decode.return_value = {}
        request = self.factory.get('/dummy-url', HTTP_AUTHORIZATION='Bearer validJWT')
        response = self.dummy_view(request)
        self.assertEqual(response.status_code, 401)
        self.assertEqual(json.loads(response.content.decode('utf-8')), {"error": "No access token provided"})

    @patch('authentication.decorators.jwt.decode')
    @patch('authentication.decorators.cache.get')
    def test_invalid_access_token(self, mock_cache_get, mock_jwt_decode):
        mock_jwt_decode.return_value = {"access_token": "test_token"}
        mock_cache_get.return_value = None
        request = self.factory.get('/dummy-url', HTTP_AUTHORIZATION='Bearer validJWT')
        response = self.dummy_view(request)
        self.assertEqual(response.status_code, 401)
        self.assertEqual(json.loads(response.content.decode('utf-8')), {"error": "Invalid token"})

    @patch('authentication.decorators.jwt.decode')
    @patch('authentication.decorators.cache.get')
    def test_valid_access_token(self, mock_cache_get, mock_jwt_decode):
        mock_jwt_decode.return_value = {"access_token": "test_token"}
        mock_cache_get.return_value = True
        request = self.factory.get('/dummy-url', HTTP_AUTHORIZATION='Bearer validJWT')
        response = self.dummy_view(request)
        self.assertEqual(response.status_code, 200)
        self.assertEqual(json.loads(response.content.decode('utf-8')), {"access_token": "test_token"})
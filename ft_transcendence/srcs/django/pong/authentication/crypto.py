from os import getenv, urandom
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.backends import default_backend
from base64 import urlsafe_b64encode, urlsafe_b64decode

class AESCipher:
    HASH_SALT = getenv("HASH_SALT")
    key = str.encode(HASH_SALT)

    @staticmethod
    def encrypt(plaintext):
        iv = urandom(16)
        cipher = Cipher(algorithms.AES(AESCipher.key), modes.CFB(iv), backend=default_backend())
        encryptor = cipher.encryptor()
        ciphertext = encryptor.update(plaintext.encode()) + encryptor.finalize()
        return urlsafe_b64encode(iv + ciphertext).decode('utf-8')

    @staticmethod
    def decrypt(ciphertext):
        ciphertext = urlsafe_b64decode(ciphertext.encode('utf-8'))
        iv = ciphertext[:16]
        cipher = Cipher(algorithms.AES(AESCipher.key), modes.CFB(iv), backend=default_backend())
        decryptor = cipher.decryptor()
        plaintext = decryptor.update(ciphertext[16:]) + decryptor.finalize()
        return plaintext.decode('utf-8')
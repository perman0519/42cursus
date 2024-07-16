from django.urls import path
from .game import game, tournament

urlpatterns = [
    path('api/game/', game),
    path('api/tournament/', tournament),
]

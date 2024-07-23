from django.urls import path
from .game import game, tournament

urlpatterns = [
    path('game', game),
    path('tournament', tournament),
]

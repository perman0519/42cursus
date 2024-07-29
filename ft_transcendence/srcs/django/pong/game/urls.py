from django.urls import path
from . import game


urlpatterns = [
    path('game', game.GameView.as_view(), name='game'),
    path('tournament', game.TournamentView.as_view(), name='tournament'),
]

from django.db import models

GAME_MODES = [
    ('1VS1', '1vs1'),
    ('TOURNAMENT', 'Tournament')
]
# Create your models here.
class Game(models.Model):

    player1 = models.CharField(max_length=10)
    player2 = models.CharField(max_length=10)
    score = models.CharField(max_length=10)
    mode = models.CharField(max_length=10, choices=GAME_MODES)
    tournament = models.ForeignKey('Tournament', on_delete=models.SET_NULL, null=True)
    created_at = models.DateTimeField(auto_now_add=True)


class Tournament(models.Model):
    game1 = models.ForeignKey('Game', related_name='tournament_game1', on_delete=models.SET_NULL, null=True)
    game2 = models.ForeignKey('Game', related_name='tournament_game2', on_delete=models.SET_NULL, null=True)
    game3 = models.ForeignKey('Game', related_name='tournament_game3', on_delete=models.SET_NULL, null=True)

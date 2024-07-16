from django.http import JsonResponse
from django.views.decorators.csrf import csrf_exempt
from django.views.decorators.http import require_http_methods
from django.core.paginator import Paginator
from .models import Game, Tournament
import json
import logging

logger = logging.getLogger(__name__)

def validate_game(data, mode):
    errors = {}
    required_fields = ['player1', 'player2', 'score', 'mode']
    for field in required_fields:
        if field not in data:
            errors[field] = f"{field} is required."
    if data.get('mode') != mode:
        errors['mode'] = f"Game mode must be '{mode}'"
    return errors

@csrf_exempt
@require_http_methods(["GET", "POST"])
def game(request):
    if request.method == 'GET':
        page_number = int(request.GET.get('page', 1))
        page_size = int(request.GET.get('size', 10))  # 기본 페이지 크기는 10

        # 전체 게임 수 계산
        total_games = Game.objects.count()

        # 페이지에 해당하는 게임만 가져오기
        start = (page_number - 1) * page_size
        end = start + page_size
        games = Game.objects.order_by('-created_at')[start:end]

        response_data = []
        for game in games:
            game_data = {
                'id': game.id,
                'player1': game.player1,
                'player2': game.player2,
                'score': game.score,
                'mode': game.mode,
                'tournament_id': game.tournament_id,
                'created_at': game.created_at.isoformat()
            }
            response_data.append(game_data)

       # 페이지 정보 계산
        total_pages = (total_games + page_size - 1) // page_size
        has_next = page_number < total_pages
        has_previous = page_number > 1

        return JsonResponse({
            "games": response_data,
            "page": {
                "current": page_number,
                "has_next": has_next,
                "has_previous": has_previous,
                "total_pages": total_pages,
                "total_items": total_games,
            }
        }, safe=False)

    elif request.method == 'POST':
        try:
            data = json.loads(request.body)
            game = Game.objects.create(
                player1=data['player1'],
                player2=data['player2'],
                score=data['score'],
                mode=data['mode']
            )
            return JsonResponse({"status": "Game created successfully", "id": game.id}, status=201)
        except KeyError as e:
            return JsonResponse({"error": f"Missing required field: {str(e)}"}, status=400)
        except json.JSONDecodeError:
            return JsonResponse({"error": "Invalid JSON"}, status=400)
        except Exception as e:
            return JsonResponse({"error": str(e)}, status=500)

@csrf_exempt
@require_http_methods(["GET", "POST"])
def tournament(request):
    # tournament GET은 없지만 최소한으로만 구현
    # if request.method == 'GET':
    #     page_number = request.GET.get('page', 1)
    #     page_size = 10  # 한 페이지당 보여줄 토너먼트 수

    #     tournaments = Tournament.objects.all().order_by('id')
    #     paginator = Paginator(tournaments, page_size)
    #     page_obj = paginator.get_page(page_number)

    #     response_data = []
    #     for tournament in page_obj:
    #         tournament_data = {}
    #         for i in range(1, 4):
    #             game = getattr(tournament, f'game{i}')
    #             if game:
    #                 tournament_data[f'game{i}'] = {
							# 'id': game.id,
							# 'player1': game.player1,
							# 'player2': game.player2,
							# 'score': game.score,
							# 'mode': game.mode,
							# 'tournament_id': game.tournament_id,
							# 'created_at': game.created_at
    #                 }
    #         response_data.append(tournament_data)

    #     return JsonResponse({
    #         "tournaments": response_data,
    #         "page": {
    #             "current": page_obj.number,
    #             "has_next": page_obj.has_next(),
    #             "has_previous": page_obj.has_previous(),
    #             "total_pages": paginator.num_pages,
    #             "total_items": paginator.count,
    #         }
    #     }, safe=False)

	# elif request.method == 'POST':
    if request.method == 'POST':
        try:
            data = json.loads(request.body)
            tournament_errors = {}
            for i in range(1, 4):
                game_key = f'game{i}'
                if game_key not in data:
                    tournament_errors[game_key] = f"{game_key} is required."
                else:
                    game_errors = validate_game(data[game_key], 'TOURNAMENT')
                    if game_errors:
                        tournament_errors[game_key] = game_errors

            if tournament_errors:
                return JsonResponse({"errors": tournament_errors}, status=400)

            tournament = Tournament.objects.create()
            for i in range(1, 4):
                game_key = f'game{i}'
                game_data = data[game_key]
                game = Game.objects.create(tournament=tournament, **game_data)
                setattr(tournament, game_key, game)
            tournament.save()
            return JsonResponse({"status": "Tournament created successfully", "id": tournament.id}, status=201)
        except json.JSONDecodeError:
            return JsonResponse({"error": "Invalid JSON"}, status=400)
        except Exception as e:
                logger.error(f'error: {str(e)}')
                return JsonResponse({"error": str(e)}, status=400)

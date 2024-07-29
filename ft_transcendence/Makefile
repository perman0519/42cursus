NAME = pong

all: $(NAME)

$(NAME):
	docker-compose -f ./srcs/docker-compose.yml --profile=setup up --build -d

clean:
	docker-compose -f srcs/docker-compose.yml down
	rm -rf ./srcs/django/pong/pong_cache/
	rm -rf ./srcs/postgres/*
	docker volume rm -f django_data
	docker volume rm -f postgres_data

fclean:	clean
	-@docker rmi $(shell docker images -q) || true
	-@docker volume rm $(shell docker volume ls -q) || true
	sudo rm -rf ./srcs/postgres/*
	sudo rm -rf ./srcs/django/app/*

re: fclean all

.PHONY : all clean fclean re

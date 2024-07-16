NAME = inception

all: $(NAME)

$(NAME):
	docker-compose -f ./srcs/docker-compose.yml up -d --build

clean:
	docker-compose -f srcs/docker-compose.yml down

fclean:	clean
	-@docker rmi $(shell docker images -q) || true
	-@docker volume rm $(shell docker volume ls -q) || true
	sudo rm -rf ./srcs/postgres/*
	sudo rm -rf ./srcs/django/app/*

re: fclean all

.PHONY : all clean fclean re

NAME = inception

all: $(NAME)

$(NAME):
	mkdir /Users/songjunsang/data/wp || true
	mkdir /Users/songjunsang/data/db || true
	docker-compose -f ./srcs/docker-compose.yml up -d --build

clean:
	docker-compose -f srcs/docker-compose.yml down

fclean:	clean
	-@docker rmi $(shell docker images -q) || true
	-@docker volume rm $(shell docker volume ls -q) || true
	sudo rm -rf /Users/songjunsang/data/*

re: fclean all

.PHONY : all clean fclean re

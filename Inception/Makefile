NAME = inception

all: $(NAME)

$(NAME):
	mkdir /home/login/data/wp || true
	mkdir /home/login/data/db || true
	docker-compose -f ./srcs/docker-compose.yml up -d
	@docker-compose -f ./srcs/docker-compose.yml logs -f

clean:
	docker-compose -f srcs/docker-compose.yml down

fclean:	clean
	-@docker rmi $(shell docker images -q) || true
	-@docker volume rm $(shell docker volume ls -q) || true
	-@docker network rm $(shell docker network ls -q) || true
	sudo rm -rf /home/login/data/db/*
	sudo rm -rf /home/login/data/wp/*

re: fclean all

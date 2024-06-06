NAME = inception

all: $(NAME)

$(NAME):
	docker-compose -f srcs/docker-compose.yml up -d
	@docker-compose -f srcs/docker-compose.yml logs -f


clean:
	docker-compose -f srcs/docker-compose.yml down

fclean:	clean
	-@docker rmi $(shell docker images -q) || true
	-@docker volume rm $(shell docker volume ls -q) || true
	-@docker network rm $(shell docker network ls -q) || true
	rm -rf ~/mariadb/* ~/wordpress/*

re: fclean all

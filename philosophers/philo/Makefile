#-------------------------------------------
GREEN		=	"\033[0;32m"
EOC			=   "\033[0;0m"
#-------------------------------------------
NAME	=	philo
CC		=	gcc
DFLAGS	=	-Wall -Wextra -Werror -g -fsanitize=thread
CFLAGS	=	-Wall -Wextra -Werror
SRC		=	main.c init.c util.c thread_main.c \
			usleep_thread.c eat_philo.c print_thread.c \
			monitor.c start_threads.c
OBJ		=	$(SRC:.c=.o)

all 	: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo $(GREEN) "philosopher made." $(EOC)

%.o		: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	$(RM) $(OBJ)
	@echo $(GREEN) "cleaned." $(EOC)

fclean	: clean
	$(RM) $(NAME)
	@echo $(GREEN) "f cleaned." $(EOC)

re		: fclean all

debug	: $(SRC)
	$(CC) $(DFLAGS) $(SRC)
	@echo $(GREEN) "debug made." $(EOC)

.PHONY	: clean fclean re

#-------------------------------------------
GREEN		=	"\033[0;32m"
EOC			=   "\033[0;0m"
#-------------------------------------------
NAME	=	philo_bonus
CC		=	gcc
DFLAGS	=	-Wall -Wextra -Werror
CFLAGS	=	-Wall -Wextra -Werror
SRC		=	main_bonus.c init_share_bonus.c init_philo_bonus.c \
			init_arg_bonus.c util_bonus.c process_main_bonus.c \
			usleep_process_bonus.c eat_philo_bonus.c print_process_bonus.c \
			monitor_bonus.c start_process_bonus.c ft_itoa_bonus.c
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
	$(CC) $(DFLAGS) -g $(SRC)
	@echo $(GREEN) "bonus_debug made." $(EOC)


.PHONY	: clean fclean re

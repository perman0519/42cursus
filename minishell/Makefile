#-------------------------------------------

BLACK       =   "\033[0;30m"
GRAY        =   "\033[1;30m"
RED         =   "\033[1;31m"
GREEN       =   "\033[0;32m"
YELLOW      =   "\033[1;33m"
PURPLE      =   "\033[0;35m"
CYAN        =   "\033[1;36m"
WHITE       =   "\033[1;37m"
EOC         =   "\033[0;0m"
LINE_CLEAR  =   "\x1b[1A\x1b[M"

#-------------------------------------------

LIBFT		=	./libft/libft.a
SRCDIR		=	./src
SRC			=	main.c main_util.c \
				is_built_in.c ft_cd.c ft_echo.c ft_env.c \
				ft_exit.c ft_export.c ft_pwd.c ft_unset.c \
				expansion.c expansion_util.c expansion_util2.c \
				tokenizer.c tokenizer_help.c syntax_analyzer.c \
				dequotenizer.c struct_cmd.c \
				init_redir.c count_pipe.c pipeline.c pipeline_child.c \
				pipeline_child_help.c pipeline_help.c pipeline_help2.c \
				handler.c heredoc.c heredoc_util.c \
				utils.c utils_2.c utils_3.c utils_4.c

SRC			:=	$(addprefix $(SRCDIR)/, $(SRC))
OBJ			=	$(SRC:.c=.o)

NAME		= minishell
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
LDFLAGS		= -L/Users/$(USER)/.brew/opt/readline/lib -lreadline
LIBFLAGS	= -Llibft -lft
INC			= -Ilibft -I/Users/$(USER)/.brew/opt/readline/include

all:		$(NAME)

$(NAME): 	$(OBJ) $(LIBFT)
		@$(CC) $(LIBFLAGS) $(LDFLAGS) $(OBJ) -o $(NAME)
		@echo $(GREEN)"minishell made." $(EOC)

$(LIBFT):
		@make --no-print-directory -C ./libft bonus

%.o: 		%.c
		@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
		@cd libft; make clean
		@$(RM) $(OBJ)
		@echo $(GREEN)"minishell cleaned." $(EOC)

fclean:		clean
		@cd libft; make fclean
		@$(RM) $(NAME)
		@echo $(GREEN)"minishell fcleaned." $(EOC)

re:			fclean all

.PHONY:		clean fclean re

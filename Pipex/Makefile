# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 11:08:05 by junssong          #+#    #+#              #
#    Updated: 2023/06/12 14:35:06 by junssong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex
BONUS_NAME	= pipex_bonus
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g

SRCS_DIR	= ./srcs/
LIBFT_DIR	= ./libft
INCS_DIR	= ./includes
BONUS_DIR	= ./bonus_srcs/

LIBFT		= $(LIBFT_DIR)libft.a
INCS		= -I includes

SRC			= pipex.c do_execve.c find_absolute_path.c set_param.c
BONUS_SRC	= pipex_bonus.c do_execve_bonus.c find_absolute_path_bonus.c \
			set_param_bonus.c

SRCS	= $(addprefix $(SRCS_DIR), $(SRC))
BONUS_SRCS = $(addprefix $(BONUS_DIR), $(BONUS_SRC))

OBJS	= $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -I $(INCS_DIR) -o $@ -c $?

$(NAME) : $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft $(INCS)

$(BONUS_NAME) : $(BONUS_OBJS)
	make -C $(LIBFT_DIR)
	$(CC) -o $(BONUS_NAME) $(BONUS_OBJS) -L$(LIBFT_DIR) -lft $(INCS) $(MLX_FLAGS)

all : $(NAME)

bonus : $(BONUS_NAME)

clean :
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJS)
	rm -rf $(BONUS_OBJS)

fclean :
	make -C $(LIBFT_DIR) fclean
	rm -rf $(OBJS)
	rm -rf $(BONUS_OBJS)
	rm -rf $(NAME)
	rm -rf $(BONUS_NAME)

re : fclean all

.PHONY : all clean fclean re

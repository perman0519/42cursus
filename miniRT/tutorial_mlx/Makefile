# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junssong <junssong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 11:08:05 by junssong          #+#    #+#              #
#    Updated: 2024/01/30 17:23:15 by junssong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= miniRT
BONUS_NAME	= miniRT_bonus
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRCS_DIR	= ./srcs/
LIBFT_DIR	= ./libft
INCS_DIR	= ./includes
MLX_DIR		= ./mlx
BONUS_DIR	= ./bonus_srcs/

LIBFT		= $(LIBFT_DIR)libft.a
INCS		= -I includes
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

SRC		= main.c
BONUS_SRC =
SRCS	= $(addprefix $(SRCS_DIR), $(SRC))
BONUS_SRCS = $(addprefix $(BONUS_DIR), $(BONUS_SRC))
OBJS	= $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -I $(INCS_DIR) -o $@ -c $?

$(NAME) : $(OBJS)
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	$(CC) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft $(INCS) $(MLX_FLAGS)

$(BONUS_NAME) : $(BONUS_OBJS)
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	$(CC) -o $(BONUS_NAME) $(BONUS_OBJS) -L$(LIBFT_DIR) -lft $(INCS) $(MLX_FLAGS)

all : $(NAME)

bonus : $(BONUS_NAME)

clean :
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	rm -rf $(OBJS)
	rm -rf $(BONUS_OBJS)

fclean :
	make -C $(LIBFT_DIR) fclean
	make -C $(MLX_DIR) clean
	make clean
	rm -rf $(NAME)
	rm -rf $(BONUS_NAME)

re : fclean all

.PHONY : all clean fclean re

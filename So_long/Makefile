# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 11:08:05 by junssong          #+#    #+#              #
#    Updated: 2023/05/30 12:56:56 by junssong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
BONUS_NAME	= so_long_bonus
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g

SRCS_DIR	= ./srcs/
LIBFT_DIR	= ./libft
INCS_DIR	= ./includes
MLX_DIR		= ./mlx
BONUS_DIR	= ./bonus_srcs/

LIBFT		= $(LIBFT_DIR)libft.a
INCS		= -I includes
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

SRC		= main.c hook.c read_map.c map_error.c dfs.c print_map.c \
		  set_param.c check_c_e.c
BONUS_SRC =  main_bonus.c hook_bonus.c read_map_bonus.c map_error_bonus.c \
			  dfs_bonus.c print_map_bonus.c \
			  set_param_bonus.c check_c_e_bonus.c
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
	rm -rf $(OBJS)
	rm -rf $(BONUS_OBJS)
	rm -rf $(NAME)
	rm -rf $(BONUS_NAME)

re : fclean all

.PHONY : all clean fclean re

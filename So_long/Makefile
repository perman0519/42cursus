# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 11:08:05 by junssong          #+#    #+#              #
#    Updated: 2023/05/26 19:48:50 by junssong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g

SRCS_DIR	= ./srcs/
LIBFT_DIR	= ./libft
INCS_DIR	= ./includes
MLX_DIR		= ./mlx

LIBFT		= $(LIBFT_DIR)libft.a
INCS		= -I includes
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

SRC		= main.c hook.c read_map.c map_error.c dfs.c print_map.c \
		  set_param.c check_c_e.c
SRCS	= $(addprefix $(SRCS_DIR), $(SRC))
OBJS	= $(SRCS:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -I $(INCS_DIR) -o $@ -c $?

$(NAME) : $(OBJS)
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	$(CC) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft $(INCS) $(MLX_FLAGS)

all : $(NAME)

clean :
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	rm -rf $(OBJS)

fclean :
	make -C $(LIBFT_DIR) fclean
	make -C $(MLX_DIR) clean
	rm -rf $(OBJS)
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re

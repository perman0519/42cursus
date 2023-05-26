# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 13:40:13 by junssong          #+#    #+#              #
#    Updated: 2023/05/09 14:49:17 by junssong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
LIBFT = Libft/libft.a
SRCS1 = main.c \
		list.c \
		parse_argv.c \
		sa.c \
		sb.c \
		ss.c \
		pa.c \
		pb.c \
		ra.c \
		rb.c \
		rr.c \
		rra.c \
		rrb.c \
		rrr.c \
		add_and_remove.c \
		is_sorted.c \
		sort.c \
		free_split.c \
		sort_size3.c \
		sort_size5.c \
		find_min_max.c \
		sort_size_more.c \
		rrr_or_rr.c

all : $(NAME)

${NAME} : $(SRCS1)
				make -C Libft
				cc $(CFLAGS) -g $^ $(LIBFT) -o $(NAME)

clean :
	cd Libft; make clean

fclean :
	cd Libft; make fclean
	rm -rf $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re

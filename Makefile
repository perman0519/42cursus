# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junssong <junssong@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 13:40:13 by junssong          #+#    #+#              #
#    Updated: 2023/03/16 14:45:40 by junssong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRCS1 = ft_putchar.c \
		ft_puthex.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_putpoint.c \
		ft_printf.c \

OBJS1 = $(SRCS1:.c=.o)

all : $(NAME)

${NAME} : $(OBJS1)
				ar -rc $(NAME) $(OBJS1)

clean :
	rm -rf $(OBJS1)

fclean : clean
	rm -rf $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re


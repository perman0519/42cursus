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

NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
SRCS1 = ft_atoi.c \
		ft_strnstr.c \
		ft_bzero.c \
		ft_strncmp.c \
		ft_memcpy.c \
		ft_isalnum.c \
		ft_memmove.c \
		ft_strrchr.c \
		ft_isalpha.c \
		ft_memset.c \
		ft_strrchr.c \
		ft_isascii.c \
		ft_strchr.c \
		ft_tolower.c \
		ft_isdigit.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_isprint.c \
		ft_strlcpy.c \
		ft_memchr.c \
		ft_strlen.c \
		ft_memcmp.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c

SRCS2 = ft_lstnew_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c

HEADER = libft.h
OBJS1 = $(SRCS1:.c=.o)
OBJS2 = $(SRCS2:.c=.o)

ifdef WITH_BONUS
	OBJ_FILES = $(OBJS1) $(OBJS2)
else
	OBJ_FILES = $(OBJS1)
endif

all : $(NAME)

${NAME} : $(OBJ_FILES) $(HEADER)
				ar -rc $(NAME) $(OBJ_FILES)

bonus :
	make WITH_BONUS=1 all

%.o : %.c $(HEADER)
	cc $(CFLAGS) -c $< -o $@ -I $(HEADER)

clean :
	rm -rf $(OBJS1) $(OBJS2)

fclean : clean
	rm -rf $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all bonus clean fclean re


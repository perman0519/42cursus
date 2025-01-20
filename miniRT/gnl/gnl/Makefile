NAME = libgnl.a

CC = cc
CCFLAGS = -c -Wall -Werror -Wextra

SRCS =	get_next_line_bonus.c \
		get_next_line_utils_bonus.c

OBJS = $(SRCS:.c=.o)

INCLUDE = -I ./

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CCFLAGS) $(INCLUDE) $<

clean :
	rm -f $(OBJS)

fclean :
	make clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re

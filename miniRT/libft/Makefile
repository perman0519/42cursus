NAME = libft.a

CC = cc
CCFLAGS = -c -Wall -Werror -Wextra

SRC_MAIN = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_atof.c
SRC_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJ_MAIN = $(SRC_MAIN:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

ifdef FLAG_BONUS
	OBJS = $(OBJ_MAIN) $(OBJ_BONUS)
else
	OBJS = $(OBJ_MAIN)
endif

INCLUDE = -I libft.h

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CCFLAGS) $(INCLUDE) $<

clean :
	rm -f $(OBJ_MAIN)
	rm -f $(OBJ_BONUS)

fclean :
	make clean
	rm -f $(NAME)

re :
	make fclean
	make all

bonus :
	make FLAG_BONUS=1 all

.PHONY : all clean fclean re bonus

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

NAME = libft.a

CC = cc
CFLAG = -Wall -Wextra -Werror

SRCS = ft_isascii.c ft_strlen.c  ft_toupper.c \
	   ft_atoi.c ft_isdigit.c  ft_strncmp.c \
	   ft_isalnum.c ft_isprint.c ft_strrchr.c \
	   ft_isalpha.c ft_strchr.c  ft_tolower.c \
	   ft_strlcpy.c ft_strlcat.c ft_strnstr.c \
	   ft_bzero.c ft_memset.c ft_memchr.c \
	   ft_memcmp.c ft_memcpy.c ft_memmove.c \
	   ft_calloc.c ft_strdup.c \
	   ft_substr.c ft_strjoin.c ft_strtrim.c \
	   ft_split.c ft_itoa.c ft_strmapi.c \
	   ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	   ft_putendl_fd.c ft_putnbr_fd.c

SRCS_BN = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		  ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		  ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \
		  ft_lstadd_mid.c ft_lstdel_mid.c

ifdef WITH_BONUS
	OBJS = $(SRCS:.c=.o) $(SRCS_BN:.c=.o)
else
	OBJS = $(SRCS:.c=.o)
endif


%.o: %.c
	@$(CC) $(CFLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@ar rsc $(NAME) $(OBJS)
	@echo $(GREEN)"libft made." $(EOC)

clean:
	@rm -f $(OBJS) $(SRCS_BN:.c=.o)
	@echo $(GREEN)"libft cleaned." $(EOC)

fclean: clean
	@rm -f $(NAME)
	@echo $(GREEN)"libft fcleaned." $(EOC)

re: fclean all

bonus : $(OBJS)
	@sleep 1
	@make WITH_BONUS=1 all
	@echo $(GREEN)"libft bonus made." $(EOC)

.PHONY: all clean fclean re bonus

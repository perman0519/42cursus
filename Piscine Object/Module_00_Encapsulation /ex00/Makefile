NAME = test
CFLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
SRCS = $(wildcard *.cpp)
all: $(NAME)

$(NAME): main.o
	$(CC) $(CFLAGS) main.o -o $(NAME)
NAME = ex00
CFLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all
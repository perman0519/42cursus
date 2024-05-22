NAME = ircserv
CXX = c++
CXXFLAGS = -I $(HEADERS_DIR) -Wall -Wextra -Werror -std=c++98
SRC = ./srcs/main.cpp \
		./srcs/Server.cpp \
		./srcs/EventHandler.cpp \
		./srcs/Channel.cpp \
		./srcs/Client.cpp \
		./srcs/utils.cpp \
		./srcs/Commands/Join.cpp \
		./srcs/Commands/Kick.cpp \
		./srcs/Commands/Nick.cpp \
		./srcs/Commands/Ping.cpp \
		./srcs/Commands/Invite.cpp \
		./srcs/Commands/Privmsg.cpp \
		./srcs/Commands/User.cpp \
		./srcs/Commands/Topic.cpp \
		./srcs/Commands/Mode.cpp \
		./srcs/Commands/Pass.cpp \
		./srcs/Bot.cpp \
		./srcs/Commands/Names.cpp

OBJS = $(SRC:.cpp=.o)
HEADERS_DIR = ./includes

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


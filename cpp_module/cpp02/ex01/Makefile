CC = c++
CPPFLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = ex01
CPP = .cpp
HPP = .hpp
SRCDIR = ./
INCDIR = ./

SRC = $(wildcard $(SRCDIR)/*$(CPP))
INC = $(wildcard $(INCDIR)/*$(HPP))
RM = rm -rf

all: $(NAME)


$(NAME): $(SRC) $(INC)
	@$(CC) $(SRC) $(CPPFLAGS) -o $@


.PHONY: clean
clean:
	@$(RM) $(NAME)

.PHONY: re
re:
	@$(MAKE) clean
	@$(MAKE) all

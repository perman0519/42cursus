CC = c++
CPPFLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = a.out
TPP = .tpp
CPP = .cpp
HPP = .hpp
SRCDIR = ./
INCDIR = ./

SRC = $(wildcard $(SRCDIR)*$(CPP))
SRC_TPP = $(wildcard $(SRCDIR)*$(TPP))
INC = $(wildcard $(INCDIR)*$(HPP))
RM = rm -rf

all: $(NAME)

# Builds the app
$(NAME): $(SRC) $(SRC_TPP) $(INC)
	@$(CC) $(SRC) $(CPPFLAGS) -o $@

# Cleans complete project
.PHONY: clean
clean:
	@$(RM) $(NAME)

.PHONY: re
re:
	@$(MAKE) clean
	@$(MAKE) all

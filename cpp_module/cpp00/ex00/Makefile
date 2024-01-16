CC = c++
CPPFLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = pvon_neiman
CPP = .cpp
HPP = .hpp
SRCDIR = ./
INCDIR = ./

SRC = $(wildcard $(SRCDIR)/*$(CPP))
INC = $(wildcard $(INCDIR)/*$(HPP))
RM = rm -rf

all: $(NAME)

# Builds the app
$(NAME): $(SRC) $(INC)
	@$(CC) $(SRC) $(CPPFLAGS) -o $@

# Cleans complete project
.PHONY: clean
clean:
	@$(RM) $(NAME)

.PHONY: re
re:
	@$(MAKE) clean
	@$(MAKE) all

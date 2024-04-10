#-------------------------------------------
GREEN		=	"\033[0;32m"
EOC			=   "\033[0;0m"
#-------------------------------------------

CC = c++
CPPFLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = RPN
CPP = .cpp
HPP = .hpp
SRCDIR = ./
INCDIR = ./

SRC = $(wildcard $(SRCDIR)*$(CPP))
INC = $(wildcard $(INCDIR)*$(HPP))
OBJ = $(SRC:.cpp=.opp)
RM = rm -rf

all: $(NAME)

# Builds the app
$(NAME): $(OBJ)
	@$(CC) $(CPPFLAGS) $(OBJ) -o $@
	@echo $(GREEN) "ex01 made." $(EOC)

%.opp : %.cpp
	@$(CC) $(CPPFLAGS) -c $< -o $@

# Removes object files
clean:
	@$(RM) $(OBJ)
	@echo $(GREEN) "cleaned." $(EOC)

# Removes object files and the app
fclean	: clean
	@$(RM) $(NAME)
	@echo $(GREEN) "f cleaned." $(EOC)

# Re-making the app
re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: clean  fclean re all

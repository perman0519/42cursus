CC = c++
CPPFLAGS = -std=c++98 -Wall -Wextra -Werror

APPNAME = account
CPP = .cpp
HPP = .hpp
SRCDIR = ./
INCDIR = ./

SRC = $(wildcard $(SRCDIR)/*$(CPP))
INC = $(wildcard $(INCDIR)/*$(HPP))
RM = rm -rf

all: $(APPNAME)

# Builds the app
$(APPNAME): $(SRC) $(INC)
	@$ $(CC) $(SRC) $(CPPFLAGS) -o $@

# Cleans complete project
.PHONY: clean
clean:
	@$ $(RM) $(APPNAME)
.PHONY: re
re:
	@$(MAKE) -s clean
	@$(MAKE) -s all

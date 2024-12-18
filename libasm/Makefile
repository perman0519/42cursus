NAME = libasm.a
TEST = test
TEST_FILE = main.c
NASM_FLAG = -f macho64
SRC_DIR = ./src
OBJ_DIR = ./obj
LIB_DIR = ./lib
SRCS1 = $(wildcard $(SRC_DIR)/*.s)
OBJS1 = $(SRCS1:$(SRC_DIR)/%.s=$(OBJ_DIR)/%.o)
all : $(LIB_DIR)/$(NAME)

$(LIB_DIR)/$(NAME) : $(OBJS1)
	ar -rcs $@ $^

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s
	nasm $(NASM_FLAG) -o $@ $<

${TEST} : $(LIB_DIR)/$(NAME) $(TEST_FILE)
		gcc -o $@ main.c -L$(LIB_DIR) -lasm -lc -nostartfiles

clean :
	rm -rf $(OBJS1)

fclean : clean
	rm -rf $(LIB_DIR)/$(NAME)
	rm -rf $(TEST)

re : fclean all

.PHONY : all bonus clean fclean re

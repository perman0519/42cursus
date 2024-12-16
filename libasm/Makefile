NAME = libasm.a
TEST = test
NASM_FLAG = -f macho64
SRC_DIR = ./asm
OBJ_DIR = ./obj
LIB_DIR = ./lib
SRCS1 = $(wildcard $(SRC_DIR)/*.s)
OBJS1 = $(SRCS1:$(SRC_DIR)/%.s=$(OBJ_DIR)/%.o)
all : $(NAME)

${NAME} : $(OBJS1)
		ar -rcs $@ $^
		mv $(NAME) $(LIB_DIR)

${TEST} : $(LIB_DIR)/$(NAME)
		gcc -o $@ main.c -L$(LIB_DIR) -lasm

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s
	nasm $(NASM_FLAG) -o $@ $<

clean :
	rm -rf $(OBJS1)

fclean : clean
	rm -rf $(LIB_DIR)/$(NAME)

re : fclean all

.PHONY : all bonus clean fclean re

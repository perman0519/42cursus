NAME = libmylib.a
NASM_FLAG = -f macho64
SRC_DIR = ./asm
OBJ_DIR = ./obj
SRCS1 = $(wildcard $(SRC_DIR)/*.asm)
OBJS1 = $(SRCS1:$(SRC_DIR)/%.asm=$(OBJ_DIR)/%.o)
all : $(NAME)

${NAME} : $(OBJS1)
		ar -rcs $@ $^

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.asm
	nasm $(NASM_FLAG) -o $@ $<

clean :
	rm -rf $(OBJS1)

fclean : clean
	rm -rf $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all bonus clean fclean re

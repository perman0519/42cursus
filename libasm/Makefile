NAME = libasm.a
BONUS = libbonus.a
TEST = test
TEST_FILE = main.c
BONUS_TEST = bonus_test
BONUS_TEST_FILE = bonus.c
NASM_FLAG = -f macho64
SRC_DIR = ./src
OBJ_DIR = ./obj
LIB_DIR = ./lib
BONUS_DIR = ./bonus
SRCS1 = $(wildcard $(SRC_DIR)/*.s)
BONUS_SRCS = $(wildcard $(BONUS_DIR)/*.s)
OBJS1 = $(SRCS1:$(SRC_DIR)/%.s=$(OBJ_DIR)/%.o)
BONUS_OBJS = $(BONUS_SRCS:$(BONUS_DIR)/%.s=$(OBJ_DIR)/%.o)

all : $(LIB_DIR)/$(NAME)

$(LIB_DIR)/$(NAME) : $(OBJS1)
	ar -rcs $@ $^

$(LIB_DIR)/$(BONUS) : $(OBJS1) $(BONUS_OBJS)
	ar -rcs $@ $^

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s
	nasm $(NASM_FLAG) -o $@ $<

$(OBJ_DIR)/%.o : $(BONUS_DIR)/%.s
	nasm $(NASM_FLAG) -o $@ $<

bonus: $(LIB_DIR)/$(BONUS)

${TEST} : $(LIB_DIR)/$(NAME) $(TEST_FILE)
		gcc -o $@ $(TEST_FILE) -L$(LIB_DIR) -lasm -lc -nostartfiles

${BONUS_TEST} : $(LIB_DIR)/$(BONUS) $(BONUS_TEST_FILE)
		gcc -o $@ $(BONUS_TEST_FILE) -L$(LIB_DIR) -lbonus -lc -nostartfiles

clean :
	rm -rf $(OBJS1)
	rm -rf $(BONUS_OBJS)

fclean : clean
	rm -rf $(LIB_DIR)/$(NAME)
	rm -rf $(LIB_DIR)/$(BONUS)
	rm -rf $(TEST)
	rm -rf $(BONUS_TEST)

re : fclean all

.PHONY : all bonus clean fclean re

NAME = test2
NASM_FLAG = -f elf64
SRCS1 = hello1.asm
OBJS1 = $(SRCS1:.asm=.o)
all : $(NAME)

${NAME} : $(OBJS1)
		ld -o $@ $^

%.o : %.asm
	nasm $(NASM_FLAG) -o $@ $<

clean :
	rm -rf $(OBJS1)

fclean : clean
	rm -rf $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all bonus clean fclean re

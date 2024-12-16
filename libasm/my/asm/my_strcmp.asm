section .text
	global my_strcmp

; int strcmp(const char *s1, const char *s2);
my_strcmp :
	xor rax, rax
	xor r8, r8
	xor r9, r9

my_strcmp_loop:
	cmp byte[rdi + r8], 0
	je ret_cmp
	cmp byte[rsi + r9], 0
	jne ret_cmp
	movsx rax, al
	inc r8
	inc r9
	jmp my_strcmp_loop

ret_cmp:
	mov al, byte[rdi + r8]
	mov bl, byte[rsi + r9]
	sub al, bl
	movsx rax, al
	ret

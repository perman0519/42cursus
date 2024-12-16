section .text
	global my_strlen

; size_t strlen(const char *s); rdi
my_strlen:
	xor rax, rax

strlen_loop:
	cmp byte [rdi + rax], 0
	je strlen_done
	inc rax
	jmp strlen_loop

strlen_done:
	ret

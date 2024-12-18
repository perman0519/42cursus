section .text
	global _my_strlen
	;length of string

; size_t strlen(const char *s); rdi
_my_strlen:
	xor rax, rax
	push rbp
	mov rbp, rsp

strlen_loop:
	cmp byte [rdi + rax], 0
	je strlen_done
	inc rax
	jmp strlen_loop

strlen_done:
	pop rbp
	ret
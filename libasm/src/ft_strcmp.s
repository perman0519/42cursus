section .text
	global _my_strcmp

; int strcmp(const char *s1, const char *s2);
_my_strcmp :
	xor rax, rax
	xor r8, r8
	xor r9, r9

_my_strcmp_loop:
	cmp byte[rdi + r8], 0
	je ret_cmp
	cmp byte[rsi + r9], 0
	je ret_cmp
	mov al, byte[rdi + r8]
	mov bl, byte[rsi + r9]
	cmp al, bl
	jne ret_cmp
	inc r8
	inc r9
	jmp _my_strcmp_loop

ret_cmp:
	mov al, byte[rdi + r8]
	mov bl, byte[rsi + r9]
	sub al, bl
	movsx rax, al ; rax에 al의 값을 sign-extend하여 저장
	ret

section .text
	extern ___error
	global _my_write

; ssize_t _my_write(int fd, const void *buff, size_t count);
_my_write:
	mov rax, 0x2000004;
	push rbp
	mov rbp, rsp
	push rdx
	syscall
	pop rdx
	cmp rax, rdx
	jne write_fail
	xor rax, rax
	pop rbp
	ret

write_fail:
	mov rdi, rax
	call ___error
	mov [rax], edi
	mov rax, -1
	pop rbp
	ret
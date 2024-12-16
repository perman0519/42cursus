section .text
	extern ___error
	global _my_write

; ssize_t _my_write(int fd, const void *buff, size_t count);
_my_write:
	mov rax, 0x2000004;
	syscall
	js write_fail
	ret

write_fail:
	neg rax
	mov rdi, rax
	call ___error
	mov [rax], edi
	mov rax, -1
	ret
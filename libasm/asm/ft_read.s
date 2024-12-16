
section .text
	extern ___error
	global _my_read

; ssize_t _my_read(int fd, const void *buff, size_t count);
_my_read:
	mov rax, 0x2000003
	syscall
	js read_fail
	ret

read_fail:
	neg rax
	mov rdi, rax
	call ___error
	mov [rax], edi
	mov rax, -1
	ret


section .text
	extern __errno_location
	global my_write

; ssize_t my_write(int fd, const void *buff, size_t count);
my_write:
	mov rax, 1;
	syscall
	js write_fail
	ret ; 에러코드를 밷음

write_fail:
	neg rax
	mov rdi, rax
	call __errno_location
	mov [rax], edi
	mov rax, -1
	ret

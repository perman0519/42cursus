section .text
	extern ___error
	global _my_write

; ssize_t _my_write(int fd, const void *buff, size_t count);
_my_write:
	push rbp
	mov rbp, rsp
	mov rax, 0x2000004;
	syscall
	jc write_fail
	pop rbp
	ret

write_fail:
	mov rdi, rax
	call ___error ; 함수가 실행될때 이 다음 주소를 저장해야 함
	mov [rax], rdi
	mov rax, -1
	pop rbp
	ret
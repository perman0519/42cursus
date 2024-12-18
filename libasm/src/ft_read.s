
section .text
	extern ___error
	global _my_read

; ssize_t _my_read(int fd, const void *buff, size_t count);
_my_read:
	mov rax, 0x2000003
	syscall
	jc read_fail
	ret

read_fail:
	mov rdi, rax ; rdi = rax
	call ___error ; rax에 errno 주소 저장
	mov [rax], edi ; rax 역참조로 errno에 rdi 저장
	mov rax, -1
	ret
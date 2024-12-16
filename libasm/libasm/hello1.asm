section .data
	msg db "hello, world!" , 0xA ; 줄바꿈 추가
	len equ $ - msg ; 문자열의 끝 위치 - 시작위치

section .text
	global _start
_start:
	mov rax, 1  ; 임시 레지스터, syscall을 호출할 때 rax에는 syscall 번호가 있어야 함
	mov rdi, 1 ; 첫 argument of syscall
	mov rsi, msg ; second argument of syscall
	mov rdx, len ; third argument of syscall
	syscall

	; exit(0)
	mov rax, 60
	xor rdi, rdi ; mov rdi, 0 xor를 하는게 더 효율적임
	syscall


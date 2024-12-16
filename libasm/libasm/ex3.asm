section .data
	SYS_WRITE equ 1
	STD_IN    equ 1
	SYS_EXIT  equ 60
	EXIT_CODE equ 0

	NEW_LINE   db 0xa
	WRONG_ARGC db "Must be two command line argument", 0xa

section .text
	global _start

_start:
	pop rcx
	cmp rcx, 3
	jne argcError

	add rsp, 8
	pop rsi
	call str_to_int

	mov r10, rax
	pop rsi
	call str_to_int
	mov r11, rax

	add r10, r11

argcError:
	;; sys_write 시스템 콜
	mov rax, 1
	;; 파일 디스크립터, 표준 출력
	mov rdi, 1
	;; 메시지 주소
	mov rsi, WRONG_ARGC
	;; 메시지 길이
	mov rdx, 34
	;; write 시스템 콜 호출
	syscall
	;; 프로그램 종료
	jmp exit

str_to_int:
	xor rax, rax
	mov rcx,  10

next:
	cmp [rsi], byte 0
	je return_str
	mov bl, [rsi]
		sub bl, 48
	mul rcx
	add rax, rbx
	inc rsi
	jmp next

return_str:
	ret

int_to_str:
	mov rdx, 0
	mov rbx, 10
	div rbx
	add rdx, 48
	add rdx, 0x0
	push rdx
	inc r12
	cmp rax, 0x0
	jne int_to_str
	jmp print

print:
	;;;; 숫자 길이 계산
	mov rax, 1
	mul r12
	mov r12, 8
	mul r12
	mov rdx, rax
	;;;; 합 출력
	mov rax, SYS_WRITE
	mov rdi, STD_IN
	mov rsi, rsp
	;; sys_write 호출
	syscall
	jmp exit

exit:
	mov rax, SYS_EXIT
	종료 코드
	mov rdi, EXIT_CODE
	syscall

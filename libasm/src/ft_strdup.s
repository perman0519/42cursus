section.text:
	global _my_strdup
	
	extern _my_strlen
	extern _malloc
	extern _my_strcpy

_my_strdup:
	push rdi ; stack에 rd i 저장
	push rdi ; stack에 rdi 저장
	call _my_strlen ; rdi에 있는 문자열의 길이를 rax에 저장
	inc rax ; null 문자 포함할 공간 확보
	mov	 rdi, rax ; rdi에 문자열 길이 저장
	call _malloc ; rax에 동적할당된 메모리 주소 저장
	cmp rax, 0 ; 동적할당 실패 시
	jz _error ; 에러 처리
	pop rsi ; rsi에 문자열 주소 저장
	mov rdi, rax ; rdi에 동적할당된 메모리 주소 저장
	call _my_strcpy ; rsi에 있는 문자열을 rdi에 복사
	pop rax ; rax에 문자열 주소 저장
	ret

_error:
	xor    rax, rax
	ret
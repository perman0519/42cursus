section.text:
	global _my_strdup
	
	extern _my_strlen
	extern _malloc
	extern _my_strcpy

_my_strdup:
	push rbp ; Prologue
	mov rbp, rsp 
	push rdi
	call _my_strlen 
	; call이 되면 가장 먼저 하는일 push 함수 종료후 실행할 명령어의 주소
	; 그런데 c 라이브러리 함수는 기본적으로 16바이트 정렬된 스택을 가지고 실행이 된다고 전제가 됨(calling convention)
	; 그렇기 때문에, call 이전에 홀수 번의 push로 8바이트 어긋나게 해야함
	inc rax
	mov rdi, rax
	sub rsp, 8 ; 8바이트 어긋나게 하기 위해 rsp 8바이트를 예약
	call _malloc
	add rsp, 8 ; rsp를 원래대로 돌려놓음
	test rax, rax
	jz malloc_fail
	pop rsi
	mov rdi, rax
	call _my_strcpy
	pop rbp ; Epilogue
	ret 

malloc_fail:
	pop rdi
	pop rbp ; Epilogue
	ret
section .text
    global _my_strcpy

; char *stpcpy(char *restrict dst, const char *restrict src);
_my_strcpy:
	; mov rax, rdi ; rax에 dst 주소 저장
	push rbp
	mov rbp, rsp
	push rdi
	xor r8, r8 ; r8를 0으로 초기화 (인덱스)

while_cpy:
	mov al, byte[rsi + r8] ; src[r8] 값을 al에 로드
	mov byte[rdi + r8], al ; dst[r8]에 값 저장
	inc r8 ; 인덱스 증가
	cmp al, 0 ; al이 0인지 확인
	jne while_cpy ; 0이 아니면 계속 반복

	mov byte[rdi + r8], 0 ; null 문자 추가
	pop rax
	pop rbp
	ret ; 복사 완료

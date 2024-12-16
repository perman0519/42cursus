section .text
    global my_strcpy

; char *stpcpy(char *restrict dst, const char *restrict src);
my_strcpy:
	mov rax, rdi ; rax에 dst 포인터 복사
	xor r8, r8 ; r8를 0으로 초기화 (인덱스)

while_cpy:
	mov al, byte [rsi + r8] ; src[r8] 값을 al에 로드
	mov byte [rdi + r8], al ; dst[r8]에 값 저장
	inc r8 ; 인덱스 증가
	test al, al ; al이 0인지 확인
	jnz while_cpy ; 0이 아니면 계속 반복

	lea rax, [rdi + r8]     ; rax에 dst + r8 값 저장 (종료 지점 포인터)
	ret ; 복사 완료

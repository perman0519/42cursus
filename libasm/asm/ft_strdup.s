section.text:
	global _my_strdup
	extern _my_strlen
	extern _malloc
	extern _my_strcpy

_my_strdup:
	push	rdi
	push	rdi
	call	_my_strlen
	inc		rax
	mov		rdi, rax
	call	_malloc
	cmp    rax, 0
	jz		_error
	pop		rsi
	mov		rdi, rax
	call	_my_strcpy
    pop     rax
	ret

_error:
	xor    rax, rax
	ret
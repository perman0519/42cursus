section .text
    global _my_strdup
    extern _my_strlen
    extern _my_strcmp
    extern _my_strcpy
    extern _malloc

_my_strdup:
    push rbp
    mov rbp, rsp
    push r12
    push r13
    push r14
    push r15

    mov rdi, rdi
    call _my_strlen
    mov r12, rax
    mov rdi, rdi
    call _malloc
    mov r13, rax
    mov r14, rdi
    mov r15, rsi
    mov rdi, r13
    mov rsi, r15
    call _my_strcpy

    pop r15
    pop r14
    pop r13
    pop r12
    pop rbp
    ret
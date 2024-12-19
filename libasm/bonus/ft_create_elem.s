%define t_list.data  0   ; data 필드의 오프셋
%define t_list.next  8   ; next 필드의 오프셋

section .text
    extern  _malloc
    global _ft_create_elem

_ft_create_elem:
    push    rbp
    mov     rbp, rsp

    ; malloc 호출로 구조체 메모리 할당
    push    rdi
    mov     rdi, 16
    sub    rsp, 8
    call    _malloc
    add    rsp, 8
    test    rax, rax
    jz      malloc_fail

    ; rdi에는 첫 번째 매개변수(data)가 들어옴
    ; 구조체의 data 필드 초기화
    pop     rdi
    mov     [rax + t_list.data], rdi

    ; 구조체의 next 필드 초기화 (NULL로 설정)
    mov     qword [rax + t_list.next], 0

    pop     rbp
    ret

malloc_fail:
    pop     rdi
    pop     rbp
    ret

%define t_list.data  0   ; data 필드의 오프셋
%define t_list.next  8   ; next 필드의 오프셋

section .text
    extern  _malloc
    extern _ft_create_elem
    global _ft_list_push_front

; void ft_list_push_front(t_list **begin_list, void *data);
_ft_list_push_front:
    push    rbp
    mov     rbp, rsp

    ; ft_create_elem 호출로 새로운 노드 생성
    push    rdi
    mov     rdi, rsi
    sub     rsp, 8
    call    _ft_create_elem
    add     rsp, 8
    test    rax, rax
    jz      malloc_fail

    pop     rdi
    ; 새로운 노드의 next 필드에 기존 노드의 주소 저장
    ;rdi = t_list **begin_list
    ;new_elem->next = *begin_list;
    mov     rbx, [rdi]            ; rbx에 *begin_list 값을 저장
    mov     [rax + t_list.next], rbx ; new_elem->next = *begin_list
    ; begin_list에 새로운 노드 주소 저장
    mov     [rdi], rax

    pop     rbp
    ret
    
malloc_fail:
    pop     rdi
    pop     rbp
    ret
%define t_list.data  0   ; data 필드의 오프셋
%define t_list.next  8   ; next 필드의 오프셋

section .text
    global _ft_list_sort

; void ft_list_sort(t_list **begin_list, int (*cmp)());
_ft_list_sort:
    push    rbp
    mov     rbp, rsp
    push    rdi
    push    rsi
    mov     rbx, [rdi]  ; begin_list -> 첫 번째 노드
    mov     r8, rsi     ; cmp 함수 포인터

while_loop1:
    cmp     rbx, 0
    je      end_sort
    mov     rcx, [rbx + t_list.next]
    jmp     while_loop2

while_loop2:
    cmp     rcx, 0
    je      end_loop2
    mov     rdi, [rbx + t_list.data]
    mov     rsi, [rcx + t_list.data]
    push    rbx
    push    rcx
    push    r8
    sub    rsp, 8
    call    r8           ; 비교 함수 호출
    add    rsp, 8
    pop     r8
    pop     rcx
    pop     rbx
    cmp     rax, 0
    jg     _swap_data
    mov     rcx, [rcx + t_list.next]
    jmp     while_loop2

end_loop2:
    mov     rbx, [rbx + t_list.next]
    jmp     while_loop1

_swap_data:
    mov     rdx, [rbx + t_list.data]
    mov     r9, [rcx + t_list.data]
    mov     [rbx + t_list.data], r9
    mov     [rcx + t_list.data], rdx
    mov     rcx, [rcx + t_list.next]
    jmp     while_loop2

end_sort:
    pop     rsi
    pop     rdi
    pop     rbp
    ret

%define t_list.data  0   ; data 필드의 오프셋
%define t_list.next  8   ; next 필드의 오프셋

section .text
    global _ft_list_size

;ft_list_size(t_list *begin_list);
_ft_list_size:
    push    rbp
    mov     rbp, rsp
    xor     rax, rax

    ; while (begin_list)

while_size:
    cmp     rdi, 0
    je      end_size
    ; begin_list = begin_list->next
    mov     rdi, [rdi + t_list.next]
    ; size++
    inc     rax
    jmp     while_size

end_size:
    pop    rbp
    ret
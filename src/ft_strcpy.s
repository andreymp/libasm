section .text
    global ft_strcpy

    ft_strcpy:
        xor rax, rax

    _while_loop:
        mov ch, byte [rsi + rax]
        mov byte [rdi + rax], ch
        cmp ch, 0
        je  _return
        inc rax
        jmp _while_loop

    _return:
        mov rax, rdi
        ret

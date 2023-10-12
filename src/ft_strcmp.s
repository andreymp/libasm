section .text
    global ft_strcmp

    ft_strcmp:
        xor rax, rax
        xor rbx, rbx
        push r8
        mov r8, 0

    _while_loop:
        mov al, byte [rdi + r8]
        mov bl, byte [rsi + r8]
        cmp al, 0
        je _return
        cmp bl, 0
        je _return
        cmp al, bl
        jne _return
        inc r8
        jmp _while_loop


    _return:
        pop r8
        sub rax, rbx
        ret 
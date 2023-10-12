section .text
    extern malloc
    extern ft_strlen
    extern ft_strcpy

    global ft_strdup

    ft_strdup:
        push rdi
        call ft_strlen
        
        inc rax
        mov rdi, rax
        call malloc WRT ..plt
        pop rdi

        cmp rax, 0
        jg _return

        ret
    
    _return:
        mov rsi, rdi
        mov rdi, rax
        call ft_strcpy

        ret
        
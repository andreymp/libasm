section .text
    global _ft_strlen

_ft_strlen:
    mov rax, -1
    
_while_loop:
    inc rax
    cmp byte [rdi + rax], 0
    jne _while_loop
    ret 
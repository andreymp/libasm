section .text
    global _ft_strcmp

_ft_strcmp:
    xor rax, rax

_while_loop:
    inc rax
    mov ch, byte [rax + rsi]
    mov cl, byte [rax + rdi]
    cmp ch, 0
    je _return
    cmp cl, 0
    je _return

_return:
    
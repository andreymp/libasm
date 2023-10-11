extern __errno_location

section .text
    global ft_write

    ft_write:
        mov rax, 1
        syscall

        cmp rax, 0
        jl _handle_errno
        ret


    _handle_errno:
        neg rax
        mov rbx, rax
        call __errno_location WRT ..plt
        mov [rax], rbx
        mov rax, -1
        ret 
    
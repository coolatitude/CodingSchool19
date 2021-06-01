section .text
    global _ft_strlen

_ft_strlen:
    xor rax, rax
    jmp loop

increment:
    inc rax

loop:
    cmp BYTE [rdi + rax], 0
    jne increment
    jmp done

done:
    ret
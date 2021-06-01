section .text
    global _ft_strcmp

_ft_strcmp:
    xor	rcx, rcx
    xor	rdx, rdx
    cmp	rdi, 0
    jz	check_null
    cmp	rsi, 0
    jz	check_null
    jmp	check

check_null:
    cmp	rdi, rsi
    jz	equal
    jg	superior
    jmp	inferior

compare:
    mov	dl, BYTE [rsi + rcx]
    cmp	BYTE [rdi + rcx], dl
    jne	last_char

increment:
    inc	rcx

check:
    cmp	BYTE [rdi + rcx], 0
    je	last_char
    cmp	BYTE [rsi + rcx], 0
    je	last_char
    jmp	compare

last_char:
    mov	dl, BYTE [rdi + rcx]
    sub	dl, BYTE [rsi + rcx]
    cmp	dl, 0
    jz	equal
    jl	inferior

superior:
    mov	rax, 1
    ret

inferior:
    mov	rax, -1
    ret

equal:
    mov	rax, 0
    ret
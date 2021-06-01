section	.text
    global	_ft_atoi_base

_ft_atoi_base:
    push	rbx
    push	r12
    xor		rax, rax
    xor		rbx, rbx
    xor		r12, r12
    jmp		base_check_loop

base_check_increment:
    inc		r12

base_check_loop:
    cmp		BYTE [rsi + r12], 0
    jz		base_check_end
    mov		r8, r12

base_check_dup_inc:
    inc		r8

base_check_dup_loop:
    cmp		BYTE [rsi + r8], 0
    jz		base_check_correct
    mov		r9b, [rsi + r8]
    cmp		BYTE [rsi + r12], r9b
    je		set_rax
    jmp		base_check_dup_inc

base_check_correct:
    cmp		BYTE [rsi + r12], 32
    je		set_rax
    cmp		BYTE [rsi + r12], 43
    je		set_rax
    cmp		BYTE [rsi + r12], 45
    je		set_rax
    cmp		BYTE [rsi + r12], 9
    je		set_rax
    cmp		BYTE [rsi + r12], 10
    je		set_rax
    cmp		BYTE [rsi + r12], 13
    je		set_rax
    cmp		BYTE [rsi + r12], 11
    je		set_rax
    cmp		BYTE [rsi + r12], 12
    je		set_rax
    jmp		base_check_increment

base_check_end:
    cmp		r12, 1
    jle		set_rax
    xor		r8, r8
    jmp		skip_whitespaces

skip_whitespaces_inc:
    inc		r8

skip_whitespaces:
    cmp		BYTE [rdi + r8], 32
    je		skip_whitespaces_inc
    cmp		BYTE [rdi + r8], 9
    je		skip_whitespaces_inc
    cmp		BYTE [rdi + r8], 10
    je		skip_whitespaces_inc
    cmp		BYTE [rdi + r8], 13
    je		skip_whitespaces_inc
    cmp		BYTE [rdi + r8], 11
    je		skip_whitespaces_inc
    cmp		BYTE [rdi + r8], 12
    je		skip_whitespaces_inc
    jmp		check_sign

is_negative:
    xor		bl, 0x00000001

is_positive:
    inc		r8

check_sign:
    cmp		BYTE [rdi + r8], 45
    je		is_negative
    cmp		BYTE [rdi + r8], 43
    je		is_positive
    jmp		atoi_loop

atoi_increment:
    inc		r8

atoi_loop:
    cmp		BYTE [rdi + r8], 0
    je		set_rax
    xor		r9, r9
    jmp		atoi_idx

atoi_idx_inc:
    inc		r9

atoi_idx:
    mov		r10b, BYTE [rsi + r9]
    cmp		r10b, 0
    je		set_rax
    cmp		BYTE [rdi + r8], r10b
    jne		atoi_idx_inc

add_to_total:
    mul		r12
    add		rax, r9
    jmp		atoi_increment

set_rax:
    mov		rax, rax
    cmp		rbx, 0
    jz		return
    neg		rax

return:
    pop		r12
    pop		rbx
    ret
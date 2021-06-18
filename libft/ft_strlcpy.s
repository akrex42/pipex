	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.intel_syntax noprefix
	.globl	_ft_strlcpy             ## -- Begin function ft_strlcpy
	.p2align	4, 0x90
_ft_strlcpy:                            ## @ft_strlcpy
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	sub	rsp, 64
	mov	qword ptr [rbp - 16], rdi
	mov	qword ptr [rbp - 24], rsi
	mov	qword ptr [rbp - 32], rdx
	cmp	qword ptr [rbp - 24], 0
	jne	LBB0_3
## %bb.1:
	cmp	qword ptr [rbp - 16], 0
	jne	LBB0_3
## %bb.2:
	mov	qword ptr [rbp - 8], 0
	jmp	LBB0_9
LBB0_3:
	mov	rdi, qword ptr [rbp - 24]
	call	_ft_strlen
	mov	qword ptr [rbp - 40], rax
	mov	rax, qword ptr [rbp - 40]
	add	rax, 1
	cmp	rax, qword ptr [rbp - 32]
	jae	LBB0_5
## %bb.4:
	mov	rdi, qword ptr [rbp - 16]
	mov	rsi, qword ptr [rbp - 24]
	mov	rax, qword ptr [rbp - 40]
	add	rax, 1
	mov	rdx, rax
	call	_ft_memcpy
	mov	qword ptr [rbp - 48], rax ## 8-byte Spill
	jmp	LBB0_8
LBB0_5:
	cmp	qword ptr [rbp - 32], 0
	je	LBB0_7
## %bb.6:
	mov	rdi, qword ptr [rbp - 16]
	mov	rsi, qword ptr [rbp - 24]
	mov	rax, qword ptr [rbp - 32]
	sub	rax, 1
	mov	rdx, rax
	call	_ft_memcpy
	mov	rdx, qword ptr [rbp - 16]
	mov	rsi, qword ptr [rbp - 32]
	sub	rsi, 1
	mov	byte ptr [rdx + rsi], 0
	mov	qword ptr [rbp - 56], rax ## 8-byte Spill
LBB0_7:
	jmp	LBB0_8
LBB0_8:
	mov	rax, qword ptr [rbp - 40]
	mov	qword ptr [rbp - 8], rax
LBB0_9:
	mov	rax, qword ptr [rbp - 8]
	add	rsp, 64
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols

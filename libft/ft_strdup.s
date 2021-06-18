	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.intel_syntax noprefix
	.globl	_ft_strdup              ## -- Begin function ft_strdup
	.p2align	4, 0x90
_ft_strdup:                             ## @ft_strdup
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	sub	rsp, 48
	mov	qword ptr [rbp - 16], rdi
	mov	rdi, qword ptr [rbp - 16]
	mov	qword ptr [rbp - 24], rdi
	mov	rdi, qword ptr [rbp - 16]
	call	_ft_strlen
	add	rax, 1
	mov	ecx, eax
	mov	dword ptr [rbp - 36], ecx
	movsxd	rax, dword ptr [rbp - 36]
	shl	rax, 0
	mov	rdi, rax
	call	_malloc
	mov	qword ptr [rbp - 32], rax
	cmp	qword ptr [rbp - 32], 0
	jne	LBB0_2
## %bb.1:
	mov	qword ptr [rbp - 8], 0
	jmp	LBB0_5
LBB0_2:
	mov	rdi, qword ptr [rbp - 32]
	mov	rsi, qword ptr [rbp - 24]
	movsxd	rdx, dword ptr [rbp - 36]
	call	_ft_strlcpy
	cmp	qword ptr [rbp - 32], 0
	mov	qword ptr [rbp - 48], rax ## 8-byte Spill
	jne	LBB0_4
## %bb.3:
	mov	qword ptr [rbp - 8], 0
	jmp	LBB0_5
LBB0_4:
	mov	rax, qword ptr [rbp - 32]
	mov	qword ptr [rbp - 8], rax
LBB0_5:
	mov	rax, qword ptr [rbp - 8]
	add	rsp, 48
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols

	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.intel_syntax noprefix
	.globl	_ft_substr              ## -- Begin function ft_substr
	.p2align	4, 0x90
_ft_substr:                             ## @ft_substr
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	sub	rsp, 64
	mov	qword ptr [rbp - 16], rdi
	mov	dword ptr [rbp - 20], esi
	mov	qword ptr [rbp - 32], rdx
	mov	rdx, qword ptr [rbp - 16]
	mov	qword ptr [rbp - 40], rdx
	mov	rdx, qword ptr [rbp - 32]
	shl	rdx, 0
	add	rdx, 1
	mov	rdi, rdx
	call	_malloc
	mov	qword ptr [rbp - 56], rax
	mov	qword ptr [rbp - 48], 0
	cmp	qword ptr [rbp - 40], 0
	jne	LBB0_2
## %bb.1:
	mov	qword ptr [rbp - 8], 0
	jmp	LBB0_11
LBB0_2:
	cmp	qword ptr [rbp - 56], 0
	jne	LBB0_4
## %bb.3:
	mov	qword ptr [rbp - 8], 0
	jmp	LBB0_11
LBB0_4:
	jmp	LBB0_5
LBB0_5:                                 ## =>This Inner Loop Header: Depth=1
	xor	eax, eax
	mov	cl, al
	mov	rdx, qword ptr [rbp - 48]
	cmp	rdx, qword ptr [rbp - 32]
	mov	byte ptr [rbp - 57], cl ## 1-byte Spill
	jae	LBB0_8
## %bb.6:                               ##   in Loop: Header=BB0_5 Depth=1
	mov	rdi, qword ptr [rbp - 16]
	call	_ft_strlen
	xor	ecx, ecx
	mov	dl, cl
	mov	ecx, dword ptr [rbp - 20]
	mov	edi, ecx
	cmp	rax, rdi
	mov	byte ptr [rbp - 57], dl ## 1-byte Spill
	jbe	LBB0_8
## %bb.7:                               ##   in Loop: Header=BB0_5 Depth=1
	cmp	qword ptr [rbp - 40], 0
	setne	al
	mov	byte ptr [rbp - 57], al ## 1-byte Spill
LBB0_8:                                 ##   in Loop: Header=BB0_5 Depth=1
	mov	al, byte ptr [rbp - 57] ## 1-byte Reload
	test	al, 1
	jne	LBB0_9
	jmp	LBB0_10
LBB0_9:                                 ##   in Loop: Header=BB0_5 Depth=1
	mov	rax, qword ptr [rbp - 40]
	mov	ecx, dword ptr [rbp - 20]
	mov	edx, ecx
	add	rdx, qword ptr [rbp - 48]
	mov	sil, byte ptr [rax + rdx]
	mov	rax, qword ptr [rbp - 56]
	mov	rdx, qword ptr [rbp - 48]
	mov	byte ptr [rax + rdx], sil
	mov	rax, qword ptr [rbp - 48]
	add	rax, 1
	mov	qword ptr [rbp - 48], rax
	jmp	LBB0_5
LBB0_10:
	mov	rax, qword ptr [rbp - 56]
	mov	rcx, qword ptr [rbp - 48]
	mov	byte ptr [rax + rcx], 0
	mov	rax, qword ptr [rbp - 56]
	mov	qword ptr [rbp - 8], rax
LBB0_11:
	mov	rax, qword ptr [rbp - 8]
	add	rsp, 64
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols

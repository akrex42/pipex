	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.intel_syntax noprefix
	.globl	_ft_strncmp             ## -- Begin function ft_strncmp
	.p2align	4, 0x90
_ft_strncmp:                            ## @ft_strncmp
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	mov	qword ptr [rbp - 16], rdi
	mov	qword ptr [rbp - 24], rsi
	mov	qword ptr [rbp - 32], rdx
	mov	rdx, qword ptr [rbp - 16]
	mov	qword ptr [rbp - 40], rdx
	mov	rdx, qword ptr [rbp - 24]
	mov	qword ptr [rbp - 48], rdx
	mov	qword ptr [rbp - 56], 0
	cmp	qword ptr [rbp - 32], 0
	jne	LBB0_2
## %bb.1:
	mov	dword ptr [rbp - 4], 0
	jmp	LBB0_12
LBB0_2:
	jmp	LBB0_3
LBB0_3:                                 ## =>This Inner Loop Header: Depth=1
	xor	eax, eax
	mov	cl, al
	mov	rdx, qword ptr [rbp - 56]
	cmp	rdx, qword ptr [rbp - 32]
	mov	byte ptr [rbp - 57], cl ## 1-byte Spill
	jae	LBB0_7
## %bb.4:                               ##   in Loop: Header=BB0_3 Depth=1
	xor	eax, eax
	mov	cl, al
	mov	rdx, qword ptr [rbp - 40]
	mov	rsi, qword ptr [rbp - 56]
	movzx	eax, byte ptr [rdx + rsi]
	mov	rdx, qword ptr [rbp - 48]
	mov	rsi, qword ptr [rbp - 56]
	movzx	edi, byte ptr [rdx + rsi]
	cmp	eax, edi
	mov	byte ptr [rbp - 57], cl ## 1-byte Spill
	jne	LBB0_7
## %bb.5:                               ##   in Loop: Header=BB0_3 Depth=1
	xor	eax, eax
	mov	cl, al
	mov	rdx, qword ptr [rbp - 40]
	mov	rsi, qword ptr [rbp - 56]
	movzx	eax, byte ptr [rdx + rsi]
	cmp	eax, 0
	mov	byte ptr [rbp - 57], cl ## 1-byte Spill
	je	LBB0_7
## %bb.6:                               ##   in Loop: Header=BB0_3 Depth=1
	mov	rax, qword ptr [rbp - 48]
	mov	rcx, qword ptr [rbp - 56]
	movzx	edx, byte ptr [rax + rcx]
	cmp	edx, 0
	setne	sil
	mov	byte ptr [rbp - 57], sil ## 1-byte Spill
LBB0_7:                                 ##   in Loop: Header=BB0_3 Depth=1
	mov	al, byte ptr [rbp - 57] ## 1-byte Reload
	test	al, 1
	jne	LBB0_8
	jmp	LBB0_9
LBB0_8:                                 ##   in Loop: Header=BB0_3 Depth=1
	mov	rax, qword ptr [rbp - 56]
	add	rax, 1
	mov	qword ptr [rbp - 56], rax
	jmp	LBB0_3
LBB0_9:
	mov	rax, qword ptr [rbp - 56]
	cmp	rax, qword ptr [rbp - 32]
	jne	LBB0_11
## %bb.10:
	mov	rax, qword ptr [rbp - 40]
	mov	rcx, qword ptr [rbp - 56]
	sub	rcx, 1
	movzx	edx, byte ptr [rax + rcx]
	mov	rax, qword ptr [rbp - 48]
	mov	rcx, qword ptr [rbp - 56]
	sub	rcx, 1
	movzx	esi, byte ptr [rax + rcx]
	sub	edx, esi
	mov	dword ptr [rbp - 4], edx
	jmp	LBB0_12
LBB0_11:
	mov	rax, qword ptr [rbp - 40]
	mov	rcx, qword ptr [rbp - 56]
	movzx	edx, byte ptr [rax + rcx]
	mov	rax, qword ptr [rbp - 48]
	mov	rcx, qword ptr [rbp - 56]
	movzx	esi, byte ptr [rax + rcx]
	sub	edx, esi
	mov	dword ptr [rbp - 4], edx
LBB0_12:
	mov	eax, dword ptr [rbp - 4]
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols

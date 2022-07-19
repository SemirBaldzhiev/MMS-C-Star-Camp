	.file	"main.c"
	.text
	.section	.rodata
.LC2:
	.string	"%.2lf\n"
.LC3:
	.string	"%d\n"
.LC4:
	.string	"%c\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	call	randinit@PLT
	movsd	.LC0(%rip), %xmm0
	movapd	%xmm0, %xmm1
	pxor	%xmm0, %xmm0
	call	randreal@PLT
	leaq	.LC2(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	.LC0(%rip), %xmm0
	movapd	%xmm0, %xmm1
	pxor	%xmm0, %xmm0
	call	randreal@PLT
	leaq	.LC2(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movl	$0, -4(%rbp)
	jmp	.L2
.L3:
	movl	$6, %esi
	movl	$1, %edi
	call	randint@PLT
	movl	%eax, %esi
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$122, %esi
	movl	$97, %edi
	call	randint@PLT
	movl	%eax, %esi
	leaq	.LC4(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movsd	.LC5(%rip), %xmm0
	movq	.LC6(%rip), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, -24(%rbp)
	movsd	-24(%rbp), %xmm0
	call	randreal@PLT
	leaq	.LC2(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	addl	$1, -4(%rbp)
.L2:
	cmpl	$4, -4(%rbp)
	jle	.L3
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC0:
	.long	0
	.long	1072693248
	.align 8
.LC5:
	.long	858993459
	.long	1075131187
	.align 8
.LC6:
	.long	3435973837
	.long	1073007820
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits

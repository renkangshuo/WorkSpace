	.file	"test.c"
	.text
	.globl	test
	.type	test, @function
test:
.LFB0:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	8(%esp), %edx
	movl	12(%esp), %ecx
	cmpl	$-3, %edx
	jge	.L2
	leal	(%edx,%ecx), %eax
	movl	%edx, %ebx
	imull	%ecx, %ebx
	cmpl	%ecx, %edx
	cmovg	%ebx, %eax
	jmp	.L4
.L2:
	movl	%ecx, %eax
	xorl	%edx, %eax
	movl	%edx, %ebx
	subl	%ecx, %ebx
	cmpl	$2, %edx
	cmovg	%ebx, %eax
.L4:
	popl	%ebx
	.cfi_def_cfa_offset 4
	.cfi_restore 3
	ret
	.cfi_endproc
.LFE0:
	.size	test, .-test
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits

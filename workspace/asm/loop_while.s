	.file	"loop_while.c"
	.text
	.globl	loop_while
	.type	loop_while, @function
loop_while:
.LFB0:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	8(%esp), %edx
	movl	12(%esp), %ecx
	movl	$1, %eax
	cmpl	%ecx, %edx
	jge	.L2
.L3:
	leal	(%edx,%ecx), %ebx
	imull	%ebx, %eax
	addl	$1, %edx
	cmpl	%edx, %ecx
	jg	.L3
.L2:
	popl	%ebx
	.cfi_def_cfa_offset 4
	.cfi_restore 3
	ret
	.cfi_endproc
.LFE0:
	.size	loop_while, .-loop_while
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits

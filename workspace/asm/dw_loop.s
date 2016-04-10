	.file	"dw_loop.c"
	.text
	.globl	dw_loop
	.type	dw_loop, @function
dw_loop:
.LFB0:
	.cfi_startproc
	movl	4(%esp), %eax
	movl	8(%esp), %ecx
	movl	12(%esp), %edx
.L2:
	addl	%edx, %eax
	imull	%edx, %ecx
	subl	$1, %edx
	testl	%edx, %edx
	jle	.L4
	cmpl	%edx, %ecx
	jl	.L2
.L4:
	rep
	ret
	.cfi_endproc
.LFE0:
	.size	dw_loop, .-dw_loop
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits

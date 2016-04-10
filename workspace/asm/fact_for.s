	.file	"fact_for.c"
	.text
	.globl	fact_for
	.type	fact_for, @function
fact_for:
.LFB0:
	.cfi_startproc
	movl	4(%esp), %ecx
	movl	$1, %eax
	cmpl	$1, %ecx
	jle	.L2
	movl	$2, %edx
.L3:
	imull	%edx, %eax
	addl	$1, %edx
	cmpl	%edx, %ecx
	jge	.L3
.L2:
	rep
	ret
	.cfi_endproc
.LFE0:
	.size	fact_for, .-fact_for
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits

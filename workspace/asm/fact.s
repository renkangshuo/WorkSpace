	.file	"fact.c"
	.text
	.globl	fact_do
	.type	fact_do, @function
fact_do:
.LFB0:
	.cfi_startproc
	movl	4(%esp), %edx
	movl	$1, %eax
.L2:
	imull	%edx, %eax
	subl	$1, %edx
	cmpl	$1, %edx
	jg	.L2
	rep
	ret
	.cfi_endproc
.LFE0:
	.size	fact_do, .-fact_do
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits

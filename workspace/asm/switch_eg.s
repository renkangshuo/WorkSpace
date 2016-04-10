	.file	"switch_eg.c"
	.text
	.globl	switch_eg
	.type	switch_eg, @function
switch_eg:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	8(%ebp), %eax
	movl	%eax, -4(%ebp)
	movl	12(%ebp), %eax
	subl	$100, %eax
	cmpl	$6, %eax
	ja	.L2
	movl	.L7(,%eax,4), %eax
	jmp	*%eax
	.section	.rodata
	.align 4
	.align 4
.L7:
	.long	.L3
	.long	.L2
	.long	.L4
	.long	.L5
	.long	.L6
	.long	.L2
	.long	.L6
	.text
.L3:
	movl	-4(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	movl	%eax, -4(%ebp)
	jmp	.L8
.L4:
	addl	$10, -4(%ebp)
.L5:
	addl	$11, -4(%ebp)
	jmp	.L8
.L6:
	movl	-4(%ebp), %eax
	imull	-4(%ebp), %eax
	movl	%eax, -4(%ebp)
	jmp	.L8
.L2:
	movl	$0, -4(%ebp)
.L8:
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	switch_eg, .-switch_eg
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits

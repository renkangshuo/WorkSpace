	.file	"globe.c"
	.globl	globe_1
	.data
	.align 4
	.type	globe_1, @object
	.size	globe_1, 4
globe_1:
	.long	1
	.globl	globe_2
	.align 4
	.type	globe_2, @object
	.size	globe_2, 4
globe_2:
	.long	2
	.globl	globe_3
	.align 4
	.type	globe_3, @object
	.size	globe_3, 4
globe_3:
	.long	3
	.text
	.globl	globe
	.type	globe, @function
globe:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	$9, -8(%ebp)
	movl	$10, -4(%ebp)
	movl	globe_1, %eax
	addl	%eax, -8(%ebp)
	movl	globe_2, %eax
	movl	%eax, %edx
	addl	-4(%ebp), %edx
	movl	globe_3, %eax
	addl	%edx, %eax
	movl	%eax, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	-8(%ebp), %edx
	addl	%edx, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	globe, .-globe
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits

	.file	"test_char.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"to"
.LC1:
	.string	"nanjing"
	.text
	.globl	main
	.type	main, @function
main:
.LFB22:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$16, %esp
	movl	$.LC0+2, (%esp)
	call	puts
	movl	$.LC1, (%esp)
	call	puts
	movl	$.LC1+3, (%esp)
	call	puts
	movl	$.LC1+6, (%esp)
	call	puts
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE22:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits

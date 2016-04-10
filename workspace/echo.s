	.file	"echo.c"
	.text
	.globl	gets
	.type	gets, @function
gets:
.LFB0:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	16(%esp), %edi
	movl	%edi, %ebx
	movl	$0, %esi
	jmp	.L2
.L4:
	movb	%al, (%ebx)
	addl	$1, %ebx
	movl	$1, %esi
.L2:
	call	getchar
	cmpl	$10, %eax
	je	.L3
	cmpl	$-1, %eax
	jne	.L4
	movb	$0, (%ebx)
	.p2align 4,,2
	jne	.L5
	testl	%esi, %esi
	sete	%al
	testb	%al, %al
	movl	$0, %eax
	cmovne	%eax, %edi
.L5:
	movl	%edi, %eax
	popl	%ebx
	.cfi_remember_state
	.cfi_def_cfa_offset 12
	.cfi_restore 3
	popl	%esi
	.cfi_def_cfa_offset 8
	.cfi_restore 6
	popl	%edi
	.cfi_def_cfa_offset 4
	.cfi_restore 7
	ret
.L3:
	.cfi_restore_state
	movb	$0, (%ebx)
	jmp	.L5
	.cfi_endproc
.LFE0:
	.size	gets, .-gets
	.globl	echo
	.type	echo, @function
echo:
.LFB1:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	subl	$40, %esp
	.cfi_def_cfa_offset 48
	movl	%gs:20, %eax
	movl	%eax, 28(%esp)
	xorl	%eax, %eax
	leal	20(%esp), %ebx
	movl	%ebx, (%esp)
	call	gets
	movl	%ebx, (%esp)
	call	puts
	movl	28(%esp), %eax
	xorl	%gs:20, %eax
	je	.L9
	call	__stack_chk_fail
.L9:
	addl	$40, %esp
	.cfi_def_cfa_offset 8
	popl	%ebx
	.cfi_def_cfa_offset 4
	.cfi_restore 3
	.p2align 4,,2
	ret
	.cfi_endproc
.LFE1:
	.size	echo, .-echo
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits

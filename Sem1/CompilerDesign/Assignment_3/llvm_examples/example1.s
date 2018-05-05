	.text
	.file	"example1.bc"
	.globl	foo
	.align	16, 0x90
	.type	foo,@function
foo:                                    # @foo
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Ltmp0:
	.cfi_def_cfa_offset 16
.Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp2:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	$0, -8(%rbp)
	jmp	.LBB0_1
	.align	16, 0x90
.LBB0_2:                                #   in Loop: Header=BB0_1 Depth=1
	movl	$.L.str, %edi
	xorl	%eax, %eax
	callq	printf
	incl	-8(%rbp)
.LBB0_1:                                # =>This Inner Loop Header: Depth=1
	movl	-8(%rbp), %eax
	cmpl	-4(%rbp), %eax
	jb	.LBB0_2
# BB#3:
	addq	$16, %rsp
	popq	%rbp
	retq
.Lfunc_end0:
	.size	foo, .Lfunc_end0-foo
	.cfi_endproc

	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Ltmp3:
	.cfi_def_cfa_offset 16
.Ltmp4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp5:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	-8(%rbp), %edi
	callq	foo
	xorl	%eax, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"Hello\n"
	.size	.L.str, 7


	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits

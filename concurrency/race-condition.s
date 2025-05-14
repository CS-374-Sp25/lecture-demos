	.file	"race-condition.c"
	.text
.Ltext0:
	.globl	start_routine
	.type	start_routine, @function
start_routine:
.LFB2:
	.file 1 "race-condition.c"
	.loc 1 10 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	.loc 1 11 0
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	.loc 1 15 0
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	testq	%rax, %rax
	js	.L2
	cvtsi2sdq	%rax, %xmm0
	jmp	.L3
.L2:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
.L3:
	movsd	.LC0(%rip), %xmm1
	mulsd	%xmm0, %xmm1
	.loc 1 16 0
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	.loc 1 15 0
	testq	%rax, %rax
	js	.L4
	cvtsi2sdq	%rax, %xmm0
	jmp	.L5
.L4:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
.L5:
	mulsd	%xmm0, %xmm1
	.loc 1 16 0
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	testq	%rax, %rax
	js	.L6
	cvtsi2sdq	%rax, %xmm0
	jmp	.L7
.L6:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
.L7:
	.loc 1 15 0
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, -16(%rbp)
	.loc 1 17 0
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rdx
	movq	(%rdx), %rdx
	movsd	(%rdx), %xmm0
	addsd	-16(%rbp), %xmm0
	movsd	%xmm0, (%rax)
	.loc 1 19 0
	movl	$0, %eax
	.loc 1 20 0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	start_routine, .-start_routine
	.section	.rodata
.LC2:
	.string	"The sum of volumes is %lf\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB3:
	.loc 1 22 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$2448, %rsp
	.loc 1 23 0
	movl	$0, %eax
	movq	%rax, -16(%rbp)
	.loc 1 28 0
	movl	$0, -4(%rbp)
	jmp	.L10
.L11:
	.loc 1 29 0 discriminator 2
	movl	-4(%rbp), %eax
	cltq
	salq	$4, %rax
	addq	%rbp, %rax
	leaq	-2416(%rax), %rdx
	leaq	-16(%rbp), %rax
	movq	%rax, (%rdx)
	.loc 1 30 0 discriminator 2
	movl	-4(%rbp), %eax
	cltq
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	salq	$4, %rdx
	addq	%rbp, %rdx
	subq	$2408, %rdx
	movq	%rax, (%rdx)
	.loc 1 31 0 discriminator 2
	leaq	-2416(%rbp), %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	salq	$4, %rdx
	addq	%rax, %rdx
	leaq	-816(%rbp), %rax
	movl	-4(%rbp), %ecx
	movslq	%ecx, %rcx
	salq	$3, %rcx
	addq	%rcx, %rax
	movq	%rdx, %rcx
	movl	$start_routine, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	pthread_create
	.loc 1 28 0 discriminator 2
	addl	$1, -4(%rbp)
.L10:
	.loc 1 28 0 is_stmt 0 discriminator 1
	cmpl	$99, -4(%rbp)
	jle	.L11
	.loc 1 36 0 is_stmt 1
	movl	$0, -4(%rbp)
	jmp	.L12
.L13:
	.loc 1 37 0 discriminator 2
	movl	-4(%rbp), %eax
	cltq
	movq	-816(%rbp,%rax,8), %rax
	leaq	-2424(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	pthread_join
	.loc 1 36 0 discriminator 2
	addl	$1, -4(%rbp)
.L12:
	.loc 1 36 0 is_stmt 0 discriminator 1
	cmpl	$99, -4(%rbp)
	jle	.L13
	.loc 1 42 0 is_stmt 1
	movq	-16(%rbp), %rax
	movq	%rax, -2440(%rbp)
	movsd	-2440(%rbp), %xmm0
	movl	$.LC2, %edi
	movl	$1, %eax
	call	printf
	.loc 1 43 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC0:
	.long	4256301137
	.long	1074839889
	.text
.Letext0:
	.file 2 "/usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h"
	.file 3 "/usr/include/bits/pthreadtypes.h"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x19f
	.value	0x4
	.long	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.long	.LASF21
	.byte	0x1
	.long	.LASF22
	.long	.LASF23
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.long	.Ldebug_line0
	.uleb128 0x2
	.long	.LASF9
	.byte	0x2
	.byte	0xd4
	.long	0x38
	.uleb128 0x3
	.byte	0x8
	.byte	0x7
	.long	.LASF0
	.uleb128 0x3
	.byte	0x1
	.byte	0x8
	.long	.LASF1
	.uleb128 0x3
	.byte	0x2
	.byte	0x7
	.long	.LASF2
	.uleb128 0x3
	.byte	0x4
	.byte	0x7
	.long	.LASF3
	.uleb128 0x3
	.byte	0x1
	.byte	0x6
	.long	.LASF4
	.uleb128 0x3
	.byte	0x2
	.byte	0x5
	.long	.LASF5
	.uleb128 0x4
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x3
	.byte	0x8
	.byte	0x5
	.long	.LASF6
	.uleb128 0x3
	.byte	0x8
	.byte	0x7
	.long	.LASF7
	.uleb128 0x5
	.byte	0x8
	.uleb128 0x3
	.byte	0x1
	.byte	0x6
	.long	.LASF8
	.uleb128 0x2
	.long	.LASF10
	.byte	0x3
	.byte	0x3c
	.long	0x38
	.uleb128 0x3
	.byte	0x8
	.byte	0x7
	.long	.LASF11
	.uleb128 0x3
	.byte	0x8
	.byte	0x5
	.long	.LASF12
	.uleb128 0x6
	.long	.LASF24
	.byte	0x10
	.byte	0x1
	.byte	0x5
	.long	0xbe
	.uleb128 0x7
	.long	.LASF13
	.byte	0x1
	.byte	0x6
	.long	0xbe
	.byte	0
	.uleb128 0x7
	.long	.LASF14
	.byte	0x1
	.byte	0x7
	.long	0x2d
	.byte	0x8
	.byte	0
	.uleb128 0x8
	.byte	0x8
	.long	0xc4
	.uleb128 0x3
	.byte	0x8
	.byte	0x4
	.long	.LASF15
	.uleb128 0x9
	.long	.LASF25
	.byte	0x1
	.byte	0xa
	.long	0x77
	.quad	.LFB2
	.quad	.LFE2-.LFB2
	.uleb128 0x1
	.byte	0x9c
	.long	0x117
	.uleb128 0xa
	.string	"arg"
	.byte	0x1
	.byte	0xa
	.long	0x77
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0xb
	.long	.LASF16
	.byte	0x1
	.byte	0xb
	.long	0x117
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0xb
	.long	.LASF17
	.byte	0x1
	.byte	0xf
	.long	0xc4
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.byte	0
	.uleb128 0x8
	.byte	0x8
	.long	0x99
	.uleb128 0xc
	.long	.LASF26
	.byte	0x1
	.byte	0x16
	.long	0x62
	.quad	.LFB3
	.quad	.LFE3-.LFB3
	.uleb128 0x1
	.byte	0x9c
	.long	0x186
	.uleb128 0xb
	.long	.LASF13
	.byte	0x1
	.byte	0x17
	.long	0xc4
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0xb
	.long	.LASF18
	.byte	0x1
	.byte	0x19
	.long	0x186
	.uleb128 0x3
	.byte	0x91
	.sleb128 -832
	.uleb128 0xb
	.long	.LASF19
	.byte	0x1
	.byte	0x1a
	.long	0x196
	.uleb128 0x3
	.byte	0x91
	.sleb128 -2432
	.uleb128 0xd
	.string	"i"
	.byte	0x1
	.byte	0x1b
	.long	0x62
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0xb
	.long	.LASF20
	.byte	0x1
	.byte	0x23
	.long	0x77
	.uleb128 0x3
	.byte	0x91
	.sleb128 -2440
	.byte	0
	.uleb128 0xe
	.long	0x80
	.long	0x196
	.uleb128 0xf
	.long	0x70
	.byte	0x63
	.byte	0
	.uleb128 0x10
	.long	0x99
	.uleb128 0xf
	.long	0x70
	.byte	0x63
	.byte	0
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",@progbits
	.long	0x2c
	.value	0x2
	.long	.Ldebug_info0
	.byte	0x8
	.byte	0
	.value	0
	.value	0
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.quad	0
	.quad	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF12:
	.string	"long long int"
.LASF17:
	.string	"volume"
.LASF9:
	.string	"size_t"
.LASF18:
	.string	"new_threads"
.LASF13:
	.string	"volume_sum"
.LASF26:
	.string	"main"
.LASF24:
	.string	"thread_arg_t"
.LASF14:
	.string	"index"
.LASF0:
	.string	"long unsigned int"
.LASF11:
	.string	"long long unsigned int"
.LASF19:
	.string	"thread_args"
.LASF25:
	.string	"start_routine"
.LASF1:
	.string	"unsigned char"
.LASF8:
	.string	"char"
.LASF6:
	.string	"long int"
.LASF16:
	.string	"casted_arg"
.LASF5:
	.string	"short int"
.LASF15:
	.string	"double"
.LASF2:
	.string	"short unsigned int"
.LASF4:
	.string	"signed char"
.LASF10:
	.string	"pthread_t"
.LASF20:
	.string	"my_variable"
.LASF23:
	.string	"/nfs/stak/users/guyera/instructor/sp25/cs374/lecture-demos/concurrency"
.LASF3:
	.string	"unsigned int"
.LASF7:
	.string	"sizetype"
.LASF21:
	.string	"GNU C 4.8.5 20150623 (Red Hat 4.8.5-44) -mtune=generic -march=x86-64 -g"
.LASF22:
	.string	"race-condition.c"
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-44)"
	.section	.note.GNU-stack,"",@progbits

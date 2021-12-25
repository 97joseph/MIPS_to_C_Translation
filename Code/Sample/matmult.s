	.file	1 "matmult.c"

 # GNU C 2.6.3 [AL 1.1, MM 40, tma 0.1] SimpleScalar running sstrix compiled by GNU C

 # Cc1 defaults:
 # -mgas -mgpOPT

 # Cc1 arguments (-G value = 8, Cpu = default, ISA = 1):
 # -quiet -dumpbase -o

gcc2_compiled.:
__gnu_compiled_c:
	.globl	a
	.data
	.align	2
a:
	.word	2
	.word	12983
	.word	-2112104
	.word	-33215
	.word	1
	.word	2121212
	.word	3
	.word	4
	.word	0
	.word	-11
	.word	2
	.word	121433
	.word	1
	.word	-9861
	.word	17901
	.word	-1
	.globl	b
	.align	2
b:
	.word	19562
	.word	243053
	.word	4
	.word	9423235
	.word	1
	.word	1212
	.word	1243
	.word	23124
	.word	0
	.word	-21211
	.word	2
	.word	-3233
	.word	-86756601
	.word	2121
	.word	3231
	.word	-2311
	.text
	.align	2
	.globl	_start

	.comm	c,64

	.text

	.loc	1 14
	.ent	_start
_start:
	.frame	$fp,24,$31		# vars= 16, regs= 1/0, args= 0, extra= 0
	.mask	0x40000000,-8
	.fmask	0x00000000,0
	subu	$sp,$sp,24
	sw	$fp,16($sp)
	move	$fp,$sp
	.set	noreorder
	nop
	.set	reorder
	sw	$0,0($fp)
$L2:
	lw	$2,0($fp)
	slt	$3,$2,4
	bne	$3,$0,$L5
	j	$L3
$L5:
	.set	noreorder
	nop
	.set	reorder
	sw	$0,4($fp)
$L6:
	lw	$2,4($fp)
	slt	$3,$2,4
	bne	$3,$0,$L9
	j	$L7
$L9:
	sw	$0,12($fp)
	sw	$0,8($fp)
$L10:
	lw	$2,8($fp)
	slt	$3,$2,4
	bne	$3,$0,$L13
	j	$L11
$L13:
	lw	$2,0($fp)
	move	$3,$2
	sll	$2,$3,4
	la	$4,a
	addu	$3,$2,$4
	move	$2,$3
	lw	$3,8($fp)
	move	$4,$3
	sll	$3,$4,2
	addu	$4,$3,$2
	move	$2,$4
	lw	$3,8($fp)
	move	$4,$3
	sll	$3,$4,4
	la	$5,b
	addu	$4,$3,$5
	move	$3,$4
	lw	$4,4($fp)
	move	$5,$4
	sll	$4,$5,2
	addu	$3,$4,$3
	move	$4,$3
	lw	$2,0($2)
	lw	$3,0($4)
	mult	$2,$3
	mflo	$2
	lw	$3,12($fp)
	addu	$2,$3,$2
	sw	$2,12($fp)
$L12:
	lw	$3,8($fp)
	addu	$2,$3,1
	move	$3,$2
	sw	$3,8($fp)
	j	$L10
$L11:
	lw	$2,0($fp)
	move	$3,$2
	sll	$2,$3,4
	la	$4,c
	addu	$3,$2,$4
	move	$2,$3
	lw	$3,4($fp)
	move	$4,$3
	sll	$3,$4,2
	addu	$2,$3,$2
	move	$3,$2
	lw	$2,12($fp)
	sw	$2,0($3)
$L8:
	lw	$3,4($fp)
	addu	$2,$3,1
	move	$3,$2
	sw	$3,4($fp)
	j	$L6
$L7:
$L4:
	lw	$3,0($fp)
	addu	$2,$3,1
	move	$3,$2
	sw	$3,0($fp)
	j	$L2
$L3:
$L1:
	move	$sp,$fp			# sp not trusted here
	lw	$fp,16($sp)
	addu	$sp,$sp,24
	j	$31
	.end	_start

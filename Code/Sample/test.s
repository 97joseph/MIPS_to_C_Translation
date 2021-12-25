	.file	1 "test.c"

 # GNU C 2.6.3 [AL 1.1, MM 40, tma 0.1] SimpleScalar running sstrix compiled by GNU C

 # Cc1 defaults:
 # -mgas -mgpOPT

 # Cc1 arguments (-G value = 8, Cpu = default, ISA = 1):
 # -quiet -dumpbase -o

gcc2_compiled.:
__gnu_compiled_c:
	.text
	.align	2
	.globl	_start

	.comm	i,4

	.comm	p,4

	.text

	.loc	1 4
	.ent	_start
_start:
	.frame	$fp,8,$31		# vars= 0, regs= 1/0, args= 0, extra= 0
	.mask	0x40000000,-8
	.fmask	0x00000000,0
	subu	$sp,$sp,8
	sw	$fp,0($sp)
	move	$fp,$sp
	li	$2,0x00000001		# 1
	sw	$2,p
	sw	$0,i
$L2:
	lw	$2,i
	slt	$3,$2,10
	bne	$3,$0,$L5
	j	$L3
$L5:
	lw	$2,p
	move	$3,$2
	sll	$2,$3,1
	sw	$2,p
$L4:
	lw	$3,i
	addu	$2,$3,1
	move	$3,$2
	sw	$3,i
	j	$L2
$L3:
$L1:
	move	$sp,$fp			# sp not trusted here
	lw	$fp,0($sp)
	addu	$sp,$sp,8
	j	$31
	.end	_start

	.file	1 "hanoi.c"

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
	.align	2
	.globl	mov

	.comm	num,16

	.comm	count,4

	.text

	.loc	1 60
	.ent	_start
_start:
	.frame	$fp,32,$31		# vars= 0, regs= 4/0, args= 16, extra= 0
	.mask	0xc0030000,-4
	.fmask	0x00000000,0
	subu	$sp,$sp,32
	sw	$31,28($sp)
	sw	$fp,24($sp)
	sw	$17,20($sp)
	sw	$16,16($sp)
	move	$fp,$sp
	move	$17,$0
	li	$16,0x00000001		# 1
$L2:
	j	$L4
	j	$L3
$L4:
	addu	$16,$16,1
	sw	$0,num
	sw	$16,num+4
	sw	$0,num+8
	sw	$0,num+12
	sw	$0,count
	move	$4,$16
	li	$5,0x00000001		# 1
	li	$6,0x00000003		# 3
	jal	mov
	addu	$17,$17,1
	li	$2,0x0000000a		# 10
	bne	$16,$2,$L5
	j	$L3
$L5:
	j	$L2
$L3:
$L1:
	move	$sp,$fp			# sp not trusted here
	lw	$31,28($sp)
	lw	$fp,24($sp)
	lw	$17,20($sp)
	lw	$16,16($sp)
	addu	$sp,$sp,32
	j	$31
	.end	_start

	.loc	1 86
	.ent	mov
mov:
	.frame	$fp,32,$31		# vars= 0, regs= 3/0, args= 16, extra= 0
	.mask	0xc0010000,-8
	.fmask	0x00000000,0
	subu	$sp,$sp,32
	sw	$31,24($sp)
	sw	$fp,20($sp)
	sw	$16,16($sp)
	move	$fp,$sp
	sw	$4,32($fp)
	sw	$5,36($fp)
	sw	$6,40($fp)
	lw	$2,32($fp)
	li	$3,0x00000001		# 1
	bne	$2,$3,$L7
	lw	$2,36($fp)
	move	$3,$2
	sll	$2,$3,2
	la	$4,num
	addu	$3,$2,$4
	move	$2,$3
	lw	$3,36($fp)
	move	$2,$3
	sll	$3,$2,2
	la	$2,num
	addu	$3,$3,$2
	move	$2,$3
	lw	$3,36($fp)
	move	$4,$3
	sll	$3,$4,2
	la	$4,num
	addu	$3,$3,$4
	move	$4,$3
	lw	$5,0($4)
	subu	$3,$5,1
	move	$4,$3
	sw	$4,0($2)
	lw	$2,40($fp)
	move	$3,$2
	sll	$2,$3,2
	la	$4,num
	addu	$3,$2,$4
	move	$2,$3
	lw	$3,40($fp)
	move	$2,$3
	sll	$3,$2,2
	la	$2,num
	addu	$3,$3,$2
	move	$2,$3
	lw	$3,40($fp)
	move	$4,$3
	sll	$3,$4,2
	la	$4,num
	addu	$3,$3,$4
	move	$4,$3
	lw	$5,0($4)
	addu	$3,$5,1
	move	$4,$3
	sw	$4,0($2)
	lw	$3,count
	addu	$2,$3,1
	move	$3,$2
	sw	$3,count
	j	$L6
$L7:
	lw	$2,36($fp)
	lw	$3,40($fp)
	addu	$2,$2,$3
	li	$3,0x00000006		# 6
	subu	$16,$3,$2
	lw	$3,32($fp)
	subu	$2,$3,1
	move	$4,$2
	lw	$5,36($fp)
	move	$6,$16
	jal	mov
	li	$4,0x00000001		# 1
	lw	$5,36($fp)
	lw	$6,40($fp)
	jal	mov
	lw	$3,32($fp)
	subu	$2,$3,1
	move	$4,$2
	move	$5,$16
	lw	$6,40($fp)
	jal	mov
	j	$L6
$L6:
	move	$sp,$fp			# sp not trusted here
	lw	$31,24($sp)
	lw	$fp,20($sp)
	lw	$16,16($sp)
	addu	$sp,$sp,32
	j	$31
	.end	mov

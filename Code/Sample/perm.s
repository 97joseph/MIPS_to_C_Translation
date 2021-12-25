	.file	1 "perm.c"

 # GNU C 2.6.3 [AL 1.1, MM 40, tma 0.1] SimpleScalar running sstrix compiled by GNU C

 # Cc1 defaults:
 # -mgas -mgpOPT

 # Cc1 arguments (-G value = 8, Cpu = default, ISA = 1):
 # -quiet -dumpbase -o

gcc2_compiled.:
__gnu_compiled_c:
	.text
	.align	2
	.globl	Swap
	.align	2
	.globl	Initialize
	.align	2
	.globl	Permute
	.align	2
	.globl	Perm
	.align	2
	.globl	_start

	.comm	permarray,28

	.comm	pctr,4

	.text

	.loc	1 8
	.ent	Swap
Swap:
	.frame	$fp,16,$31		# vars= 8, regs= 1/0, args= 0, extra= 0
	.mask	0x40000000,-8
	.fmask	0x00000000,0
	subu	$sp,$sp,16
	sw	$fp,8($sp)
	move	$fp,$sp
	sw	$4,16($fp)
	sw	$5,20($fp)
	lw	$2,16($fp)
	lw	$3,0($2)
	sw	$3,0($fp)
	lw	$2,16($fp)
	lw	$3,20($fp)
	lw	$4,0($3)
	sw	$4,0($2)
	lw	$2,20($fp)
	lw	$3,0($fp)
	sw	$3,0($2)
$L1:
	move	$sp,$fp			# sp not trusted here
	lw	$fp,8($sp)
	addu	$sp,$sp,16
	j	$31
	.end	Swap

	.loc	1 15
	.ent	Initialize
Initialize:
	.frame	$fp,16,$31		# vars= 8, regs= 1/0, args= 0, extra= 0
	.mask	0x40000000,-8
	.fmask	0x00000000,0
	subu	$sp,$sp,16
	sw	$fp,8($sp)
	move	$fp,$sp
	.set	noreorder
	nop
	.set	reorder
	li	$2,0x00000001		# 1
	sw	$2,0($fp)
$L3:
	lw	$2,0($fp)
	slt	$3,$2,8
	bne	$3,$0,$L6
	j	$L4
$L6:
	lw	$2,0($fp)
	move	$3,$2
	sll	$2,$3,2
	la	$4,permarray
	addu	$3,$2,$4
	move	$2,$3
	lw	$3,0($fp)
	subu	$4,$3,1
	sw	$4,0($2)
$L5:
	lw	$3,0($fp)
	addu	$2,$3,1
	move	$3,$2
	sw	$3,0($fp)
	j	$L3
$L4:
$L2:
	move	$sp,$fp			# sp not trusted here
	lw	$fp,8($sp)
	addu	$sp,$sp,16
	j	$31
	.end	Initialize

	.loc	1 23
	.ent	Permute
Permute:
	.frame	$fp,32,$31		# vars= 8, regs= 2/0, args= 16, extra= 0
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	subu	$sp,$sp,32
	sw	$31,28($sp)
	sw	$fp,24($sp)
	move	$fp,$sp
	sw	$4,32($fp)
	lw	$2,pctr
	addu	$3,$2,1
	sw	$3,pctr
	lw	$2,32($fp)
	li	$3,0x00000001		# 1
	beq	$2,$3,$L8
	lw	$3,32($fp)
	subu	$2,$3,1
	move	$4,$2
	jal	Permute
	lw	$2,32($fp)
	subu	$3,$2,1
	sw	$3,16($fp)
$L9:
	lw	$2,16($fp)
	bgtz	$2,$L12
	j	$L10
$L12:
	lw	$2,32($fp)
	move	$3,$2
	sll	$2,$3,2
	la	$3,permarray
	addu	$2,$2,$3
	lw	$3,16($fp)
	move	$4,$3
	sll	$3,$4,2
	la	$4,permarray
	addu	$3,$3,$4
	move	$4,$2
	move	$5,$3
	jal	Swap
	lw	$3,32($fp)
	subu	$2,$3,1
	move	$4,$2
	jal	Permute
	lw	$2,32($fp)
	move	$3,$2
	sll	$2,$3,2
	la	$3,permarray
	addu	$2,$2,$3
	lw	$3,16($fp)
	move	$4,$3
	sll	$3,$4,2
	la	$4,permarray
	addu	$3,$3,$4
	move	$4,$2
	move	$5,$3
	jal	Swap
$L11:
	lw	$3,16($fp)
	subu	$2,$3,1
	move	$3,$2
	sw	$3,16($fp)
	j	$L9
$L10:
$L8:
$L7:
	move	$sp,$fp			# sp not trusted here
	lw	$31,28($sp)
	lw	$fp,24($sp)
	addu	$sp,$sp,32
	j	$31
	.end	Permute

	.loc	1 37
	.ent	Perm
Perm:
	.frame	$fp,32,$31		# vars= 8, regs= 2/0, args= 16, extra= 0
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	subu	$sp,$sp,32
	sw	$31,28($sp)
	sw	$fp,24($sp)
	move	$fp,$sp
	sw	$0,pctr
	jal	Initialize
	li	$4,0x00000007		# 7
	jal	Permute
$L13:
	move	$sp,$fp			# sp not trusted here
	lw	$31,28($sp)
	lw	$fp,24($sp)
	addu	$sp,$sp,32
	j	$31
	.end	Perm

	.loc	1 45
	.ent	_start
_start:
	.frame	$fp,24,$31		# vars= 0, regs= 2/0, args= 16, extra= 0
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	subu	$sp,$sp,24
	sw	$31,20($sp)
	sw	$fp,16($sp)
	move	$fp,$sp
	jal	Perm
$L14:
	move	$sp,$fp			# sp not trusted here
	lw	$31,20($sp)
	lw	$fp,16($sp)
	addu	$sp,$sp,24
	j	$31
	.end	_start

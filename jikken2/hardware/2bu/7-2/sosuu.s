	.file	1 "sosuu.c"
	.section .mdebug.abi32
	.previous
	.text
	.align	2
	.globl	main
	.ent	main
main:
	.frame	$fp,160,$31		# vars= 136, regs= 2/0, args= 16, gp= 0
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	
	addiu	$sp,$sp,-160
	sw	$31,156($sp)
	sw	$fp,152($sp)
	move	$fp,$sp
	li	$2,72			# 0x48
	sw	$2,24($fp)
	li	$2,69			# 0x45
	sw	$2,28($fp)
	li	$2,76			# 0x4c
	sw	$2,32($fp)
	li	$2,76			# 0x4c
	sw	$2,36($fp)
	li	$2,79			# 0x4f
	sw	$2,40($fp)
	li	$2,10			# 0xa
	sw	$2,44($fp)
	sw	$0,48($fp)
	addiu	$2,$fp,24
	move	$4,$2
	jal	my_print
	nop

$L2:
	li	$2,78			# 0x4e
	sw	$2,24($fp)
	li	$2,85			# 0x55
	sw	$2,28($fp)
	li	$2,77			# 0x4d
	sw	$2,32($fp)
	li	$2,61			# 0x3d
	sw	$2,36($fp)
	sw	$0,40($fp)
	addiu	$2,$fp,24
	move	$4,$2
	jal	my_print
	nop

	addiu	$2,$fp,88
	move	$4,$2
	jal	my_scan
	nop

	li	$2,69			# 0x45
	sw	$2,24($fp)
	li	$2,67			# 0x43
	sw	$2,28($fp)
	li	$2,72			# 0x48
	sw	$2,32($fp)
	li	$2,79			# 0x4f
	sw	$2,36($fp)
	li	$2,32			# 0x20
	sw	$2,40($fp)
	sw	$0,44($fp)
	addiu	$2,$fp,24
	move	$4,$2
	jal	my_print
	nop

	addiu	$2,$fp,88
	move	$4,$2
	jal	my_print
	nop

	li	$2,10			# 0xa
	sw	$2,24($fp)
	sw	$0,28($fp)
	addiu	$2,$fp,24
	move	$4,$2
	jal	my_print
	nop

	addiu	$2,$fp,88
	move	$4,$2
	jal	my_a2i
	nop

	sw	$2,16($fp)
	li	$2,3			# 0x3
	sw	$2,20($fp)
	j	$L3
	nop

$L4:
	lw	$4,20($fp)
	jal	sosuu_check
	nop

	beq	$2,$0,$L5
	nop

	lw	$4,20($fp)
	jal	my_i2a
	nop

$L5:
	lw	$2,20($fp)
	nop
	addiu	$2,$2,1
	sw	$2,20($fp)
$L3:
	lw	$2,20($fp)
	lw	$3,16($fp)
	nop
	sltu	$2,$3,$2
	beq	$2,$0,$L4
	nop

	li	$2,10			# 0xa
	sw	$2,24($fp)
	sw	$0,28($fp)
	addiu	$2,$fp,24
	move	$4,$2
	jal	my_print
	nop

	j	$L2
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
	.align	2
	.globl	sosuu_check
	.ent	sosuu_check
sosuu_check:
	.frame	$fp,32,$31		# vars= 24, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	
	addiu	$sp,$sp,-32
	sw	$fp,24($sp)
	move	$fp,$sp
	sw	$4,32($fp)
	lw	$2,32($fp)
	nop
	andi	$2,$2,0x1
	bne	$2,$0,$L10
	nop

	sw	$0,16($fp)
	j	$L12
	nop

$L10:
	li	$2,1			# 0x1
	sw	$2,4($fp)
	li	$2,3			# 0x3
	sw	$2,8($fp)
	j	$L13
	nop

$L14:
	lw	$2,8($fp)
	nop
	sw	$2,0($fp)
	j	$L15
	nop

$L16:
	lw	$3,32($fp)
	lw	$2,0($fp)
	nop
	bne	$3,$2,$L17
	nop

	sw	$0,4($fp)
$L17:
	lw	$2,0($fp)
	lw	$3,8($fp)
	nop
	addu	$2,$2,$3
	sw	$2,0($fp)
$L15:
	lw	$2,0($fp)
	lw	$3,32($fp)
	nop
	sltu	$2,$3,$2
	beq	$2,$0,$L16
	nop

	lw	$2,8($fp)
	nop
	addiu	$2,$2,2
	sw	$2,8($fp)
$L13:
	lw	$2,32($fp)
	nop
	srl	$3,$2,1
	lw	$2,8($fp)
	nop
	sltu	$2,$2,$3
	bne	$2,$0,$L14
	nop

	lw	$2,4($fp)
	nop
	sw	$2,16($fp)
$L12:
	lw	$2,16($fp)
	move	$sp,$fp
	lw	$fp,24($sp)
	addiu	$sp,$sp,32
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	sosuu_check
	.size	sosuu_check, .-sosuu_check
	.align	2
	.globl	my_a2i
	.ent	my_a2i
my_a2i:
	.frame	$fp,24,$31		# vars= 16, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	
	addiu	$sp,$sp,-24
	sw	$fp,16($sp)
	move	$fp,$sp
	sw	$4,24($fp)
	lw	$2,24($fp)
	nop
	sw	$2,8($fp)
	sw	$0,4($fp)
	j	$L23
	nop

$L24:
	lw	$2,8($fp)
	nop
	addiu	$2,$2,4
	sw	$2,8($fp)
	lw	$2,4($fp)
	nop
	addiu	$2,$2,1
	sw	$2,4($fp)
$L23:
	lw	$2,8($fp)
	nop
	lw	$2,0($2)
	nop
	bne	$2,$0,$L24
	nop

	sw	$0,0($fp)
	lw	$2,24($fp)
	nop
	sw	$2,8($fp)
	lw	$3,4($fp)
	li	$2,1			# 0x1
	bne	$3,$2,$L26
	nop

	lw	$2,8($fp)
	nop
	lw	$2,0($2)
	nop
	addiu	$2,$2,-48
	sw	$2,0($fp)
	j	$L28
	nop

$L26:
	lw	$3,4($fp)
	li	$2,2			# 0x2
	bne	$3,$2,$L29
	nop

	sw	$0,4($fp)
	j	$L31
	nop

$L32:
	lw	$2,0($fp)
	nop
	addiu	$2,$2,10
	sw	$2,0($fp)
	lw	$2,4($fp)
	nop
	addiu	$2,$2,1
	sw	$2,4($fp)
$L31:
	lw	$2,8($fp)
	nop
	lw	$2,0($2)
	nop
	addiu	$3,$2,-48
	lw	$2,4($fp)
	nop
	sltu	$2,$2,$3
	bne	$2,$0,$L32
	nop

	lw	$2,8($fp)
	nop
	addiu	$2,$2,4
	sw	$2,8($fp)
	lw	$2,8($fp)
	nop
	lw	$3,0($2)
	lw	$2,0($fp)
	nop
	addu	$2,$3,$2
	addiu	$2,$2,-48
	sw	$2,0($fp)
	j	$L28
	nop

$L29:
	lw	$3,4($fp)
	li	$2,3			# 0x3
	bne	$3,$2,$L28
	nop

	sw	$0,4($fp)
	j	$L35
	nop

$L36:
	lw	$2,0($fp)
	nop
	addiu	$2,$2,100
	sw	$2,0($fp)
	lw	$2,4($fp)
	nop
	addiu	$2,$2,1
	sw	$2,4($fp)
$L35:
	lw	$2,8($fp)
	nop
	lw	$2,0($2)
	nop
	addiu	$3,$2,-48
	lw	$2,4($fp)
	nop
	sltu	$2,$2,$3
	bne	$2,$0,$L36
	nop

	lw	$2,8($fp)
	nop
	addiu	$2,$2,4
	sw	$2,8($fp)
	sw	$0,4($fp)
	j	$L38
	nop

$L39:
	lw	$2,0($fp)
	nop
	addiu	$2,$2,10
	sw	$2,0($fp)
	lw	$2,4($fp)
	nop
	addiu	$2,$2,1
	sw	$2,4($fp)
$L38:
	lw	$2,8($fp)
	nop
	lw	$2,0($2)
	nop
	addiu	$3,$2,-48
	lw	$2,4($fp)
	nop
	sltu	$2,$2,$3
	bne	$2,$0,$L39
	nop

	lw	$2,8($fp)
	nop
	addiu	$2,$2,4
	sw	$2,8($fp)
	lw	$2,8($fp)
	nop
	lw	$3,0($2)
	lw	$2,0($fp)
	nop
	addu	$2,$3,$2
	addiu	$2,$2,-48
	sw	$2,0($fp)
$L28:
	lw	$2,0($fp)
	move	$sp,$fp
	lw	$fp,16($sp)
	addiu	$sp,$sp,24
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	my_a2i
	.size	my_a2i, .-my_a2i
	.align	2
	.globl	my_i2a
	.ent	my_i2a
my_i2a:
	.frame	$fp,48,$31		# vars= 24, regs= 2/0, args= 16, gp= 0
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	
	addiu	$sp,$sp,-48
	sw	$31,44($sp)
	sw	$fp,40($sp)
	move	$fp,$sp
	sw	$4,48($fp)
	sw	$0,16($fp)
	j	$L43
	nop

$L44:
	lw	$2,48($fp)
	nop
	addiu	$2,$2,-10
	sw	$2,48($fp)
	lw	$2,16($fp)
	nop
	addiu	$2,$2,1
	sw	$2,16($fp)
$L43:
	lw	$2,48($fp)
	nop
	sltu	$2,$2,10
	beq	$2,$0,$L44
	nop

	lw	$2,16($fp)
	nop
	addiu	$2,$2,48
	sw	$2,20($fp)
	lw	$2,48($fp)
	nop
	addiu	$2,$2,48
	sw	$2,24($fp)
	li	$2,32			# 0x20
	sw	$2,28($fp)
	sw	$0,32($fp)
	addiu	$2,$fp,20
	move	$4,$2
	jal	my_print
	nop

	move	$sp,$fp
	lw	$31,44($sp)
	lw	$fp,40($sp)
	addiu	$sp,$sp,48
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	my_i2a
	.size	my_i2a, .-my_i2a
	.align	2
	.globl	my_scan
	.ent	my_scan
my_scan:
	.frame	$fp,8,$31		# vars= 0, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	
	addiu	$sp,$sp,-8
	sw	$fp,0($sp)
	move	$fp,$sp
	sw	$4,8($fp)
	li	$2,776			# 0x308
	sw	$0,0($2)
	li	$3,780			# 0x30c
	li	$2,1			# 0x1
	sw	$2,0($3)
	li	$3,776			# 0x308
	li	$2,1			# 0x1
	sw	$2,0($3)
	li	$2,776			# 0x308
	sw	$0,0($2)
	li	$3,776			# 0x308
	li	$2,1			# 0x1
	sw	$2,0($3)
	j	$L48
	nop

$L49:
	li	$2,776			# 0x308
	sw	$0,0($2)
	li	$3,776			# 0x308
	li	$2,1			# 0x1
	sw	$2,0($3)
$L48:
	li	$2,784			# 0x310
	lw	$3,0($2)
	li	$2,-1			# 0xffffffffffffffff
	beq	$3,$2,$L49
	nop

	j	$L51
	nop

$L52:
	lw	$2,8($fp)
	nop
	lw	$2,0($2)
	nop
	beq	$2,$0,$L53
	nop

	lw	$2,8($fp)
	nop
	lw	$2,0($2)
	nop
	sltu	$2,$2,27
	beq	$2,$0,$L53
	nop

	lw	$2,8($fp)
	nop
	lw	$2,0($2)
	nop
	addiu	$3,$2,64
	lw	$2,8($fp)
	nop
	sw	$3,0($2)
	j	$L56
	nop

$L53:
	lw	$2,8($fp)
	nop
	lw	$2,0($2)
	nop
	sltu	$2,$2,48
	bne	$2,$0,$L57
	nop

	lw	$2,8($fp)
	nop
	lw	$2,0($2)
	nop
	sltu	$2,$2,58
	beq	$2,$0,$L57
	nop

	lw	$2,8($fp)
	nop
	lw	$3,0($2)
	lw	$2,8($fp)
	nop
	sw	$3,0($2)
	j	$L56
	nop

$L57:
	lw	$2,8($fp)
	nop
	lw	$2,0($2)
	nop
	bne	$2,$0,$L60
	nop

	lw	$3,8($fp)
	li	$2,64			# 0x40
	sw	$2,0($3)
	j	$L56
	nop

$L60:
	lw	$2,8($fp)
	nop
	lw	$3,0($2)
	li	$2,27			# 0x1b
	bne	$3,$2,$L62
	nop

	lw	$3,8($fp)
	li	$2,91			# 0x5b
	sw	$2,0($3)
	j	$L56
	nop

$L62:
	lw	$2,8($fp)
	nop
	lw	$3,0($2)
	li	$2,29			# 0x1d
	bne	$3,$2,$L64
	nop

	lw	$3,8($fp)
	li	$2,93			# 0x5d
	sw	$2,0($3)
	j	$L56
	nop

$L64:
	lw	$2,8($fp)
	nop
	lw	$2,0($2)
	nop
	sltu	$2,$2,32
	bne	$2,$0,$L66
	nop

	lw	$2,8($fp)
	nop
	lw	$2,0($2)
	nop
	sltu	$2,$2,48
	beq	$2,$0,$L66
	nop

	lw	$2,8($fp)
	nop
	lw	$3,0($2)
	lw	$2,8($fp)
	nop
	sw	$3,0($2)
	j	$L56
	nop

$L66:
	lw	$2,8($fp)
	nop
	lw	$3,0($2)
	li	$2,58			# 0x3a
	bne	$3,$2,$L69
	nop

	lw	$3,8($fp)
	li	$2,63			# 0x3f
	sw	$2,0($3)
	j	$L56
	nop

$L69:
	lw	$2,8($fp)
	nop
	lw	$3,0($2)
	li	$2,59			# 0x3b
	bne	$3,$2,$L71
	nop

	lw	$3,8($fp)
	li	$2,61			# 0x3d
	sw	$2,0($3)
	j	$L56
	nop

$L71:
	lw	$2,8($fp)
	nop
	lw	$3,0($2)
	li	$2,60			# 0x3c
	bne	$3,$2,$L73
	nop

	lw	$3,8($fp)
	li	$2,59			# 0x3b
	sw	$2,0($3)
	j	$L56
	nop

$L73:
	lw	$2,8($fp)
	nop
	lw	$3,0($2)
	li	$2,61			# 0x3d
	bne	$3,$2,$L75
	nop

	lw	$3,8($fp)
	li	$2,58			# 0x3a
	sw	$2,0($3)
	j	$L56
	nop

$L75:
	lw	$2,8($fp)
	nop
	lw	$3,0($2)
	li	$2,62			# 0x3e
	bne	$3,$2,$L77
	nop

	lw	$3,8($fp)
	li	$2,10			# 0xa
	sw	$2,0($3)
	j	$L56
	nop

$L77:
	lw	$3,8($fp)
	li	$2,64			# 0x40
	sw	$2,0($3)
$L56:
	li	$2,776			# 0x308
	sw	$0,0($2)
	li	$3,776			# 0x308
	li	$2,1			# 0x1
	sw	$2,0($3)
	lw	$2,8($fp)
	nop
	addiu	$2,$2,4
	sw	$2,8($fp)
$L51:
	li	$2,784			# 0x310
	lw	$3,0($2)
	lw	$2,8($fp)
	nop
	sw	$3,0($2)
	lw	$2,8($fp)
	nop
	lw	$3,0($2)
	li	$2,62			# 0x3e
	bne	$3,$2,$L52
	nop

	lw	$2,8($fp)
	nop
	sw	$0,0($2)
	li	$2,776			# 0x308
	sw	$0,0($2)
	li	$2,780			# 0x30c
	sw	$0,0($2)
	li	$3,776			# 0x308
	li	$2,1			# 0x1
	sw	$2,0($3)
	li	$2,776			# 0x308
	sw	$0,0($2)
	move	$sp,$fp
	lw	$fp,0($sp)
	addiu	$sp,$sp,8
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	my_scan
	.size	my_scan, .-my_scan
	.align	2
	.globl	my_print
	.ent	my_print
my_print:
	.frame	$fp,8,$31		# vars= 0, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	
	addiu	$sp,$sp,-8
	sw	$fp,0($sp)
	move	$fp,$sp
	sw	$4,8($fp)
	j	$L82
	nop

$L83:
	li	$2,768			# 0x300
	sw	$0,0($2)
	lw	$2,8($fp)
	nop
	lw	$2,0($2)
	nop
	sltu	$2,$2,65
	bne	$2,$0,$L84
	nop

	lw	$2,8($fp)
	nop
	lw	$2,0($2)
	nop
	sltu	$2,$2,91
	beq	$2,$0,$L84
	nop

	li	$3,772			# 0x304
	lw	$2,8($fp)
	nop
	lw	$2,0($2)
	nop
	addiu	$2,$2,-64
	sw	$2,0($3)
	j	$L87
	nop

$L84:
	lw	$2,8($fp)
	nop
	lw	$2,0($2)
	nop
	sltu	$2,$2,97
	bne	$2,$0,$L88
	nop

	lw	$2,8($fp)
	nop
	lw	$2,0($2)
	nop
	sltu	$2,$2,123
	beq	$2,$0,$L88
	nop

	li	$3,772			# 0x304
	lw	$2,8($fp)
	nop
	lw	$2,0($2)
	nop
	addiu	$2,$2,-96
	sw	$2,0($3)
	j	$L87
	nop

$L88:
	lw	$2,8($fp)
	nop
	lw	$2,0($2)
	nop
	sltu	$2,$2,48
	bne	$2,$0,$L91
	nop

	lw	$2,8($fp)
	nop
	lw	$2,0($2)
	nop
	sltu	$2,$2,58
	beq	$2,$0,$L91
	nop

	li	$2,772			# 0x304
	lw	$3,8($fp)
	nop
	lw	$3,0($3)
	nop
	sw	$3,0($2)
	j	$L87
	nop

$L91:
	lw	$2,8($fp)
	nop
	lw	$3,0($2)
	li	$2,64			# 0x40
	bne	$3,$2,$L94
	nop

	li	$2,772			# 0x304
	sw	$0,0($2)
	j	$L87
	nop

$L94:
	lw	$2,8($fp)
	nop
	lw	$3,0($2)
	li	$2,91			# 0x5b
	bne	$3,$2,$L96
	nop

	li	$3,772			# 0x304
	li	$2,27			# 0x1b
	sw	$2,0($3)
	j	$L87
	nop

$L96:
	lw	$2,8($fp)
	nop
	lw	$3,0($2)
	li	$2,93			# 0x5d
	bne	$3,$2,$L98
	nop

	li	$3,772			# 0x304
	li	$2,29			# 0x1d
	sw	$2,0($3)
	j	$L87
	nop

$L98:
	lw	$2,8($fp)
	nop
	lw	$2,0($2)
	nop
	sltu	$2,$2,32
	bne	$2,$0,$L100
	nop

	lw	$2,8($fp)
	nop
	lw	$2,0($2)
	nop
	sltu	$2,$2,48
	beq	$2,$0,$L100
	nop

	li	$2,772			# 0x304
	lw	$3,8($fp)
	nop
	lw	$3,0($3)
	nop
	sw	$3,0($2)
	j	$L87
	nop

$L100:
	lw	$2,8($fp)
	nop
	lw	$3,0($2)
	li	$2,63			# 0x3f
	bne	$3,$2,$L103
	nop

	li	$3,772			# 0x304
	li	$2,58			# 0x3a
	sw	$2,0($3)
	j	$L87
	nop

$L103:
	lw	$2,8($fp)
	nop
	lw	$3,0($2)
	li	$2,61			# 0x3d
	bne	$3,$2,$L105
	nop

	li	$3,772			# 0x304
	li	$2,59			# 0x3b
	sw	$2,0($3)
	j	$L87
	nop

$L105:
	lw	$2,8($fp)
	nop
	lw	$3,0($2)
	li	$2,59			# 0x3b
	bne	$3,$2,$L107
	nop

	li	$3,772			# 0x304
	li	$2,60			# 0x3c
	sw	$2,0($3)
	j	$L87
	nop

$L107:
	lw	$2,8($fp)
	nop
	lw	$3,0($2)
	li	$2,58			# 0x3a
	bne	$3,$2,$L109
	nop

	li	$3,772			# 0x304
	li	$2,61			# 0x3d
	sw	$2,0($3)
	j	$L87
	nop

$L109:
	lw	$2,8($fp)
	nop
	lw	$3,0($2)
	li	$2,10			# 0xa
	bne	$3,$2,$L111
	nop

	li	$3,772			# 0x304
	li	$2,62			# 0x3e
	sw	$2,0($3)
	j	$L87
	nop

$L111:
	li	$2,772			# 0x304
	sw	$0,0($2)
$L87:
	li	$3,768			# 0x300
	li	$2,1			# 0x1
	sw	$2,0($3)
	lw	$2,8($fp)
	nop
	addiu	$2,$2,4
	sw	$2,8($fp)
$L82:
	lw	$2,8($fp)
	nop
	lw	$2,0($2)
	nop
	bne	$2,$0,$L83
	nop

	move	$sp,$fp
	lw	$fp,0($sp)
	addiu	$sp,$sp,8
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	my_print
	.size	my_print, .-my_print
	.ident	"GCC: (GNU) 4.2.0"

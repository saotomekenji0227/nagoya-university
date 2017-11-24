	.file	1 "motor.c"
	.section .mdebug.abi32
	.previous
	.text
	.align	2
	.globl	main
	.ent	main
main:
	.frame	$fp,104,$31		# vars= 80, regs= 2/0, args= 16, gp= 0
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	
	addiu	$sp,$sp,-104
	sw	$31,100($sp)
	sw	$fp,96($sp)
	move	$fp,$sp
	sw	$0,24($fp)
$L2:
	addiu	$2,$fp,28
	move	$4,$2
	jal	my_scan
	nop

	lw	$3,28($fp)
	li	$2,82			# 0x52
	bne	$3,$2,$L3
	nop

	sw	$0,24($fp)
	j	$L5
	nop

$L3:
	lw	$3,28($fp)
	li	$2,76			# 0x4c
	bne	$3,$2,$L6
	nop

	li	$2,1			# 0x1
	sw	$2,24($fp)
	j	$L5
	nop

$L6:
	lw	$3,28($fp)
	li	$2,83			# 0x53
	bne	$3,$2,$L5
	nop

	li	$2,2			# 0x2
	sw	$2,24($fp)
$L5:
	addiu	$2,$fp,28
	move	$4,$2
	jal	my_scan
	nop

	addiu	$2,$fp,28
	move	$4,$2
	jal	my_a2i
	nop

	sw	$2,16($fp)
	lw	$2,24($fp)
	nop
	bne	$2,$0,$L9
	nop

	sw	$0,20($fp)
	j	$L11
	nop

$L12:
	jal	my_motor1
	nop

	lw	$2,20($fp)
	nop
	addiu	$2,$2,1
	sw	$2,20($fp)
$L11:
	lw	$2,20($fp)
	lw	$3,16($fp)
	nop
	sltu	$2,$2,$3
	bne	$2,$0,$L12
	nop

	j	$L2
	nop

$L9:
	lw	$3,24($fp)
	li	$2,1			# 0x1
	bne	$3,$2,$L15
	nop

	sw	$0,20($fp)
	j	$L17
	nop

$L18:
	jal	my_motor2
	nop

	lw	$2,20($fp)
	nop
	addiu	$2,$2,1
	sw	$2,20($fp)
$L17:
	lw	$2,20($fp)
	lw	$3,16($fp)
	nop
	sltu	$2,$2,$3
	bne	$2,$0,$L18
	nop

	j	$L2
	nop

$L15:
	sw	$0,20($fp)
	j	$L20
	nop

$L21:
	jal	my_motor3
	nop

	lw	$2,20($fp)
	nop
	addiu	$2,$2,1
	sw	$2,20($fp)
$L20:
	lw	$2,20($fp)
	lw	$3,16($fp)
	nop
	sltu	$2,$2,$3
	bne	$2,$0,$L21
	nop

	j	$L2
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
	.align	2
	.globl	my_motor1
	.ent	my_motor1
my_motor1:
	.frame	$fp,24,$31		# vars= 0, regs= 2/0, args= 16, gp= 0
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	
	addiu	$sp,$sp,-24
	sw	$31,20($sp)
	sw	$fp,16($sp)
	move	$fp,$sp
	li	$4,8			# 0x8
	jal	ext_out
	nop

	li	$4,4			# 0x4
	jal	ext_out
	nop

	li	$4,2			# 0x2
	jal	ext_out
	nop

	li	$4,1			# 0x1
	jal	ext_out
	nop

	move	$sp,$fp
	lw	$31,20($sp)
	lw	$fp,16($sp)
	addiu	$sp,$sp,24
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	my_motor1
	.size	my_motor1, .-my_motor1
	.align	2
	.globl	my_motor2
	.ent	my_motor2
my_motor2:
	.frame	$fp,24,$31		# vars= 0, regs= 2/0, args= 16, gp= 0
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	
	addiu	$sp,$sp,-24
	sw	$31,20($sp)
	sw	$fp,16($sp)
	move	$fp,$sp
	li	$4,8			# 0x8
	jal	ext_out
	nop

	li	$4,1			# 0x1
	jal	ext_out
	nop

	li	$4,2			# 0x2
	jal	ext_out
	nop

	li	$4,4			# 0x4
	jal	ext_out
	nop

	move	$sp,$fp
	lw	$31,20($sp)
	lw	$fp,16($sp)
	addiu	$sp,$sp,24
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	my_motor2
	.size	my_motor2, .-my_motor2
	.align	2
	.globl	my_motor3
	.ent	my_motor3
my_motor3:
	.frame	$fp,24,$31		# vars= 0, regs= 2/0, args= 16, gp= 0
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	
	addiu	$sp,$sp,-24
	sw	$31,20($sp)
	sw	$fp,16($sp)
	move	$fp,$sp
	li	$4,8			# 0x8
	jal	ext_out
	nop

	li	$4,8			# 0x8
	jal	ext_out
	nop

	li	$4,8			# 0x8
	jal	ext_out
	nop

	li	$4,8			# 0x8
	jal	ext_out
	nop

	move	$sp,$fp
	lw	$31,20($sp)
	lw	$fp,16($sp)
	addiu	$sp,$sp,24
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	my_motor3
	.size	my_motor3, .-my_motor3
	.align	2
	.globl	ext_out
	.ent	ext_out
ext_out:
	.frame	$fp,16,$31		# vars= 8, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	
	addiu	$sp,$sp,-16
	sw	$fp,8($sp)
	move	$fp,$sp
	sw	$4,16($fp)
	li	$3,800			# 0x320
	lw	$2,16($fp)
	nop
	sw	$2,0($3)
	move	$sp,$fp
	lw	$fp,8($sp)
	addiu	$sp,$sp,16
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	ext_out
	.size	ext_out, .-ext_out
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
	j	$L32
	nop

$L33:
	li	$2,776			# 0x308
	sw	$0,0($2)
	li	$3,776			# 0x308
	li	$2,1			# 0x1
	sw	$2,0($3)
$L32:
	li	$2,784			# 0x310
	lw	$3,0($2)
	li	$2,-1			# 0xffffffffffffffff
	beq	$3,$2,$L33
	nop

	j	$L35
	nop

$L36:
	lw	$2,8($fp)
	nop
	lw	$2,0($2)
	nop
	beq	$2,$0,$L37
	nop

	lw	$2,8($fp)
	nop
	lw	$2,0($2)
	nop
	sltu	$2,$2,27
	beq	$2,$0,$L37
	nop

	lw	$2,8($fp)
	nop
	lw	$2,0($2)
	nop
	addiu	$3,$2,64
	lw	$2,8($fp)
	nop
	sw	$3,0($2)
	j	$L40
	nop

$L37:
	lw	$2,8($fp)
	nop
	lw	$2,0($2)
	nop
	sltu	$2,$2,48
	bne	$2,$0,$L41
	nop

	lw	$2,8($fp)
	nop
	lw	$2,0($2)
	nop
	sltu	$2,$2,58
	beq	$2,$0,$L41
	nop

	lw	$2,8($fp)
	nop
	lw	$3,0($2)
	lw	$2,8($fp)
	nop
	sw	$3,0($2)
	j	$L40
	nop

$L41:
	lw	$2,8($fp)
	nop
	lw	$2,0($2)
	nop
	bne	$2,$0,$L44
	nop

	lw	$3,8($fp)
	li	$2,64			# 0x40
	sw	$2,0($3)
	j	$L40
	nop

$L44:
	lw	$2,8($fp)
	nop
	lw	$3,0($2)
	li	$2,27			# 0x1b
	bne	$3,$2,$L46
	nop

	lw	$3,8($fp)
	li	$2,91			# 0x5b
	sw	$2,0($3)
	j	$L40
	nop

$L46:
	lw	$2,8($fp)
	nop
	lw	$3,0($2)
	li	$2,29			# 0x1d
	bne	$3,$2,$L48
	nop

	lw	$3,8($fp)
	li	$2,93			# 0x5d
	sw	$2,0($3)
	j	$L40
	nop

$L48:
	lw	$2,8($fp)
	nop
	lw	$2,0($2)
	nop
	sltu	$2,$2,32
	bne	$2,$0,$L50
	nop

	lw	$2,8($fp)
	nop
	lw	$2,0($2)
	nop
	sltu	$2,$2,48
	beq	$2,$0,$L50
	nop

	lw	$2,8($fp)
	nop
	lw	$3,0($2)
	lw	$2,8($fp)
	nop
	sw	$3,0($2)
	j	$L40
	nop

$L50:
	lw	$2,8($fp)
	nop
	lw	$3,0($2)
	li	$2,58			# 0x3a
	bne	$3,$2,$L53
	nop

	lw	$3,8($fp)
	li	$2,63			# 0x3f
	sw	$2,0($3)
	j	$L40
	nop

$L53:
	lw	$2,8($fp)
	nop
	lw	$3,0($2)
	li	$2,59			# 0x3b
	bne	$3,$2,$L55
	nop

	lw	$3,8($fp)
	li	$2,61			# 0x3d
	sw	$2,0($3)
	j	$L40
	nop

$L55:
	lw	$2,8($fp)
	nop
	lw	$3,0($2)
	li	$2,60			# 0x3c
	bne	$3,$2,$L57
	nop

	lw	$3,8($fp)
	li	$2,59			# 0x3b
	sw	$2,0($3)
	j	$L40
	nop

$L57:
	lw	$2,8($fp)
	nop
	lw	$3,0($2)
	li	$2,61			# 0x3d
	bne	$3,$2,$L59
	nop

	lw	$3,8($fp)
	li	$2,58			# 0x3a
	sw	$2,0($3)
	j	$L40
	nop

$L59:
	lw	$2,8($fp)
	nop
	lw	$3,0($2)
	li	$2,62			# 0x3e
	bne	$3,$2,$L61
	nop

	lw	$3,8($fp)
	li	$2,10			# 0xa
	sw	$2,0($3)
	j	$L40
	nop

$L61:
	lw	$3,8($fp)
	li	$2,64			# 0x40
	sw	$2,0($3)
$L40:
	li	$2,776			# 0x308
	sw	$0,0($2)
	li	$3,776			# 0x308
	li	$2,1			# 0x1
	sw	$2,0($3)
	lw	$2,8($fp)
	nop
	addiu	$2,$2,4
	sw	$2,8($fp)
$L35:
	li	$2,784			# 0x310
	lw	$3,0($2)
	lw	$2,8($fp)
	nop
	sw	$3,0($2)
	lw	$2,8($fp)
	nop
	lw	$3,0($2)
	li	$2,62			# 0x3e
	bne	$3,$2,$L36
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
	j	$L66
	nop

$L67:
	lw	$2,8($fp)
	nop
	addiu	$2,$2,4
	sw	$2,8($fp)
	lw	$2,4($fp)
	nop
	addiu	$2,$2,1
	sw	$2,4($fp)
$L66:
	lw	$2,8($fp)
	nop
	lw	$2,0($2)
	nop
	bne	$2,$0,$L67
	nop

	sw	$0,0($fp)
	lw	$2,24($fp)
	nop
	sw	$2,8($fp)
	lw	$3,4($fp)
	li	$2,1			# 0x1
	bne	$3,$2,$L69
	nop

	lw	$2,8($fp)
	nop
	lw	$2,0($2)
	nop
	addiu	$2,$2,-48
	sw	$2,0($fp)
	j	$L71
	nop

$L69:
	lw	$3,4($fp)
	li	$2,2			# 0x2
	bne	$3,$2,$L72
	nop

	sw	$0,4($fp)
	j	$L74
	nop

$L75:
	lw	$2,0($fp)
	nop
	addiu	$2,$2,10
	sw	$2,0($fp)
	lw	$2,4($fp)
	nop
	addiu	$2,$2,1
	sw	$2,4($fp)
$L74:
	lw	$2,8($fp)
	nop
	lw	$2,0($2)
	nop
	addiu	$3,$2,-48
	lw	$2,4($fp)
	nop
	sltu	$2,$2,$3
	bne	$2,$0,$L75
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
	j	$L71
	nop

$L72:
	lw	$3,4($fp)
	li	$2,3			# 0x3
	bne	$3,$2,$L71
	nop

	sw	$0,4($fp)
	j	$L78
	nop

$L79:
	lw	$2,0($fp)
	nop
	addiu	$2,$2,100
	sw	$2,0($fp)
	lw	$2,4($fp)
	nop
	addiu	$2,$2,1
	sw	$2,4($fp)
$L78:
	lw	$2,8($fp)
	nop
	lw	$2,0($2)
	nop
	addiu	$3,$2,-48
	lw	$2,4($fp)
	nop
	sltu	$2,$2,$3
	bne	$2,$0,$L79
	nop

	lw	$2,8($fp)
	nop
	addiu	$2,$2,4
	sw	$2,8($fp)
	sw	$0,4($fp)
	j	$L81
	nop

$L82:
	lw	$2,0($fp)
	nop
	addiu	$2,$2,10
	sw	$2,0($fp)
	lw	$2,4($fp)
	nop
	addiu	$2,$2,1
	sw	$2,4($fp)
$L81:
	lw	$2,8($fp)
	nop
	lw	$2,0($2)
	nop
	addiu	$3,$2,-48
	lw	$2,4($fp)
	nop
	sltu	$2,$2,$3
	bne	$2,$0,$L82
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
$L71:
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
	.ident	"GCC: (GNU) 4.2.0"

	.section .text
	.align 4
	.global memcpy_fast
	.type memcpy_fast, @function
	
memcpy_fast:
	mov.n   a5, a2
	movi    a6, 4
	
.Lloop4:
	bltu    a4, a6, .Ltail
	l32i    a7, a3, 0
	s32i    a7, a2, 0
	addi    a3, a3, 4
	addi    a2, a2, 4
	addi    a4, a4, -4
	j       .Lloop4
	
.Ltail:
	beqz    a4, .Ldone
.Lloop1:
	l8ui    a7, a3, 0
	s8i     a7, a2, 0
	addi    a3, a3, 1
	addi    a2, a2, 1
	addi    a4, a4, -1
	bnez    a4, .Lloop1
	
.Ldone:
	mov.n   a2, a5
	ret
	
	.size memcpy_fast, . - memcpy_fast
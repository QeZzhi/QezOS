	.section .text
	.align 4	
	.global memset_fast
	.type memset_fast, @function
	
memset_fast:
	mov.n   a5, a2
	
	extui   a3, a3, 0, 8
	
	movi    a8, 0x01010101
	mull     a3, a3, a8
	
	movi    a8, 4
.Lloop4:
	bltu    a4, a8, .Ltail
	s32i    a3, a2, 0
	addi    a2, a2, 4
	addi    a4, a4, -4
	j       .Lloop4
	
.Ltail:
	beqz    a4, .Ldone
.Lloop1:
	s8i     a3, a2, 0
	addi    a2, a2, 1
	addi    a4, a4, -1
	bnez    a4, .Lloop1
	
.Ldone:
	mov.n   a2, a5
	ret
	
	.size memset_fast, . - memset_fast
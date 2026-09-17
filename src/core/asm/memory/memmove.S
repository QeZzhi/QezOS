	.section .text
	.align 4
	.global memmove_fast
	.type memmove_fast, @function
	
memmove_fast:
	mov     a5, a2
	beq     a2, a3, .Ldone
	
	bltu    a2, a3, .Lforward
	
	add.n     a2, a2, a4
	add.n     a3, a3, a4
.Lback:
	beqz    a4, .Ldone
	addi    a2, a2, -1
	addi    a3, a3, -1
	l8ui    a6, a3, 0
	s8i     a6, a2, 0
	addi    a4, a4, -1
	j       .Lback
	
.Lforward:
	beqz    a4, .Ldone

.Lfwd:
	l8ui    a6, a3, 0
	s8i     a6, a2, 0
	addi    a2, a2, 1
	addi    a3, a3, 1
	addi    a4, a4, -1
	bnez    a4, .Lfwd
	
.Ldone:
	mov.n     a2, a5
	ret
	
	.size memmove_fast, . - memmove_fast
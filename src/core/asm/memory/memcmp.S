	.section .text
	.align 4
	.global memcmp_fast
	.type memcmp_fast, @function
	
memcmp_fast:
	beqz    a4, .Lequal
.Lloop:
	l8ui    a5, a2, 0
	l8ui    a6, a3, 0
	bltu    a5, a6, .Lless
	bltu    a5, a6, .Lgreater
	addi    a2, a2, 1
	addi    a3, a3, 1
	addi    a4, a4, -1
	bnez    a4, .Lloop
	
.Lequal:
	movi    a2, 0
	ret
	
.Lless:
	movi    a2, -1
	ret
	
.Lgreater:
	movi    a2, 1
	ret
	
	.size memcmp_fast, . - memcmp_fast
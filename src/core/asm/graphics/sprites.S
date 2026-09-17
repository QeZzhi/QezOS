	.section .text	
	.align 4
	
	.global draw_sprite_fast
	.type draw_sprite_fast, @function
	
draw_sprite_fast:
	beqz    a5, .Lsprite_done
	bltz    a5, .Lsprite_done
	beqz    a6, .Lsprite_done
	bltz    a6, .Lsprite_done
	
	mov.n   a7, a2
	mov.n   a8, a3
	
	movi    a9, 135
	mull    a9, a3, a9
	add.n   a9, a9, a2
	slli    a9, a9, 1
	
	movi    a10, 0x3C000000
	add.n   a10, a10, a9
	
	movi    a11, 270
	
.Lsprite_row:
	mov.n   a12, a10
	mov.n   a13, a5
	
.Lsprite_col:
	l16ui   a14, a4, 0
	s16i    a14, a12, 0
	addi    a4, a4, 2
	addi    a12, a12, 2
	addi    a13, a13, -1
	bnez    a13, .Lsprite_col
	
	add.n   a10, a10, a11
	addi    a6, a6, -1
	bnez    a6, .Lsprite_row
	
.Lsprite_done:
	ret
	
	.size draw_sprite_fast, . - draw_sprite_fast
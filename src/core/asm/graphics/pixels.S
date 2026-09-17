	.section .text
	.align 4
	
	
	.global draw_pixel_fast
	.type draw_pixel_fast, @function
	
draw_pixel_fast:
	bltz    a2, .Ldone
	bltz    a3, .Ldone
	bgeu    a2, a5, .Ldone
	movi    a5, 240
	bgeu    a3, a5, .Ldone
	
	movi    a5, 135
	mull    a5, a3, a5
	add.n   a5, a5, a2
	slli    a5, a5, 1
	
	movi    a6, 0x3C000000
	add.n   a6, a6, a5
	
	s16i    a4, a6, 0
	
.Ldone:
	ret
	
	.size draw_pixel_fast, . - draw_pixel_fast
	
	.align 4
	.global draw_hline_fast
	.type draw_hline_fast, @function
	
draw_hline_fast:
	bltz    a2, .Lhline_done
	bltz    a3, .Lhline_done
	beqz    a4, .Lhline_done
	bltz    a4, .Lhline_done
	
	movi    a6, 135
	mull    a6, a3, a6
	add.n   a6, a6, a2
	slli    a6, a6, 1
	
	movi    a7, 0x3C000000
	add.n   a7, a7, a6
	
.Lhline_loop:
	s16i    a5, a7, 0
	addi    a7, a7, 2
	addi    a4, a4, -1
	bnez    a4, .Lhline_loop
	
.Lhline_done:
	ret
	
	.size draw_hline_fast, . - draw_hline_fast
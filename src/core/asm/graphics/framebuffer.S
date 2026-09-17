	.section .text
	.align 4
	
	.global fill_screen_fast
	.type fill_screen_fast, @function
	
fill_screen_fast:
	movi    a3, 0x3C000000
	movi    a4, 32400
	movi    a5, 0
	
.Lfill_loop:
	s16i    a2, a3, 0
	addi    a3, a3, 2
	addi    a5, a5, 1
	bltu    a5, a4, .Lfill_loop
	ret
	
	.size fill_screen_fast, . - fill_screen_fast
	
	
	.align 4
	.global clear_screen_fast
	.type clear_screen_fast, @function
	
clear_screen_fast:
	movi     a2, 0
	j       fill_screen_fast
	
	.size clear_screen_fast, . - clear_screen_fast
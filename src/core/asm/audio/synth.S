	.section .text
	.align 4
	
	.global square_wave_fast
	.type square_wave_fast, @function
	
square_wave_fast:
	movi    a4, 128
	bltu    a2, a4, .Lsq_low
	mov.n   a2, a3
	ret
	
.Lsq_low:
	neg     a2, a3
	ret
	
	.size square_wave_fast, . - square_wave_fast
	
.align 4
	.global saw_wave_fast
	.type saw_wave_fast, @function
	
saw_wave_fast:
	movi    a4, 128
	sub     a2, a2, a4
	mull    a2, a2, a3
	srai    a2, a2, 7
	ret
	
	.size saw_wave_fast, . - saw_wave_fast
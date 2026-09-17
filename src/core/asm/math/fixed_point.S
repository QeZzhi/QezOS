	.section .text
	.align 4
	
	.global fixed_mul
	.type fixed_mul, @function
	
fixed_mul:
	mull    a2, a2, a3
	srai    a2, a2, 16
	ret
	
	.size fixed_mul, . - fixed_mul
	
	.align 4
	.global fixed_div
	.type fixed_div, @function
	
fixed_div:
	slli    a2, a2, 16
	quos    a2, a2, a3
	ret
	
	.size fixed_div, . - fixed_div
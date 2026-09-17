	.section .text
	.align 4
	
	.global fast_abs_int
	.type fast_abs_int, @function
	
fast_abs_int:
	abs     a2, a2
	ret
	
	.size fast_abs_int, . - fast_abs_int
	
	.align 4
	.global fast_min_int
	.type fast_min_int, @function
	
fast_min_int:
	min     a2, a2, a3
	ret
	
	.size fast_min_int, . - fast_min_int
	
	.align 4
	.global fast_max_int
	.type fast_max_int, @function
	
fast_max_int:
	max     a2, a2, a3
	ret
	
	.size fast_max_int, . - fast_max_int
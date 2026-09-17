	.section .text
	.align 4
	
	.global gpio_set_fast
	.type gpio_set_fast, @function
	
gpio_set_fast:
	movi    a3, 0x60004008
	movi    a4, 1
	ssl     a2
	sll     a4, a4
	s32i    a4, a3, 0
	ret
	
	.size gpio_set_fast, . - gpio_set_fast
	
	
	.align 4
	.global gpio_clear_fast
	.type gpio_clear_fast, @function
	
gpio_clear_fast:
	movi    a3, 0x6000400C
	movi    a4, 1
	ssl     a2
	sll     a4, a4
	s32i    a4, a3, 0
	ret
	
	.size gpio_clear_fast, . - gpio_clear_fast
	
	.align 4
	.global gpio_read_fast
	.type gpio_read_fast, @function
	
gpio_read_fast:
	movi    a3, 0x6000403C
	l32i    a4, a3, 0
	movi    a5, 1
	ssl     a2
	sll     a5, a5
	and     a2, a4, a5
	ret
	
	.size gpio_read_fast, . - gpio_read_fast
	.section .text
	.align 4
	
	.global i2c_start_fast
	.type i2c_start_fast, @function
	
i2c_start_fast:
	movi    a2, 0x60013004
	movi    a3, 0x00000001
	s32i    a3, a2, 0
	ret
	
	.size i2c_start_fast, . - i2c_start_fast
	
	
	.align 4
	.global i2c_stop_fast
	.type i2c_stop_fast, @function
	
i2c_stop_fast:
	movi    a2, 0x60013004
	movi    a3, 0x00000002
	s32i    a3, a2, 0
	ret
	
	.size i2c_stop_fast, . - i2c_stop_fast
	
	.align 4
	.global i2c_write_byte_fast
	.type i2c_write_byte_fast, @function
	
i2c_write_byte_fast:
	movi    a3, 0x6001301C
	s32i    a2, a3, 0
	movi    a3, 0x60013004
	movi    a4, 0x00000004
	ret
	
	.size i2c_write_byte_fast, . - i2c_write_byte_fast
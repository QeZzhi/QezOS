	.section .text
	.align 4
	
	
	.global spi_send_byte_fast
	.type spi_send_byte_fast, @function
	
spi_send_byte_fast:
	movi    a3, 0x3F000080
	s32i    a2, a3, 0
	movi    a3, 0x3F000024
	movi    a4, 7
	s32i    a4, a3, 0
	movi    a3, 0x3F000000
	movi    a4, 0x00000001
	s32i    a4, a3, 0
	ret
	
	.size spi_send_byte_fast, . - spi_send_byte_fast
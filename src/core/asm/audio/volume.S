	.section .text
	.align 4
	
	
	.global apply_volume_fast
	.type apply_volume_fast, @function
	
apply_volume_fast:
	mull    a2, a2, a3
	movi    a4, 255
	quos    a2, a2, a4
	ret
	
	.size apply_volume_fast, . - apply_volume_fast
	
	.align 4
	.global apply_volume_buffer_fast
	.type apply_volume_buffer_fast, @function
	
apply_volume_buffer_fast:
	beqz    a3, .Lvol_done
	bltz    a3, .Lvol_done
	
	movi    a5, 255
	
.Lvol_loop:
	l32i    a6, a2, 0
	mull    a6, a6, a4
	quos    a6, a6, a5
	s32i    a6, a2, 0
	
	addi    a2, a2, 4
	addi    a3, a3, -1
	bnez    a3, .Lvol_loop
	
.Lvol_done:
	ret
	
	.size apply_volume_buffer_fast, . - apply_volume_buffer_fast
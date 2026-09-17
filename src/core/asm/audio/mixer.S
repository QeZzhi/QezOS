	.section .text
	.align 4
	
	.global mix_audio_fast
	.type mix_audio_fast, @function

mix_audio_fast:
	add.n   a2, a2, a3
	srai    a2, a2, 1
	ret
	
	.size mix_audio_fast, . - mix_audio_fast
	
	.align 4
	.global mix_buffer_fast
	.type mix_buffer_fast, @function
	
mix_buffer_fast:
	beqz    a4, .Lmix_done
	bltz    a4, .Lmix_done
	
.Lmix_loop:
	l32i    a5, a2, 0
	l32i    a6, a3, 0
	add.n   a5, a5, a6
	srai    a5, a5, 1
	s32i    a5, a2, 0
	
	addi    a2, a2, 4
	addi    a3, a3, 4
	addi    a4, a4, -1
	bnez    a4, .Lmix_loop
	
.Lmix_done:
	ret
	
	.size mix_buffer_fast, . - mix_buffer_fast
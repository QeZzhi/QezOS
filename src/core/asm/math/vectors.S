	.section .text
	.align 4
	
	.global vec3_dot
	.type vec3_dot, @function
	
vec3_dot:
	l32i    a4, a2, 0
	l32i    a5, a3, 0
	mull    a4, a4, a5      /* a4 = a[0] * b[0] */
	mov.n   a6, a4
	
	l32i    a4, a2, 4	
	l32i    a5, a3, 4
	mull    a4, a4, a5      /* a4 = a[1] * b[1] */
	add.n   a6, a6, a4
	
	l32i    a4, a2, 8
	l32i    a5, a3, 8
	mull    a4, a4, a5      /* a4 = a[2] * b[2] */
	add.n   a6, a6, a4
	
	mov.n   a2, a6
	ret
	
	.size vec3_dot, . - vec3_dot
	
	.align 4
	.global vec3_add
	.type vec3_add, @function
	
vec3_add:
	l32i    a5, a3, 0
	l32i    a6, a4, 0
	add.n   a5, a5, a6
	s32i    a5, a2, 0
	
	l32i    a5, a3, 4
	l32i    a6, a4, 4
	add.n   a5, a5, a6
	s32i    a5, a2, 4
	
	l32i    a5, a3, 8
	l32i    a6, a4, 8
	add.n   a5, a5, a6
	s32i    a5, a2, 8
	
	ret
	
	.size vec3_add, . - vec3_add
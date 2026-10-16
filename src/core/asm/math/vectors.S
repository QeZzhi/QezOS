# ============================================================
# vectors.S — ассемблерные функции для 3D-векторов
# Скалярное произведение и сложение векторов.
# vectors.S — assembly functions for 3D vectors
# Dot product and vector addition.
# ============================================================

	.section .text      # Секция кода | Code section
	.align 4            # Выравнивание по 4 байта | Align to 4 bytes

# ------------------------------------------------------------
# vec3_dot — скалярное произведение двух 3D-векторов
# Вход: a2 = указатель на вектор A, a3 = указатель на вектор B
# Выход: a2 = A.x*B.x + A.y*B.y + A.z*B.z
# Векторы — массивы int[3]
# ------------------------------------------------------------
	.global vec3_dot          # Делаем символ глобальным | Make symbol global
	.type vec3_dot, @function # Тип: функция | Type: function
	
vec3_dot:                     # Метка функции | Function label
	l32i    a4, a2, 0         # a4 = A.x (читаем 4 байта) | a4 = A.x (read 4 bytes)
	l32i    a5, a3, 0         # a5 = B.x | a5 = B.x
	mull    a4, a4, a5        # a4 = A.x * B.x | a4 = A.x * B.x
	mov.n   a6, a4            # a6 = A.x * B.x (сохраняем результат) | a6 = A.x * B.x (save result)
	
	l32i    a4, a2, 4         # a4 = A.y | a4 = A.y
	l32i    a5, a3, 4         # a5 = B.y | a5 = B.y
	mull    a4, a4, a5        # a4 = A.y * B.y | a4 = A.y * B.y
	add.n   a6, a6, a4        # a6 = A.x*B.x + A.y*B.y | a6 = A.x*B.x + A.y*B.y
	
	l32i    a4, a2, 8         # a4 = A.z | a4 = A.z
	l32i    a5, a3, 8         # a5 = B.z | a5 = B.z
	mull    a4, a4, a5        # a4 = A.z * B.z | a4 = A.z * B.z
	add.n   a6, a6, a4        # a6 = A.x*B.x + A.y*B.y + A.z*B.z | a6 = full dot product
	
	mov.n   a2, a6            # a2 = результат (возвращаемое значение) | a2 = result (return value)
	ret                       # Возврат | Return
	
	.size vec3_dot, . - vec3_dot  # Размер функции | Function size

# ------------------------------------------------------------
# vec3_add — сложение двух 3D-векторов
# Вход: a2 = указатель на out, a3 = указатель на A, a4 = указатель на B
# Выход: out = A + B (покоординатно)
# ------------------------------------------------------------
	.align 4
	.global vec3_add          # Делаем символ глобальным | Make symbol global
	.type vec3_add, @function # Тип: функция | Type: function
	
vec3_add:                     # Метка функции | Function label
	l32i    a5, a3, 0         # a5 = A.x | a5 = A.x
	l32i    a6, a4, 0         # a6 = B.x | a6 = B.x
	add.n   a5, a5, a6        # a5 = A.x + B.x | a5 = A.x + B.x
	s32i    a5, a2, 0         # out.x = A.x + B.x | out.x = A.x + B.x
	
	l32i    a5, a3, 4         # a5 = A.y | a5 = A.y
	l32i    a6, a4, 4         # a6 = B.y | a6 = B.y
	add.n   a5, a5, a6        # a5 = A.y + B.y | a5 = A.y + B.y
	s32i    a5, a2, 4         # out.y = A.y + B.y | out.y = A.y + B.y
	
	l32i    a5, a3, 8         # a5 = A.z | a5 = A.z
	l32i    a6, a4, 8         # a6 = B.z | a6 = B.z
	add.n   a5, a5, a6        # a5 = A.z + B.z | a5 = A.z + B.z
	s32i    a5, a2, 8         # out.z = A.z + B.z | out.z = A.z + B.z
	
	ret                       # Возврат | Return
	
	.size vec3_add, . - vec3_add  # Размер функции | Function size
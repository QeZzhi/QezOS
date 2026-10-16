# ============================================================
# fixed_point.S — ассемблерные функции fixed-point математики
# Умножение и деление чисел с фиксированной точкой (16.16).
# fixed_point.S — assembly fixed-point math functions
# Multiplication and division of fixed-point numbers (16.16).
# ============================================================

	.section .text      # Секция кода | Code section
	.align 4            # Выравнивание по 4 байта | Align to 4 bytes

# ------------------------------------------------------------
# fixed_mul — умножение fixed-point чисел (16.16)
# Вход: a2 = первое число, a3 = второе число
# Выход: a2 = (a2 * a3) >> 16
# ------------------------------------------------------------
	.global fixed_mul          # Делаем символ глобальным | Make symbol global
	.type fixed_mul, @function # Тип: функция | Type: function
	
fixed_mul:                     # Метка функции | Function label
	mull    a2, a2, a3        # a2 = a2 * a3 (32-битное умножение) | a2 = a2 * a3 (32-bit multiply)
	srai    a2, a2, 16        # a2 = a2 >> 16 (сдвиг на 16 бит) | a2 = a2 >> 16 (shift by 16 bits)
	ret                       # Возврат | Return
	
	.size fixed_mul, . - fixed_mul  # Размер функции | Function size

# ------------------------------------------------------------
# fixed_div — деление fixed-point чисел (16.16)
# Вход: a2 = делимое, a3 = делитель
# Выход: a2 = (a2 << 16) / a3
# ------------------------------------------------------------
	.align 4
	.global fixed_div          # Делаем символ глобальным | Make symbol global
	.type fixed_div, @function # Тип: функция | Type: function
	
fixed_div:                     # Метка функции | Function label
	slli    a2, a2, 16        # a2 = a2 << 16 (сдвиг влево на 16) | a2 = a2 << 16 (shift left by 16)
	quos    a2, a2, a3        # a2 = a2 / a3 (знаковое деление) | a2 = a2 / a3 (signed divide)
	ret                       # Возврат | Return
	
	.size fixed_div, . - fixed_div  # Размер функции | Function size
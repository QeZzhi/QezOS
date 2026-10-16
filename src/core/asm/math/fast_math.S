# ============================================================
# fast_math.S — ассемблерные базовые математические функции
# Модуль, минимум, максимум — быстро, через инструкции Xtensa.
# fast_math.S — assembly basic math functions
# Absolute, min, max — fast, via Xtensa instructions.
# ============================================================

	.section .text      # Секция кода | Code section
	.align 4            # Выравнивание по 4 байта | Align to 4 bytes

# ------------------------------------------------------------
# fast_abs_int — модуль числа
# Вход: a2 = число
# Выход: a2 = |a2|
# ------------------------------------------------------------
	.global fast_abs_int          # Делаем символ глобальным | Make symbol global
	.type fast_abs_int, @function # Тип: функция | Type: function
	
fast_abs_int:                     # Метка функции | Function label
	abs     a2, a2                # a2 = |a2| (модуль) | a2 = |a2| (absolute value)
	ret                           # Возврат | Return
	
	.size fast_abs_int, . - fast_abs_int  # Размер функции | Function size

# ------------------------------------------------------------
# fast_min_int — минимум из двух чисел
# Вход: a2 = первое число, a3 = второе число
# Выход: a2 = min(a2, a3)
# ------------------------------------------------------------
	.align 4
	.global fast_min_int          # Делаем символ глобальным | Make symbol global
	.type fast_min_int, @function # Тип: функция | Type: function
	
fast_min_int:                     # Метка функции | Function label
	min     a2, a2, a3            # a2 = min(a2, a3) | a2 = min(a2, a3)
	ret                           # Возврат | Return
	
	.size fast_min_int, . - fast_min_int  # Размер функции | Function size

# ------------------------------------------------------------
# fast_max_int — максимум из двух чисел
# Вход: a2 = первое число, a3 = второе число
# Выход: a2 = max(a2, a3)
# ------------------------------------------------------------
	.align 4
	.global fast_max_int          # Делаем символ глобальным | Make symbol global
	.type fast_max_int, @function # Тип: функция | Type: function
	
fast_max_int:                     # Метка функции | Function label
	max     a2, a2, a3            # a2 = max(a2, a3) | a2 = max(a2, a3)
	ret                           # Возврат | Return
	
	.size fast_max_int, . - fast_max_int  # Размер функции | Function size
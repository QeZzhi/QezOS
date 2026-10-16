# ============================================================
# synth.S — ассемблерные функции генерации звуковых волн
# Генерирует квадратную и пилообразную волны.
# synth.S — assembly sound wave generation functions
# Generates square and saw waves.
# ============================================================

	.section .text      # Секция кода | Code section
	.align 4            # Выравнивание по 4 байта | Align to 4 bytes

# ------------------------------------------------------------
# square_wave_fast — квадратная волна
# Вход:  a2 = фаза (0-255), a3 = амплитуда
# Выход: a2 = +amplitude (если фаза >= 128) или -amplitude
# ------------------------------------------------------------
	.global square_wave_fast          # Делаем символ глобальным | Make symbol global
	.type square_wave_fast, @function # Тип: функция | Type: function
	
square_wave_fast:                     # Метка функции | Function label
	movi    a4, 128                   # a4 = 128 (половина фазы) | a4 = 128 (half phase)
	bltu    a2, a4, .Lsq_low          # Если фаза < 128 — на .Lsq_low | If phase < 128 — go to .Lsq_low
	mov.n   a2, a3                    # a2 = a3 (положительная амплитуда) | a2 = a3 (positive amplitude)
	ret                               # Возврат | Return
	
.Lsq_low:                             # Фаза >= 128 | Phase >= 128
	neg     a2, a3                    # a2 = -a3 (отрицательная амплитуда) | a2 = -a3 (negative amplitude)
	ret                               # Возврат | Return
	
	.size square_wave_fast, . - square_wave_fast  # Размер функции | Function size

# ------------------------------------------------------------
# saw_wave_fast — пилообразная волна
# Вход:  a2 = фаза (0-255), a3 = амплитуда
# Выход: a2 = (phase - 128) * amplitude / 128
# ------------------------------------------------------------
	.align 4
	.global saw_wave_fast          # Делаем символ глобальным | Make symbol global
	.type saw_wave_fast, @function # Тип: функция | Type: function
	
saw_wave_fast:                     # Метка функции | Function label
	movi    a4, 128                # a4 = 128 (центр) | a4 = 128 (center)
	sub     a2, a2, a4             # a2 = phase - 128 (центрируем) | a2 = phase - 128 (center)
	mull    a2, a2, a3             # a2 = (phase - 128) * amplitude | a2 = (phase - 128) * amplitude
	srai    a2, a2, 7              # a2 = a2 >> 7 (деление на 128) | a2 = a2 >> 7 (divide by 128)
	ret                            # Возврат | Return
	
	.size saw_wave_fast, . - saw_wave_fast  # Размер функции | Function size
# ============================================================
# mixer.S — ассемблерные функции микширования аудио
# Смешивает два сэмпла или два буфера (усреднение).
# mixer.S — assembly audio mixing functions
# Mixes two samples or two buffers (averaging).
# ============================================================

	.section .text      # Секция кода | Code section
	.align 4            # Выравнивание по 4 байта | Align to 4 bytes

# ------------------------------------------------------------
# mix_audio_fast — смешать два сэмпла
# Вход:  a2 = сэмпл A, a3 = сэмпл B
# Выход: a2 = (A + B) / 2
# ------------------------------------------------------------
	.global mix_audio_fast          # Делаем символ глобальным | Make symbol global
	.type mix_audio_fast, @function # Тип: функция | Type: function

mix_audio_fast:                     # Метка функции | Function label
	add.n   a2, a2, a3              # a2 = a2 + a3 (сложение) | a2 = a2 + a3 (add)
	srai    a2, a2, 1               # a2 = a2 >> 1 (деление на 2) | a2 = a2 >> 1 (div by 2)
	ret                             # Возврат | Return
	
	.size mix_audio_fast, . - mix_audio_fast  # Размер функции | Function size

# ------------------------------------------------------------
# mix_buffer_fast — смешать два буфера
# Вход:  a2 = указатель на out, a3 = указатель на in, a4 = размер
# Выход: out[i] = (out[i] + in[i]) / 2
# ------------------------------------------------------------
	.align 4
	.global mix_buffer_fast          # Делаем символ глобальным | Make symbol global
	.type mix_buffer_fast, @function # Тип: функция | Type: function
	
mix_buffer_fast:                     # Метка функции | Function label
	beqz    a4, .Lmix_done          # Если размер == 0 — выход | If size == 0 — exit
	bltz    a4, .Lmix_done          # Если размер < 0 — выход | If size < 0 — exit
	
.Lmix_loop:                         # Начало цикла | Loop start
	l32i    a5, a2, 0               # a5 = out[i] | a5 = out[i]
	l32i    a6, a3, 0               # a6 = in[i] | a6 = in[i]
	add.n   a5, a5, a6              # a5 = a5 + a6 | a5 = a5 + a6
	srai    a5, a5, 1               # a5 = a5 >> 1 | a5 = a5 >> 1
	s32i    a5, a2, 0               # out[i] = a5 | out[i] = a5
	
	addi    a2, a2, 4               # out++ (следующий int) | out++ (next int)
	addi    a3, a3, 4               # in++ | in++
	addi    a4, a4, -1              # size-- | size--
	bnez    a4, .Lmix_loop          # Если size != 0 — повтор | If size != 0 — repeat
	
.Lmix_done:                         # Конец | End
	ret                             # Возврат | Return
	
	.size mix_buffer_fast, . - mix_buffer_fast  # Размер функции | Function size
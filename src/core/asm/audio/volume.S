# ============================================================
# volume.S — ассемблерные функции управления громкостью
# Применяет громкость к сэмплу или буферу.
# volume.S — assembly volume control functions
# Applies volume to a sample or buffer.
# ============================================================

	.section .text      # Секция кода | Code section
	.align 4            # Выравнивание по 4 байта | Align to 4 bytes

# ------------------------------------------------------------
# apply_volume_fast — применить громкость к одному сэмплу
# Вход:  a2 = сэмпл, a3 = громкость (0-255)
# Выход: a2 = сэмпл * громкость / 255
# ------------------------------------------------------------
	.global apply_volume_fast          # Делаем символ глобальным | Make symbol global
	.type apply_volume_fast, @function # Тип: функция | Type: function
	
apply_volume_fast:                     # Метка функции | Function label
	mull    a2, a2, a3                # a2 = сэмпл * громкость | a2 = sample * volume
	movi    a4, 255                   # a4 = 255 (максимум) | a4 = 255 (max)
	quos    a2, a2, a4                # a2 = a2 / 255 (знаковое деление) | a2 = a2 / 255 (signed divide)
	ret                               # Возврат | Return
	
	.size apply_volume_fast, . - apply_volume_fast  # Размер функции | Function size

# ------------------------------------------------------------
# apply_volume_buffer_fast — применить громкость к буферу
# Вход:  a2 = указатель на буфер, a3 = размер, a4 = громкость
# Выход: buffer[i] = buffer[i] * volume / 255
# ------------------------------------------------------------
	.align 4
	.global apply_volume_buffer_fast          # Делаем символ глобальным | Make symbol global
	.type apply_volume_buffer_fast, @function # Тип: функция | Type: function
	
apply_volume_buffer_fast:                     # Метка функции | Function label
	beqz    a3, .Lvol_done                    # Если размер == 0 — выход | If size == 0 — exit
	bltz    a3, .Lvol_done                    # Если размер < 0 — выход | If size < 0 — exit
	
	movi    a5, 255                           # a5 = 255 (максимум) | a5 = 255 (max)
	
.Lvol_loop:                                   # Начало цикла | Loop start
	l32i    a6, a2, 0                         # a6 = buffer[i] | a6 = buffer[i]
	mull    a6, a6, a4                        # a6 = buffer[i] * громкость | a6 = buffer[i] * volume
	quos    a6, a6, a5                        # a6 = a6 / 255 | a6 = a6 / 255
	s32i    a6, a2, 0                         # buffer[i] = a6 | buffer[i] = a6
	
	addi    a2, a2, 4                         # buffer++ (следующий int) | buffer++ (next int)
	addi    a3, a3, -1                        # size-- | size--
	bnez    a3, .Lvol_loop                    # Если size != 0 — повтор | If size != 0 — repeat
	
.Lvol_done:                                   # Конец | End
	ret                                       # Возврат | Return
	
	.size apply_volume_buffer_fast, . - apply_volume_buffer_fast  # Размер функции | Function size
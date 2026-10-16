# ============================================================
# memmove.S — ассемблерная функция перемещения памяти
# Копирует n байт с защитой от перекрытия областей.
# memmove.S — assembly memory move function
# Copies n bytes with overlap protection.
# ============================================================

	.section .text      # Секция кода | Code section
	.align 4            # Выравнивание по 4 байта | Align to 4 bytes

# ------------------------------------------------------------
# memmove_fast — переместить n байт (безопасно при перекрытии)
# Вход: a2 = dest, a3 = src, a4 = n
# Выход: a2 = dest
# ------------------------------------------------------------
	.global memmove_fast          # Делаем символ глобальным | Make symbol global
	.type memmove_fast, @function # Тип: функция | Type: function
	
memmove_fast:                     # Метка функции | Function label
	mov     a5, a2            # a5 = dest (сохраняем для возврата) | a5 = dest (save for return)
	beq     a2, a3, .Ldone    # Если dest == src — ничего не делать | If dest == src — do nothing
	
	bltu    a2, a3, .Lforward # Если dest < src — копировать вперёд | If dest < src — copy forward
	
	# dest > src: копируем с КОНЦА, чтобы не затереть src
	# dest > src: copy from END, so we don't overwrite src
	add.n   a2, a2, a4        # a2 = dest + n (конец dest) | a2 = dest + n (end of dest)
	add.n   a3, a3, a4        # a3 = src + n (конец src) | a3 = src + n (end of src)
.Lback:                           # Цикл назад | Backward loop
	beqz    a4, .Ldone        # Если n == 0 — конец | If n == 0 — done
	addi    a2, a2, -1        # dest-- | dest--
	addi    a3, a3, -1        # src-- | src--
	l8ui    a6, a3, 0         # a6 = *src (читаем 1 байт) | a6 = *src (read 1 byte)
	s8i     a6, a2, 0         # *dest = a6 (пишем 1 байт) | *dest = a6 (write 1 byte)
	addi    a4, a4, -1        # n-- | n--
	j       .Lback            # Повтор | Repeat
	
.Lforward:                        # dest < src: копируем с начала | dest < src: copy from start
	beqz    a4, .Ldone        # Если n == 0 — конец | If n == 0 — done

.Lfwd:                            # Цикл вперёд | Forward loop
	l8ui    a6, a3, 0         # a6 = *src | a6 = *src
	s8i     a6, a2, 0         # *dest = a6 | *dest = a6
	addi    a2, a2, 1         # dest++ | dest++
	addi    a3, a3, 1         # src++ | src++
	addi    a4, a4, -1        # n-- | n--
	bnez    a4, .Lfwd         # Если n != 0 — повтор | If n != 0 — repeat
	
.Ldone:                           # Конец | Done
	mov.n   a2, a5            # a2 = dest (возвращаем) | a2 = dest (return)
	ret                       # Возврат | Return
	
	.size memmove_fast, . - memmove_fast  # Размер функции | Function size
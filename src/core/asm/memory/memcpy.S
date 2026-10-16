# ============================================================
# memcpy.S — ассемблерная функция копирования памяти
# Копирует n байт из src в dest. Оптимизирована: по 4 байта.
# memcpy.S — assembly memory copy function
# Copies n bytes from src to dest. Optimized: 4 bytes at a time.
# ============================================================

	.section .text      # Секция кода | Code section
	.align 4            # Выравнивание по 4 байта | Align to 4 bytes

# ------------------------------------------------------------
# memcpy_fast — копировать n байт
# Вход: a2 = dest, a3 = src, a4 = n (размер в байтах)
# Выход: a2 = dest (как в стандартном memcpy)
# ------------------------------------------------------------
	.global memcpy_fast          # Делаем символ глобальным | Make symbol global
	.type memcpy_fast, @function # Тип: функция | Type: function
	
memcpy_fast:                     # Метка функции | Function label
	mov.n   a5, a2            # a5 = dest (сохраняем для возврата) | a5 = dest (save for return)
	movi    a6, 4             # a6 = 4 (размер блока для копирования) | a6 = 4 (block size for copy)
	
.Lloop4:                         # Цикл по 4 байта | 4-byte loop
	bltu    a4, a6, .Ltail    # Если n < 4 — на хвост | If n < 4 — go to tail
	l32i    a7, a3, 0         # a7 = src (читаем 4 байта) | a7 = src (read 4 bytes)
	s32i    a7, a2, 0         # dest = a7 (пишем 4 байта) | dest = a7 (write 4 bytes)
	addi    a3, a3, 4         # src += 4 | src += 4
	addi    a2, a2, 4         # dest += 4 | dest += 4
	addi    a4, a4, -4        # n -= 4 | n -= 4
	j       .Lloop4           # Повтор | Repeat
	
.Ltail:                          # Хвост (меньше 4 байт) | Tail (less than 4 bytes)
	beqz    a4, .Ldone        # Если n == 0 — конец | If n == 0 — done
.Lloop1:                         # Цикл по 1 байту | 1-byte loop
	l8ui    a7, a3, 0         # a7 = src (читаем 1 байт) | a7 = src (read 1 byte)
	s8i     a7, a2, 0         # dest = a7 (пишем 1 байт) | dest = a7 (write 1 byte)
	addi    a3, a3, 1         # src++ | src++
	addi    a2, a2, 1         # dest++ | dest++
	addi    a4, a4, -1        # n-- | n--
	bnez    a4, .Lloop1       # Если n != 0 — повтор | If n != 0 — repeat
	
.Ldone:                          # Конец | Done
	mov.n   a2, a5            # a2 = dest (возвращаем оригинал) | a2 = dest (return original)
	ret                       # Возврат | Return
	
	.size memcpy_fast, . - memcpy_fast  # Размер функции | Function size
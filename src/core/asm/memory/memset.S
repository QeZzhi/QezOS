# ============================================================
# memset.S — ассемблерная функция заполнения памяти
# Заполняет n байт одним значением. Оптимизирована: по 4 байта.
# memset.S — assembly memory set function
# Fills n bytes with one value. Optimized: 4 bytes at a time.
# ============================================================

	.section .text      # Секция кода | Code section
	.align 4            # Выравнивание по 4 байта | Align to 4 bytes

# ------------------------------------------------------------
# memset_fast — заполнить n байт значением value
# Вход: a2 = dest, a3 = value (байт), a4 = n (размер в байтах)
# Выход: a2 = dest
# ------------------------------------------------------------
	.global memset_fast          # Делаем символ глобальным | Make symbol global
	.type memset_fast, @function # Тип: функция | Type: function
	
memset_fast:                     # Метка функции | Function label
	mov.n   a5, a2            # a5 = dest (сохраняем для возврата) | a5 = dest (save for return)
	
	extui   a3, a3, 0, 8      # a3 = value & 0xFF (только младший байт) | a3 = value & 0xFF (only low byte)
	
	movi    a8, 0x01010101    # a8 = 0x01010101 (магия для копирования байта) | a8 = 0x01010101 (magic for byte spreading)
	mull    a3, a3, a8        # a3 = value * 0x01010101 (байт во всех 4 позициях) | a3 = value * 0x01010101 (byte in all 4 positions)
	
	movi    a8, 4             # a8 = 4 (размер блока) | a8 = 4 (block size)
.Lloop4:                          # Цикл по 4 байта | 4-byte loop
	bltu    a4, a8, .Ltail    # Если n < 4 — на хвост | If n < 4 — go to tail
	s32i    a3, a2, 0         # Записать 4 байта (все = value) | Write 4 bytes (all = value)
	addi    a2, a2, 4         # dest += 4 | dest += 4
	addi    a4, a4, -4        # n -= 4 | n -= 4
	j       .Lloop4           # Повтор | Repeat
	
.Ltail:                           # Хвост (меньше 4 байт) | Tail (less than 4 bytes)
	beqz    a4, .Ldone        # Если n == 0 — конец | If n == 0 — done
.Lloop1:                          # Цикл по 1 байту | 1-byte loop
	s8i     a3, a2, 0         # Записать 1 байт | Write 1 byte
	addi    a2, a2, 1         # dest++ | dest++
	addi    a4, a4, -1        # n-- | n--
	bnez    a4, .Lloop1       # Если n != 0 — повтор | If n != 0 — repeat
	
.Ldone:                           # Конец | Done
	mov.n   a2, a5            # a2 = dest (возвращаем) | a2 = dest (return)
	ret                       # Возврат | Return
	
	.size memset_fast, . - memset_fast  # Размер функции | Function size
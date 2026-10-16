# ============================================================
# memcmp.S — ассемблерная функция сравнения памяти
# Сравнивает n байт двух областей памяти.
# memcmp.S — assembly memory comparison function
# Compares n bytes of two memory regions.
# ============================================================

	.section .text      # Секция кода | Code section
	.align 4            # Выравнивание по 4 байта | Align to 4 bytes

# ------------------------------------------------------------
# memcmp_fast — сравнить n байт
# Вход: a2 = указатель на A, a3 = указатель на B, a4 = размер
# Выход: a2 = 0 (равны), -1 (A < B), 1 (A > B)
# ------------------------------------------------------------
	.global memcmp_fast          # Делаем символ глобальным | Make symbol global
	.type memcmp_fast, @function # Тип: функция | Type: function
	
memcmp_fast:                     # Метка функции | Function label
	beqz    a4, .Lequal       # Если размер == 0 — равны | If size == 0 — equal
	
.Lloop:                          # Начало цикла | Loop start
	l8ui    a5, a2, 0         # a5 = A[i] (читаем 1 байт) | a5 = A[i] (read 1 byte)
	l8ui    a6, a3, 0         # a6 = B[i] (читаем 1 байт) | a6 = B[i] (read 1 byte)
	bltu    a5, a6, .Lless    # Если A[i] < B[i] — на .Lless | If A[i] < B[i] — go to .Lless
	bltu    a5, a6, .Lgreater # ← БАГ: должно быть bgtu (A[i] > B[i]) | BUG: should be bgtu (A[i] > B[i])
	addi    a2, a2, 1         # A++ | A++
	addi    a3, a3, 1         # B++ | B++
	addi    a4, a4, -1        # размер-- | size--
	bnez    a4, .Lloop        # Если размер != 0 — повтор | If size != 0 — repeat
	
.Lequal:                         # Равны | Equal
	movi    a2, 0             # a2 = 0 (равны) | a2 = 0 (equal)
	ret                       # Возврат | Return
	
.Lless:                          # A < B | A < B
	movi    a2, -1            # a2 = -1 (A < B) | a2 = -1 (A < B)
	ret                       # Возврат | Return
	
.Lgreater:                       # A > B | A > B
	movi    a2, 1             # a2 = 1 (A > B) | a2 = 1 (A > B)
	ret                       # Возврат | Return
	
	.size memcmp_fast, . - memcmp_fast  # Размер функции | Function size
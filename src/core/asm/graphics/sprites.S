# ============================================================
# sprites.S — ассемблерная функция рисования спрайтов
# Рисует спрайт (картинку) в указанной позиции.
# sprites.S — assembly sprite drawing function
# Draws a sprite (image) at the specified position.
# ============================================================

	.section .text      # Секция кода | Code section
	.align 4            # Выравнивание по 4 байта | Align to 4 bytes

# ------------------------------------------------------------
# draw_sprite_fast — нарисовать спрайт
# Вход: a2 = x, a3 = y, a4 = указатель на данные, a5 = ширина, a6 = высота
# Спрайт — массив RGB565 пикселей (uint16_t)
# Проверки: ширина > 0, высота > 0
# ------------------------------------------------------------
	.global draw_sprite_fast          # Делаем символ глобальным | Make symbol global
	.type draw_sprite_fast, @function # Тип: функция | Type: function
	
draw_sprite_fast:                     # Метка функции | Function label
	beqz    a5, .Lsprite_done     # Если ширина == 0 — выход | If width == 0 — exit
	bltz    a5, .Lsprite_done     # Если ширина < 0 — выход | If width < 0 — exit
	beqz    a6, .Lsprite_done     # Если высота == 0 — выход | If height == 0 — exit
	bltz    a6, .Lsprite_done     # Если высота < 0 — выход | If height < 0 — exit
	
	mov.n   a7, a2                # a7 = x (сохраняем) | a7 = x (save)
	mov.n   a8, a3                # a8 = y (сохраняем) | a8 = y (save)
	
	movi    a9, 135               # a9 = 135 (высота экрана) | a9 = 135 (screen height)
	mull    a9, a3, a9            # a9 = y * 135 | a9 = y * 135
	add.n   a9, a9, a2            # a9 = y*135 + x | a9 = y*135 + x
	slli    a9, a9, 1             # a9 = (y*135 + x) * 2 | a9 = (y*135 + x) * 2
	
	movi    a10, 0x3C000000       # a10 = адрес framebuffer | a10 = framebuffer address
	add.n   a10, a10, a9          # a10 = framebuffer + offset | a10 = framebuffer + offset
	
	movi    a11, 270              # a11 = 270 (шаг строки = 135 * 2) | a11 = 270 (row stride = 135 * 2)
	
.Lsprite_row:                         # Начало строки спрайта | Sprite row start
	mov.n   a12, a10              # a12 = адрес начала строки | a12 = row start address
	mov.n   a13, a5               # a13 = ширина (счётчик) | a13 = width (counter)
	
.Lsprite_col:                         # Начало столбца спрайта | Sprite column start
	l16ui   a14, a4, 0            # a14 = пиксель спрайта (2 байта) | a14 = sprite pixel (2 bytes)
	s16i    a14, a12, 0           # Записать пиксель на экран | Write pixel to screen
	addi    a4, a4, 2             # sprite++ (следующий пиксель) | sprite++ (next pixel)
	addi    a12, a12, 2           # screen++ (следующий пиксель) | screen++ (next pixel)
	addi    a13, a13, -1          # ширина-- | width--
	bnez    a13, .Lsprite_col     # Если ширина != 0 — повтор | If width != 0 — repeat
	
	add.n   a10, a10, a11         # a10 += 270 (следующая строка) | a10 += 270 (next row)
	addi    a6, a6, -1            # высота-- | height--
	bnez    a6, .Lsprite_row      # Если высота != 0 — повтор | If height != 0 — repeat
	
.Lsprite_done:                        # Выход | Exit
	ret                           # Возврат | Return
	
	.size draw_sprite_fast, . - draw_sprite_fast  # Размер функции | Function size
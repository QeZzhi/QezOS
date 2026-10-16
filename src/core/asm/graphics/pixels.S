# ============================================================
# pixels.S — ассемблерные функции рисования пикселей и линий
# Рисует пиксель и горизонтальную линию на экране.
# pixels.S — assembly pixel and line drawing functions
# Draws a pixel and a horizontal line on screen.
# ============================================================

	.section .text      # Секция кода | Code section
	.align 4            # Выравнивание по 4 байта | Align to 4 bytes

# ------------------------------------------------------------
# draw_pixel_fast — нарисовать пиксель
# Вход: a2 = x, a3 = y, a4 = цвет
# Проверки: x >= 0, y >= 0, x < 240, y < 135
# Адрес: framebuffer + (y * 135 + x) * 2
# ------------------------------------------------------------
	.global draw_pixel_fast          # Делаем символ глобальным | Make symbol global
	.type draw_pixel_fast, @function # Тип: функция | Type: function
	
draw_pixel_fast:                     # Метка функции | Function label
	bltz    a2, .Ldone            # Если x < 0 — выход | If x < 0 — exit
	bltz    a3, .Ldone            # Если y < 0 — выход | If y < 0 — exit
	bgeu    a2, a5, .Ldone        # Если x >= a5 — выход (a5 = ???) | If x >= a5 — exit (a5 = ???)
	movi    a5, 240               # a5 = 240 (ширина экрана) | a5 = 240 (screen width)
	bgeu    a3, a5, .Ldone        # Если y >= 240 — выход (ОШИБКА: надо 135) | If y >= 240 — exit (BUG: should be 135)
	
	movi    a5, 135               # a5 = 135 (высота экрана) | a5 = 135 (screen height)
	mull    a5, a3, a5            # a5 = y * 135 | a5 = y * 135
	add.n   a5, a5, a2            # a5 = y*135 + x | a5 = y*135 + x
	slli    a5, a5, 1             # a5 = (y*135 + x) * 2 (RGB565) | a5 = (y*135 + x) * 2 (RGB565)
	
	movi    a6, 0x3C000000        # a6 = адрес framebuffer | a6 = framebuffer address
	add.n   a6, a6, a5            # a6 = framebuffer + offset | a6 = framebuffer + offset
	
	s16i    a4, a6, 0             # Записать цвет (2 байта) | Write color (2 bytes)
	
.Ldone:                               # Выход | Exit
	ret                           # Возврат | Return
	
	.size draw_pixel_fast, . - draw_pixel_fast  # Размер функции | Function size

# ------------------------------------------------------------
# draw_hline_fast — нарисовать горизонтальную линию
# Вход: a2 = x, a3 = y, a4 = длина, a5 = цвет
# Проверки: x >= 0, y >= 0, длина > 0
# ------------------------------------------------------------
	.align 4
	.global draw_hline_fast          # Делаем символ глобальным | Make symbol global
	.type draw_hline_fast, @function # Тип: функция | Type: function
	
draw_hline_fast:                     # Метка функции | Function label
	bltz    a2, .Lhline_done      # Если x < 0 — выход | If x < 0 — exit
	bltz    a3, .Lhline_done      # Если y < 0 — выход | If y < 0 — exit
	beqz    a4, .Lhline_done      # Если длина == 0 — выход | If length == 0 — exit
	bltz    a4, .Lhline_done      # Если длина < 0 — выход | If length < 0 — exit
	
	movi    a6, 135               # a6 = 135 (высота экрана) | a6 = 135 (screen height)
	mull    a6, a3, a6            # a6 = y * 135 | a6 = y * 135
	add.n   a6, a6, a2            # a6 = y*135 + x | a6 = y*135 + x
	slli    a6, a6, 1             # a6 = (y*135 + x) * 2 | a6 = (y*135 + x) * 2
	
	movi    a7, 0x3C000000        # a7 = адрес framebuffer | a7 = framebuffer address
	add.n   a7, a7, a6            # a7 = framebuffer + offset | a7 = framebuffer + offset
	
.Lhline_loop:                         # Начало цикла | Loop start
	s16i    a5, a7, 0             # Записать цвет пикселя | Write pixel color
	addi    a7, a7, 2             # a7 += 2 (следующий пиксель) | a7 += 2 (next pixel)
	addi    a4, a4, -1            # длина-- | length--
	bnez    a4, .Lhline_loop      # Если длина != 0 — повтор | If length != 0 — repeat
	
.Lhline_done:                         # Выход | Exit
	ret                           # Возврат | Return
	
	.size draw_hline_fast, . - draw_hline_fast  # Размер функции | Function size
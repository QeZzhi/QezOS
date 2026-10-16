# ============================================================
# framebuffer.S — ассемблерные функции заливки экрана
# Заливает весь экран одним цветом.
# framebuffer.S — assembly screen fill functions
# Fills the entire screen with one color.
# ============================================================

	.section .text      # Секция кода | Code section
	.align 4            # Выравнивание по 4 байта | Align to 4 bytes

# ------------------------------------------------------------
# fill_screen_fast — залить экран цветом
# Вход: a2 = цвет (uint16_t)
# Регистр 0x3C000000 — начало framebuffer
# Размер: 32400 пикселей (240 * 135)
# ------------------------------------------------------------
	.global fill_screen_fast          # Делаем символ глобальным | Make symbol global
	.type fill_screen_fast, @function # Тип: функция | Type: function
	
fill_screen_fast:                     # Метка функции | Function label
	movi    a3, 0x3C000000        # a3 = адрес начала framebuffer | a3 = framebuffer start address
	movi    a4, 32400             # a4 = 32400 (240 * 135 пикселей) | a4 = 32400 (240 * 135 pixels)
	movi    a5, 0                 # a5 = 0 (счётчик) | a5 = 0 (counter)
	
.Lfill_loop:                          # Начало цикла | Loop start
	s16i    a2, a3, 0             # Записать цвет (2 байта) по адресу | Write color (2 bytes) at address
	addi    a3, a3, 2             # a3 += 2 (следующий пиксель, RGB565) | a3 += 2 (next pixel, RGB565)
	addi    a5, a5, 1             # a5 += 1 (счётчик++) | a5 += 1 (counter++)
	bltu    a5, a4, .Lfill_loop   # Если a5 < a4 — повтор | If a5 < a4 — repeat
	ret                           # Возврат | Return
	
	.size fill_screen_fast, . - fill_screen_fast  # Размер функции | Function size

# ------------------------------------------------------------
# clear_screen_fast — очистить экран (залить чёрным)
# Просто вызывает fill_screen_fast с цветом 0
# ------------------------------------------------------------
	.align 4
	.global clear_screen_fast          # Делаем символ глобальным | Make symbol global
	.type clear_screen_fast, @function # Тип: функция | Type: function
	
clear_screen_fast:                     # Метка функции | Function label
	movi     a2, 0                 # a2 = 0 (чёрный цвет) | a2 = 0 (black color)
	j       fill_screen_fast       # Прыжок на fill_screen_fast | Jump to fill_screen_fast
	
	.size clear_screen_fast, . - clear_screen_fast  # Размер функции | Function size
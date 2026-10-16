// ============================================================
// asm_graphics.h — заголовок ассемблерных функций графики
// Быстрые функции для рисования пикселей, линий, спрайтов.
// asm_graphics.h — assembly graphics functions header
// Fast functions for drawing pixels, lines, sprites.
// ============================================================

#ifndef ASM_GRAPHICS_H // Если ASM_GRAPHICS_H ещё не определён | If ASM_GRAPHICS_H is not defined yet
#define ASM_GRAPHICS_H // Определяем ASM_GRAPHICS_H | Define ASM_GRAPHICS_H

#include <stdint.h> // Нужен тип uint16_t | Need uint16_t type

#ifdef __cplusplus // Если компилируется как C++ | If compiled as C++
extern "C" { // Отключаем искажение имён | Disable name mangling
#endif

// ------------------------------------------------------------
// Рисование пикселей и линий
// ------------------------------------------------------------

// Нарисовать пиксель в (x, y) | Draw pixel at (x, y)
void draw_pixel_fast(int x, int y, uint16_t color);

// Нарисовать горизонтальную линию | Draw horizontal line
void draw_hline_fast(int x, int y, int w, uint16_t color);

// Нарисовать вертикальную линию | Draw vertical line
void draw_vline_fast(int x, int y, int h, uint16_t color);

// ------------------------------------------------------------
// Спрайты и заливка
// ------------------------------------------------------------

// Нарисовать спрайт (массив пикселей) | Draw sprite (pixel array)
void draw_sprite_fast(int x, int y, const uint16_t* data, int w, int h);

// Залить весь экран цветом | Fill entire screen with color
void fill_screen_fast(uint16_t color);

// Очистить экран (залить чёрным) | Clear screen (fill black)
void clear_screen_fast(void);

#ifdef __cplusplus // Если компилируется как C++ | If compiled as C++
} // Закрываем extern "C" | Close extern "C"
#endif

#endif // Конец include guard | End of include guard
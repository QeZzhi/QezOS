// ============================================================
// GraphicsCore.cpp — обёртка над ассемблерной графикой
// Класс GraphicsCore вызывает asm_graphics.h из C++.
// GraphicsCore.cpp — wrapper over assembly graphics
// Class GraphicsCore calls asm_graphics.h from C++.
// ============================================================

#include "GraphicsCore.h"          // Объявление класса GraphicsCore | GraphicsCore class declaration
#include "core/inc/asm_graphics.h" // Ассемблерные функции графики | Assembly graphics functions

namespace core { // Пространство имён core | Namespace core

// ------------------------------------------------------------
// GraphicsCore::init — инициализировать графику
// Очищает экран чёрным при старте
// ------------------------------------------------------------
void GraphicsCore::init() { // Инициализация | Init
    clear(0x0000); // Очищаем экран чёрным | Clear screen with black
}

// ------------------------------------------------------------
// GraphicsCore::clear — очистить экран цветом
// ------------------------------------------------------------
void GraphicsCore::clear(uint16_t color) { // Очистка | Clear
    fill_screen_fast(color); // Вызываем ассемблерную функцию | Call assembly function
}

// ------------------------------------------------------------
// GraphicsCore::drawPixel — нарисовать пиксель
// ------------------------------------------------------------
void GraphicsCore::drawPixel(int x, int y, uint16_t color) { // Пиксель | Pixel
    draw_pixel_fast(x, y, color); // Вызываем ассемблерную функцию | Call assembly function
}

// ------------------------------------------------------------
// GraphicsCore::drawHLine — нарисовать горизонтальную линию
// ------------------------------------------------------------
void GraphicsCore::drawHLine(int x, int y, int w, uint16_t color) { // Горизонтальная линия | Horizontal line
    draw_hline_fast(x, y, w, color); // Вызываем ассемблерную функцию | Call assembly function
}

// ------------------------------------------------------------
// GraphicsCore::drawVLine — нарисовать вертикальную линию
// ------------------------------------------------------------
void GraphicsCore::drawVLine(int x, int y, int h, uint16_t color) { // Вертикальная линия | Vertical line
    draw_vline_fast(x, y, h, color); // Вызываем ассемблерную функцию | Call assembly function
}

// ------------------------------------------------------------
// GraphicsCore::drawSprite — нарисовать спрайт
// ------------------------------------------------------------
void GraphicsCore::drawSprite(int x, int y, const uint16_t* data, int w, int h) { // Спрайт | Sprite
    draw_sprite_fast(x, y, data, w, h); // Вызываем ассемблерную функцию | Call assembly function
}

// ------------------------------------------------------------
// GraphicsCore::fill — залить экран цветом
// То же самое, что clear, но с другим именем
// ------------------------------------------------------------
void GraphicsCore::fill(uint16_t color) { // Заливка | Fill
    fill_screen_fast(color); // Вызываем ассемблерную функцию | Call assembly function
}

} // Конец namespace core | End of namespace core
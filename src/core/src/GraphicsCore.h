// ============================================================
// GraphicsCore.h — заголовок обёртки над ассемблерной графикой
// Класс GraphicsCore вызывает asm_graphics.h из C++.
// GraphicsCore.h — wrapper header over assembly graphics
// Class GraphicsCore calls asm_graphics.h from C++.
// ============================================================

#ifndef GRAPHICS_CORE_H // Если GRAPHICS_CORE_H ещё не определён | If GRAPHICS_CORE_H is not defined yet
#define GRAPHICS_CORE_H // Определяем GRAPHICS_CORE_H | Define GRAPHICS_CORE_H

#include <cstdint> // Нужен тип uint16_t | Need uint16_t type

namespace core { // Пространство имён core | Namespace core

// ------------------------------------------------------------
// GraphicsCore — статический класс-обёртка над asm_graphics.h
// Все методы статические — объект создавать не надо
// ------------------------------------------------------------
class GraphicsCore { // Класс GraphicsCore | Class GraphicsCore
public: // Публичные методы | Public methods
    
    // Инициализировать графику (очистить экран) | Initialize graphics (clear screen)
    static void init();
    
    // Очистить экран цветом | Clear screen with color
    static void clear(uint16_t color);
    
    // Нарисовать пиксель | Draw pixel
    static void drawPixel(int x, int y, uint16_t color);
    
    // Нарисовать горизонтальную линию | Draw horizontal line
    static void drawHLine(int x, int y, int w, uint16_t color);
    
    // Нарисовать вертикальную линию | Draw vertical line
    static void drawVLine(int x, int y, int h, uint16_t color);
    
    // Нарисовать спрайт | Draw sprite
    static void drawSprite(int x, int y, const uint16_t* data, int w, int h);
    
    // Залить экран цветом | Fill screen with color
    static void fill(uint16_t color);
};

} // Конец namespace core | End of namespace core

#endif // Конец include guard | End of include guard
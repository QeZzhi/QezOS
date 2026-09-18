#ifndef GRAPHICS_CORE_H
#define GRAPHICS_CORE_H

#include <cstdint>

namespace core {

class GraphicsCore {
public:
    static void init();
    static void clear(uint16_t color);
    static void drawPixel(int x, int y, uint16_t color);
    static void drawHLine(int x, int y, int w, uint16_t color);
    static void drawVLine(int x, int y, int h, uint16_t color);
    static void drawSprite(int x, int y, const uint16_t* data, int w, int h);
    static void fill(uint16_t color);
};

}

#endif
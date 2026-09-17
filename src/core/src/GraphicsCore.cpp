#include "GraphicsCore.h"
#include "core/inc/asm_graphics.h"

namespace core {

void GraphicsCore::init() {
    clear(0x0000);
}

void GraphicsCore::clear(uint16_t color) {
    fill_screen_fast(color);
}

void GraphicsCore::drawPixel(int x, int y, uint16_t color) {
    draw_pixel_fast(x, y, color);
}

void GraphicsCore::drawHLine(int x, int y, int w, uint16_t color) {
    draw_hline_fast(x, y, w, color);
}

void GraphicsCore::drawVLine(int x, int y, int h, uint16_t color) {
    draw_vline_fast(x, y, h, color);
}

void GraphicsCore::drawSprite(int x, int y, const uint16_t* data, int w, int h) {
    draw_sprite_fast(x, y, data, w, h);
}

void GraphicsCore::fill(uint16_t color) {
    fill_screen_fast(color);
}

} // namespace core
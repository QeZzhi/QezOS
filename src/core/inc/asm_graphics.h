#ifndef ASM_GRAPHICS_H
#define ASM_GRAPHICS_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void draw_pixel_fast(int x, int y, uint16_t color);
void draw_hline_fast(int x, int y, int w, uint16_t color);
void draw_vline_fast(int x, int y, int h, uint16_t color);
void draw_sprite_fast(int x, int y, const uint16_t* data, int w, int h);
void fill_screen_fast(uint16_t color);
void clear_screen_fast(void);

#ifdef __cplusplus
}
#endif

#endif
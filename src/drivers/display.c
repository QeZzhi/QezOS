#include "display.h"
#include "core/inc/asm_graphics.h"
#include "m5_shim/m5_shim.h"

void drawBootMenu(const char* options[], int selected, int count) {
    clear();
    qz_lcd_set_text_color(TFT_WHITE);
    qz_lcd_set_cursor(10, 20);
    qz_lcd_println("|-----QezOS Boot Menu-----|");
    
    for (int i = 0; i < count; i++) {
        qz_lcd_set_cursor(20, 60 + i * 30);
        if (i == selected) {
            qz_lcd_set_text_color(TFT_YELLOW);
            qz_lcd_print("> ");
        } else {
            
            qz_lcd_set_text_color(TFT_GRAY);
            qz_lcd_print("  ");
        }
        qz_lcd_println(options[i]);
    }
}

void drawGenericMenu(const char* title, const char* options[], int selected, int count) {
    clear();
    qz_lcd_set_text_color(TFT_WHITE);
    qz_lcd_set_cursor(10, 20);
    qz_lcd_println(title);
    
    for (int i = 0; i < count; i++) {
        qz_lcd_set_cursor(20, 60 + i * 30);
        if (i == selected) {
            qz_lcd_set_text_color(TFT_CYAN);
            qz_lcd_print("> ");
        } else {
            qz_lcd_set_text_color(TFT_GRAY);
            qz_lcd_print("  ");
        }
        qz_lcd_println(options[i]);
    }
}

void clear() {
    fill_screen_fast(0x0000);
}

void setColor(uint16_t color) {
    qz_lcd_fillScreen(color);
}

void printText(const char* text, int x, int y, uint16_t color) {
    qz_lcd_set_text_color(color);
    qz_lcd_set_cursor(x, y);
    qz_lcd_println(text);
}

void printCentered(const char* text, uint16_t color) {
    qz_lcd_set_text_color(color);
    int textWidth = qz_lcd_textWidth(text);
    int textHeight = qz_lcd_fontHeight();
    int x = (135 - textWidth) / 2;
    int y = (240 - textHeight) / 2;
    qz_lcd_set_cursor(x, y);
    qz_lcd_println(text);
}

#include "display.h"
#include "core/inc/asm_graphics.h"

void drawBootMenu(const char* options[], int selected, int count) {
    clear();
    M5.Lcd.setTextColor(TFT_WHITE);
    M5.Lcd.setCursor(10, 20);
    M5.Lcd.println("|-----QezOS Boot Menu-----|");
    
    for (int i = 0; i < count; i++) {
        M5.Lcd.setCursor(20, 60 + i * 30);
        if (i == selected) {
            M5.Lcd.setTextColor(TFT_YELLOW);
            M5.Lcd.print("> ");
        } else {
            M5.Lcd.setTextColor(TFT_GRAY);
            M5.Lcd.print("  ");
        }
        M5.Lcd.println(options[i]);
    }
}

void drawGenericMenu(const char* title, const char* options[], int selected, int count) {
    clear();
    M5.Lcd.setTextColor(TFT_WHITE);
    M5.Lcd.setCursor(10, 20);
    M5.Lcd.println(title);
    
    for (int i = 0; i < count; i++) {
        M5.Lcd.setCursor(20, 60 + i * 30);
        if (i == selected) {
            M5.Lcd.setTextColor(TFT_CYAN);
            M5.Lcd.print("> ");
        } else {
            M5.Lcd.setTextColor(TFT_GRAY);
            M5.Lcd.print("  ");
        }
        M5.Lcd.println(options[i]);
    }
}

void clear() {
    fill_screen_fast(0x0000);
}

void setColor(uint16_t color) {
    M5.Lcd.fillScreen(color);
}

void printText(const char* text, int x, int y, uint16_t color) {
    M5.Lcd.setTextColor(color);
    M5.Lcd.setCursor(x, y);
    M5.Lcd.println(text);
}

void printCentered(const char* text, uint16_t color) {
    M5.Lcd.setTextColor(color);
    int textWidth = M5.Lcd.textWidth(text);
    int textHeight = M5.Lcd.fontHeight();
    int x = (135 - textWidth) / 2;
    int y = (240 - textHeight) / 2;
    M5.Lcd.setCursor(x, y);
    M5.Lcd.println(text);
}
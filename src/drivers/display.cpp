#include "display.h"

void drawBootMenu(const char* options[], int selected, int count) {
    M5.Lcd.fillScreen(TFT_BLACK);
    M5.Lcd.setTextColor(TFT_WHITE);
    M5.Lcd.setCursor(10, 20);
    M5.Lcd.println("QezOS Boot Menu");

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

void clear() {
    M5.Lcd.fillScreen(TFT_BLACK);
}

void setColor(uint16_t color) {
    M5.Lcd.fillScreen(color);
}

void printText(const char* text, int coordinates[2], uint16_t color) {
    M5.Lcd.setTextColor(color);
    M5.Lcd.setCursor(20, 50);
    M5.Lcd.println(text);
}
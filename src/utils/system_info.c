#include "system_info.h"
#include "m5_shim/m5_shim.h"
#include "drivers/display.h"
#include "drivers/buttons.h"
#include "core/inc/asm_graphics.h"
#include "stdbool.h"
void showSystemInfo() {
    clear();
    qz_lcd_set_text_color(TFT_CYAN);
    qz_lcd_set_cursor(10, 10);
    qz_lcd_println("=== System Info ===");
    
    qz_lcd_set_text_color(TFT_WHITE);
    qz_lcd_set_cursor(10, 35);
    qz_lcd_println("QezOS v0.1");
    
    qz_lcd_set_cursor(10, 55);
    qz_lcd_println("CPU: ESP32-S3");
    qz_lcd_set_cursor(10, 75);
    qz_lcd_printf("Freq: %d MHz\n", qz_esp_getFlashChipSize());
    
    qz_lcd_set_cursor(10, 100);
    qz_lcd_printf("RAM: %d KB\n", qz_esp_getFreeHeap() / 1024);
    
    qz_lcd_set_cursor(10, 120);
    qz_lcd_printf("Flash: %d MB\n", qz_esp_getFlashChipSize() / 1024 / 1024);
    qz_lcd_set_cursor(10, 140);
    qz_lcd_printf("Uptime: %d s\n", qz_millis() / 1000);
    qz_lcd_set_text_color(TFT_GRAY);
    qz_lcd_set_cursor(10, 180);
    qz_lcd_println("Press B to return");
    while (true) {
        int btn = getButtonPress();
        if (btn == BUTTON_B) {
            return;
        }
        delay(100);
    }
}
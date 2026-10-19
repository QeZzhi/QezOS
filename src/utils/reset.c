#include "reset.h"
#include "m5_shim/m5_shim.h"
#include "drivers/display.h"
#include "drivers/buttons.h"
#include "core/inc/asm_graphics.h"
#include "stdbool.h"

void resetSettings() {
    clear();
    qz_lcd_set_text_color(TFT_RED);
    qz_lcd_set_cursor(10, 20);
    qz_lcd_println("Reset Settings");
    qz_lcd_set_text_color(TFT_WHITE);
    qz_lcd_set_cursor(10, 60);
    qz_lcd_println("Are you sure?");
    qz_lcd_set_text_color(TFT_YELLOW);
    qz_lcd_set_cursor(10, 100);
    qz_lcd_println("A = Confirm");
    qz_lcd_set_cursor(10, 130);
    qz_lcd_println("B = Cancel");
    
    while (true) {
        int btn = getButtonPress();
        
        if (btn == BUTTON_A) {
            clear();
            qz_lcd_set_text_color(TFT_GREEN);
            qz_lcd_set_cursor(10, 80);
            qz_lcd_println("Resetting");
            delay(1000);
            
            qz_esp_restart();
        }
        else if (btn == BUTTON_B) {
            return;
        }
        
        delay(100);
    }
}
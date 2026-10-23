#include "secure.h"
#include "drivers/display.h"
#include "drivers/buttons.h"
#include "m5_shim/m5_shim.h"

void runSecureMenu(void) {
    const char* options[] = {
        "Check Integrity",
        "Lock Device",
        "Back to Boot"
    };
    int selected = 0;
    int count = 3;

    while (1) {
        drawGenericMenu("Secure Boot", options, selected, count);
        
        int btn = getButtonPress();
        
        if (btn == BUTTON_B) { 
            selected = (selected + 1) % count; // Вниз
        } 
        else if (btn == BUTTON_UP) {
            selected = (selected - 1 + count) % count; // Вверх
        }
        else if (btn == BUTTON_A) { 
            if (selected == 0) {
                clear();
                qz_lcd_set_text_color(TFT_GREEN);
                qz_lcd_set_cursor(10, 50);
                qz_lcd_println("Checking...");
                qz_delay(1500);
                qz_lcd_set_cursor(10, 80);
                qz_lcd_println("System OK");
                qz_delay(1500);
                clear();
            } 
            else if (selected == 1) {
                clear();
                qz_lcd_set_text_color(TFT_RED);
                qz_lcd_set_cursor(10, 50);
                qz_lcd_println("Device Locked!");
                qz_delay(2000);
                clear();
            } 
            else if (selected == 2) {
                clear();
                return; 
            }
        }
        qz_delay(150); 
    }
}
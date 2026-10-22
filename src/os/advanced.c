#include "advanced.h"
#include "drivers/display.h"
#include "drivers/buttons.h"
#include "m5_shim/m5_shim.h"

void runAdvancedOptionsMenu(void) {
    const char* options[] = {
        "System Info",
        "Hardware Test",
        "Reset Settings",
        "Back to Boot"
    };
    int selected = 0;
    int count = 4;

    while (1) {
        drawGenericMenu("|-- Advanced Options Boot--|", options, selected, count);
        
        int btn = getButtonPress();
        
        // Переключение вниз теперь на кнопке B
        if (btn == BUTTON_B) {
            selected = (selected + 1) % count;
        } 
        // Выбор теперь на кнопке A
        else if (btn == BUTTON_A) {
            if (selected == 0) {
                clear();
                showSystemInfo(); 
                qz_delay(2000);
                clear();
            } 
            else if (selected == 1) {
                clear();
                runHardwareTest();
            } 
            else if (selected == 2) {
                clear();
                qz_lcd_println("Resetting...");
                qz_delay(1000);
                resetSettings();
            } 
            else if (selected == 3) {
                clear();
                return; 
            }
        }
        qz_delay(150);
    }
}
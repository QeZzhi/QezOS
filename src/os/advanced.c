#include "advanced.h"
#include "drivers/display.h"
#include "drivers/buttons.h"
#include "m5_shim/m5_shim.h"
#include "utils/system_info.h"
#include "utils/hardware_test.h"
#include "utils/reset.h"

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
        drawGenericMenu("Advanced Options", options, selected, count);
        
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
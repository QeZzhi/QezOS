#include <stdio.h>
#include "bootloader.h"
#include "drivers/display.h"
#include "drivers/buttons.h"
#include "os/os.h" 
#include "m5_shim/m5_shim.h"

void bootMenu(void) {
    const char* options[] = {
        "Standart Boot",
        "Advanced Options",
        "Secure Boot",
        "Reboot"
    };
    int selected = 0;
    int count = 4;
    
    while (1) {
        drawBootMenu(options, selected, count);
        
        int btn = getButtonPress();
        
        if (btn == BUTTON_B) { 
            selected = (selected + 1) % count; // Вниз
        } 
        else if (btn == BUTTON_UP) {
            selected = (selected - 1 + count) % count; // Вверх
        }
        else if (btn == BUTTON_A) { 
            if (selected == 0) { clear(); StandartBoot(); } 
            else if (selected == 1) { clear(); AdvancedOptionsBoot(); } 
            else if (selected == 2) { clear(); SecureBoot(); } 
            else if (selected == 3) { clear(); qz_esp_restart(); }
        }
        qz_delay(100); 
    }
}
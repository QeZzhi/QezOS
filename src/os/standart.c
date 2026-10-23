#include "standart.h"
#include "drivers/display.h"
#include "drivers/buttons.h"
#include "m5_shim/m5_shim.h"

void runStandartMenu(void) {
    const char* apps[] = {"None", "None", "None", "Back to Boot"};
    int count = 4;
    int selected = 0;

    while (1) {
        drawGenericMenu("Apps Menu", apps, selected, count);
        
        int btn = getButtonPress();
        
        if (btn == BUTTON_B) { 
            selected = (selected + 1) % count; // Вниз
        } 
        else if (btn == BUTTON_UP) {
            selected = (selected - 1 + count) % count; // Вверх
        }
        else if (btn == BUTTON_A) { 
            if (selected == 3) {
                clear();
                return; // Выход в Boot Menu
            } else {
                clear();
                qz_lcd_set_text_color(TFT_YELLOW);
                qz_lcd_set_cursor(10, 50);
                qz_lcd_println("Launching app...");
                qz_delay(1000);
                clear();
                printCentered("In development", TFT_YELLOW);
                qz_delay(2000);
                clear();
            }
        }
        qz_delay(150); 
    }
}
#include "standart.h"
#include "drivers/display.h"
#include "drivers/buttons.h"
#include "m5_shim/m5_shim.h"

void runStandartMenu(void) {
    const char* apps[] = {"None", "None", "None", "Back to Boot"};
    int count = 4;
    int selected = 0;

    while (1) {
        // Рисуем меню (используем универсальную функцию из display.c)
        drawGenericMenu("|-----Apps Menu-----|", apps, selected, count);
        
        int btn = getButtonPress();
        
        if (btn == BUTTON_A) {
            // Переключение вниз
            selected = (selected + 1) % count;
        } 
        else if (btn == BUTTON_B) {
            // Выбор пункта
            if (selected == 3) {
                // "Back to Boot"
                clear();
                return; // Выход из меню
            } else {
                // Заглушка для остальных приложений
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
        qz_delay(150); // Антидребезг
    }
}
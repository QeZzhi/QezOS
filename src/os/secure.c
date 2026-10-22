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
        // Рисуем меню (используем функцию из display.c)
        drawGenericMenu("|-- Secure Boot --|", options, selected, count);
        
        int btn = getButtonPress();
        
        // Переключение вниз теперь на кнопке B
        if (btn == BUTTON_B) {
            selected = (selected + 1) % count;
        } 
        // Выбор теперь на кнопке A
        else if (btn == BUTTON_A) {
            if (selected == 0) {
                // Пункт "Check Integrity"
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
                // Пункт "Lock Device"
                clear();
                qz_lcd_set_text_color(TFT_RED);
                qz_lcd_set_cursor(10, 50);
                qz_lcd_println("Device Locked!");
                qz_delay(2000);
                clear();
            } 
            else if (selected == 2) {
                // Пункт "Back to Boot"
                clear();
                return; // Выход из функции
            }
        }
        qz_delay(150); // Антидребезг
    }
}
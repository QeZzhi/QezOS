// ============================================================
// reset.cpp — сброс настроек QezOS
// Спрашивает подтверждение и перезагружает устройство.
// reset.cpp — QezOS settings reset
// Asks for confirmation and restarts the device.
// ============================================================

#include "reset.h"                    // Объявление resetSettings | resetSettings declaration
#include <M5Unified.h>                // M5.Lcd, ESP.restart | M5.Lcd, ESP.restart
#include "drivers/display.h"          // clear | clear
#include "drivers/buttons.h"          // getButtonPress, BUTTON_A, BUTTON_B | getButtonPress, BUTTON_A, BUTTON_B
#include "lib/Qlib.h"                 // q.wait | q.wait
#include "core/inc/asm_graphics.h"    // fill_screen_fast (не используется) | fill_screen_fast (unused)

// ------------------------------------------------------------
// resetSettings — сбросить настройки QezOS
// Показывает подтверждение, при согласии — перезагрузка
// ------------------------------------------------------------
void resetSettings() { // Сброс настроек | Reset settings
    clear(); // Очищаем экран | Clear screen
    M5.Lcd.setTextColor(TFT_RED); // Красный цвет (предупреждение) | Red color (warning)
    M5.Lcd.setCursor(10, 20); // Курсор | Cursor
    M5.Lcd.println("Reset Settings"); // Заголовок | Title
    
    M5.Lcd.setTextColor(TFT_WHITE); // Белый цвет | White color
    M5.Lcd.setCursor(10, 60); // Курсор ниже | Cursor below
    M5.Lcd.println("Are you sure?"); // Вопрос | Question
    
    M5.Lcd.setTextColor(TFT_YELLOW); // Жёлтый цвет | Yellow color
    M5.Lcd.setCursor(10, 100); // Курсор | Cursor
    M5.Lcd.println("A = Confirm"); // A = подтвердить | A = Confirm
    M5.Lcd.setCursor(10, 130); // Курсор | Cursor
    M5.Lcd.println("B = Cancel"); // B = отмена | B = Cancel
    
    while (true) { // Цикл ожидания | Wait loop
        int btn = getButtonPress(); // Получаем нажатие | Get button press
        
        if (btn == BUTTON_A) { // Если подтверждение | If confirm
            // Подтверждение | Confirmation
            clear(); // Очищаем экран | Clear screen
            M5.Lcd.setTextColor(TFT_GREEN); // Зелёный цвет | Green color
            M5.Lcd.setCursor(10, 80); // Курсор | Cursor
            M5.Lcd.println("Resetting..."); // Надпись | Message
            q.wait(1000); // Пауза 1 сек | 1 sec delay
            
            // Перезагрузка | Restart
            ESP.restart(); // Перезагружаем устройство | Restart device
        }
        else if (btn == BUTTON_B) { // Если отмена | If cancel
            // Отмена — возврат в меню | Cancel — return to menu
            return; // Возврат в меню | Return to menu
        }
        
        q.wait(100); // Пауза 100 мс (антидребезг) | 100 ms delay (debounce)
    }
}
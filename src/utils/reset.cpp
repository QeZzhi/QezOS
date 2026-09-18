#include "reset.h"
#include <M5Unified.h>
#include "drivers/display.h"
#include "drivers/buttons.h"
#include "lib/Qlib.h"
#include "core/inc/asm_graphics.h"

void resetSettings() {
    clear();
    M5.Lcd.setTextColor(TFT_RED);
    M5.Lcd.setCursor(10, 20);
    M5.Lcd.println("Reset Settings");
    
    M5.Lcd.setTextColor(TFT_WHITE);
    M5.Lcd.setCursor(10, 60);
    M5.Lcd.println("Are you sure?");
    
    M5.Lcd.setTextColor(TFT_YELLOW);
    M5.Lcd.setCursor(10, 100);
    M5.Lcd.println("A = Confirm");
    M5.Lcd.setCursor(10, 130);
    M5.Lcd.println("B = Cancel");
    
    while (true) {
        int btn = getButtonPress();
        
        if (btn == BUTTON_A) {
            // Подтверждение
            clear();
            M5.Lcd.setTextColor(TFT_GREEN);
            M5.Lcd.setCursor(10, 80);
            M5.Lcd.println("Resetting...");
            q.wait(1000);
            
            // Перезагрузка
            ESP.restart();
        }
        else if (btn == BUTTON_B) {
            // Отмена — возврат в меню
            return;
        }
        
        q.wait(100);
    }
}
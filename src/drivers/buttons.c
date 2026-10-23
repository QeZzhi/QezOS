#include "buttons.h"
#include "m5_shim/m5_shim.h"
#include "stdbool.h"

int getButtonPress(void) {
    qz_m5_update(); 
    
    static bool long_press_active = false; // Флаг: было ли долгое нажатие
    
    // 1. Если кнопку только что зажали
    if (qz_btn_a_wasPressed()) {
        long_press_active = false; // Сбрасываем флаг для нового нажатия
    }
    
    // 2. Если кнопка зажата долго (срабатывает на 1-й секунде)
    if (qz_btn_a_wasLongPressed()) {
        long_press_active = true; // Ставим флаг, что это было долгое нажатие
        return BUTTON_UP;         // Возвращаем "Вверх"
    } 
    
    // 3. Если кнопку отпустили
    if (qz_btn_a_wasReleased()) {
        if (!long_press_active) {
            // Если это было короткое нажатие (флага нет) -> это ВЫБОР
            return BUTTON_A; 
        }
        // Если флаг есть, значит это было долгое нажатие.
        // Мы НЕ возвращаем выбор, просто сбрасываем флаг.
        long_press_active = false;
    }
    
    // 4. Кнопка B (Вниз)
    if (qz_btn_b_wasPressed()) return BUTTON_B;
    
    return BUTTON_NONE;
}
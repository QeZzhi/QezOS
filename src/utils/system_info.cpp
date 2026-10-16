// ============================================================
// system_info.cpp — информация о системе QezOS
// Показывает версию, CPU, RAM, Flash, время работы.
// system_info.cpp — QezOS system info
// Shows version, CPU, RAM, Flash, uptime.
// ============================================================

#include "system_info.h"              // Объявление showSystemInfo | showSystemInfo declaration
#include <M5Unified.h>                // M5.Lcd, ESP, getCpuFrequencyMhz | M5.Lcd, ESP, getCpuFrequencyMhz
#include "drivers/display.h"          // clear | clear
#include "drivers/buttons.h"          // getButtonPress, BUTTON_B | getButtonPress, BUTTON_B
#include "lib/Qlib.h"                 // q.wait | q.wait
#include "core/inc/asm_graphics.h"    // fill_screen_fast (не используется) | fill_screen_fast (unused)

// ------------------------------------------------------------
// showSystemInfo — показать информацию о системе
// Выводит версию, CPU, RAM, Flash, uptime, ждёт нажатия B
// ------------------------------------------------------------
void showSystemInfo() { // Информация о системе | System info
    clear(); // Очищаем экран | Clear screen
    M5.Lcd.setTextColor(TFT_CYAN); // Голубой цвет | Cyan color
    M5.Lcd.setCursor(10, 10); // Курсор | Cursor
    M5.Lcd.println("=== System Info ==="); // Заголовок | Title
    
    M5.Lcd.setTextColor(TFT_WHITE); // Белый цвет | White color
    M5.Lcd.setCursor(10, 35); // Курсор ниже | Cursor below
    M5.Lcd.println("QezOS v0.1"); // Версия QezOS | QezOS version
    
    M5.Lcd.setCursor(10, 55); // Курсор | Cursor
    M5.Lcd.println("CPU: ESP32-S3"); // Процессор | CPU
    M5.Lcd.setCursor(10, 75); // Курсор | Cursor
    M5.Lcd.printf("Freq: %d MHz\n", getCpuFrequencyMhz()); // Частота CPU | CPU frequency
    
    M5.Lcd.setCursor(10, 100); // Курсор | Cursor
    M5.Lcd.printf("RAM: %d KB\n", ESP.getFreeHeap() / 1024); // Свободная RAM | Free RAM
    
    M5.Lcd.setCursor(10, 120); // Курсор | Cursor
    M5.Lcd.printf("Flash: %d MB\n", ESP.getFlashChipSize() / 1024 / 1024); // Размер Flash | Flash size
    M5.Lcd.setCursor(10, 140); // Курсор | Cursor
    M5.Lcd.printf("Uptime: %d s\n", millis() / 1000); // Время работы в сек | Uptime in sec
    M5.Lcd.setTextColor(TFT_GRAY); // Серый цвет | Gray color
    M5.Lcd.setCursor(10, 180); // Курсор ниже | Cursor below
    M5.Lcd.println("Press B to return"); // Подсказка | Hint
    while (true) { // Цикл ожидания | Wait loop
        int btn = getButtonPress(); // Получаем нажатие | Get button press
        if (btn == BUTTON_B) { // Если B | If B
            return; // Выход из меню | Exit menu
        }
        q.wait(100); // Пауза 100 мс (антидребезг) | 100 ms delay (debounce)
    }
}
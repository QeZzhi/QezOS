// ============================================================
// advanced.cpp — расширенное меню QezOS
// Здесь: тест железа, информация о системе, сброс настроек.
// advanced.cpp — advanced menu of QezOS
// Here: hardware test, system info, reset settings.
// ============================================================

#include <M5Unified.h> // Библиотека M5Stack (экран, кнопки, звук) | M5Stack library (screen, buttons, sound)
#include "drivers/display.h" // Функции рисования меню | Menu drawing functions
#include <drivers/buttons.h> // getButtonPress | getButtonPress
#include "lib/Qlib.h" // Q q (wait, print) | Q q (wait, print)
#include "utils/hardware_test.h" // runHardwareTest | runHardwareTest
#include "utils/reset.h" // resetSettings | resetSettings
#include "utils/system_info.h" // showSystemInfo | showSystemInfo

// ------------------------------------------------------------
// runAdvancedOptionsMenu — расширенное меню QezOS
// Показывает список опций, обрабатывает нажатия кнопок
// ------------------------------------------------------------
void runAdvancedOptionsMenu() { // Расширенное меню | Advanced menu
    const char* options[] = { // Массив опций | Options array
        "Hardware Test", // Тест железа | Hardware test
        "System Info", // Информация о системе | System info
        "Reset Settings", // Сброс настроек | Reset settings
        "Back" // Назад | Back
    };
    int count = 4; // Количество опций | Number of options
    int selected = 0; // Текущая выбранная опция | Currently selected option
    
    while (true) { // Бесконечный цикл меню | Infinite menu loop
        drawGenericMenu("Advanced Options", options, selected, count); // Рисуем меню | Draw menu
        int btn = getButtonPress(); // Получаем нажатие кнопки | Get button press
        
        if (btn == BUTTON_A) { // Если кнопка A | If button A
            selected = (selected + 1) % count; // Следующая опция (по кругу) | Next option (circular)
        } else if (btn == BUTTON_B) { // Если кнопка B | If button B
            switch (selected) { // Смотрим, что выбрано | Check what's selected
                case 0: runHardwareTest(); break; // Тест железа | Hardware test
                case 1: showSystemInfo(); break; // Информация о системе | System info
                case 2: resetSettings(); break; // Сброс настроек | Reset settings
                case 3: return; // Назад — выход из меню | Back — exit menu
            }
        }
        q.wait(100); // Пауза 100 мс (антидребезг) | 100 ms delay (debounce)
    }
}
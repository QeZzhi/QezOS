// ============================================================
// bootloader.cpp — загрузчик QezOS
// Показывает меню выбора режима загрузки (3 варианта).
// bootloader.cpp — QezOS bootloader
// Shows boot mode selection menu (3 options).
// ============================================================

#include <M5Unified.h>            // Библиотека M5Stack | M5Stack library
#include "bootloader.h"           // Объявление bootMenu | bootMenu declaration
#include "../drivers/display.h"   // drawBootMenu | drawBootMenu
#include "../drivers/buttons.h"   // getButtonPress, BUTTON_A, BUTTON_B | getButtonPress, BUTTON_A, BUTTON_B
#include "lib/Qlib.h"             // q.wait | q.wait
#include "os/os.h"                // StandartBoot, AdvancedOptionsBoot, SecureBoot | StandartBoot, AdvancedOptionsBoot, SecureBoot

// ------------------------------------------------------------
// bootselect — массив выбора загрузки (пока не используется)
// 3 элемента: по одному на каждый режим загрузки
// ------------------------------------------------------------
int bootselect[3] = {0, 0, 0}; // Массив выбора (зарезервирован) | Selection array (reserved)

// ------------------------------------------------------------
// bootMenu — главное меню загрузчика
// Показывает 3 режима загрузки, обрабатывает нажатия
// ------------------------------------------------------------
void bootMenu() { // Меню загрузки | Boot menu
    int selected = 0; // Текущий выбранный режим | Currently selected mode
    const char* options[3] = {"QezOS Standard Boot", "QezOS Advanced Options Boot", "QezOS Secure Boot"}; // 3 режима загрузки | 3 boot modes

    while (true) { // Бесконечный цикл меню | Infinite menu loop
        drawBootMenu(options, selected, 3); // Рисуем меню | Draw menu
        int btn = getButtonPress(); // Получаем нажатие кнопки | Get button press
        if (btn == BUTTON_A) { // Если кнопка A | If button A
            selected = (selected + 1) % 3; // Следующий режим (по кругу) | Next mode (circular)
        } else if (btn == BUTTON_B) { // Если кнопка B | If button B
            if (selected == 0) { // Режим 0: Standard | Mode 0: Standard
                StandartBoot(); // Запуск Standard Boot | Run Standard Boot
            } else if (selected == 1) { // Режим 1: Advanced | Mode 1: Advanced
                AdvancedOptionsBoot(); // Запуск Advanced Boot | Run Advanced Boot
            } else { // Режим 2: Secure | Mode 2: Secure
                SecureBoot(); // Запуск Secure Boot | Run Secure Boot
            }
        }
        q.wait(100); // Пауза 100 мс (антидребезг) | 100 ms delay (debounce)
    }
}
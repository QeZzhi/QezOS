// ============================================================
// secure.cpp — меню Secure Boot в QezOS
// Пока что функции-заглушки: «This function is delevop».
// secure.cpp — Secure Boot menu in QezOS
// Currently stub functions: "This function is delevop".
// ============================================================

#include <M5Unified.h>        // Библиотека M5Stack | M5Stack library
#include "drivers/display.h"  // drawGenericMenu, clear, printCentered | drawGenericMenu, clear, printCentered
#include <drivers/buttons.h>  // getButtonPress, BUTTON_A, BUTTON_B | getButtonPress, BUTTON_A, BUTTON_B
#include "lib/Qlib.h"         // q.print, q.println, q.wait | q.print, q.println, q.wait

// ------------------------------------------------------------
// runSecureMenu — меню Secure Boot
// Показывает список приложений (все — «None»)
// ------------------------------------------------------------
void runSecureMenu() { // Меню Secure Boot | Secure Boot menu
    const char* apps_secure[4] = {"None", "None", "None", "Back to Boot"}; // Массив приложений | Apps array
    int appCount = 4; // Количество пунктов | Number of items
    int selected = 0; // Текущий выбранный пункт | Currently selected item
    
    while (true) { // Бесконечный цикл меню | Infinite menu loop
        drawGenericMenu("|-----Secure Boot-----|", apps_secure, selected, appCount); // Рисуем меню | Draw menu
        
        int btn = getButtonPress(); // Получаем нажатие кнопки | Get button press
        
        if (btn == BUTTON_A) { // Если кнопка A | If button A
            selected = (selected + 1) % appCount; // Следующий пункт | Next item
        }
        else if (btn == BUTTON_B) { // Если кнопка B | If button B
            if (selected == 0) { // Пункт 0 | Item 0
                q.print("Launching "); // Печатаем «Launching » | Print "Launching "
                apps_secure[0]; // (бесполезная строка — результат не используется) | (useless line — result unused)
                q.wait(1000); // Пауза 1 сек | 1 sec delay
                clear(); // Очищаем экран | Clear screen
                printCentered("This function is develop", TFT_YELLOW); // Заглушка | Stub
                q.wait(2000); // Пауза 2 сек | 2 sec delay
                clear(); // Очищаем экран | Clear screen
            } else if (selected == 1) { // Пункт 1 | Item 1
                q.println("Launching "); // Печатаем «Launching » с новой строкой | Print "Launching " with newline
                apps_secure[1]; // (бесполезная строка) | (useless line)
                q.wait(1000); // Пауза 1 сек | 1 sec delay
                clear(); // Очищаем экран | Clear screen
                printCentered("This function is develop", TFT_YELLOW); // Заглушка | Stub
                q.wait(2000); // Пауза 2 сек | 2 sec delay
                clear(); // Очищаем экран | Clear screen
            } else if (selected == 2) { // Пункт 2 | Item 2
                q.println("Launching "); // Печатаем «Launching » с новой строкой | Print "Launching " with newline
                apps_secure[2]; // (бесполезная строка) | (useless line)
                q.wait(1000); // Пауза 1 сек | 1 sec delay
                clear(); // Очищаем экран | Clear screen
                printCentered("This function is develop", TFT_YELLOW); // Заглушка | Stub
                q.wait(2000); // Пауза 2 сек | 2 sec delay
                clear(); // Очищаем экран | Clear screen
            } else if (selected == 3) { // Пункт 3 (Back to Boot) | Item 3 (Back to Boot)
                printCentered(apps_secure[3], TFT_WHITE); // Печатаем «Back to Boot» | Print "Back to Boot"
                q.wait(1000); // Пауза 1 сек | 1 sec delay
                clear(); // Очищаем экран | Clear screen
                return; // Выход из меню | Exit menu
            }
        }
        q.wait(100); // Пауза 100 мс (антидребезг) | 100 ms delay (debounce)
    }
}
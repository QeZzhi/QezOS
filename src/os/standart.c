// ============================================================
// standart.cpp — стандартное меню приложений QezOS
// Пока что все приложения — заглушки («This function is delevop»).
// standart.cpp — standard apps menu of QezOS
// All apps are currently stubs ("This function is delevop").
// ============================================================

#include <M5Unified.h>        // Библиотека M5Stack | M5Stack library
#include "drivers/display.h"  // drawGenericMenu, clear, printCentered | drawGenericMenu, clear, printCentered
#include <drivers/buttons.h>  // getButtonPress, BUTTON_A, BUTTON_B | getButtonPress, BUTTON_A, BUTTON_B
#include "lib/Qlib.h"         // q.print, q.println, q.wait | q.print, q.println, q.wait

// ------------------------------------------------------------
// runStandartMenu — стандартное меню приложений
// Показывает список приложений (пока все — «None»)
// ------------------------------------------------------------
void runStandartMenu() { // Стандартное меню | Standard menu
    const char* apps_standart[4] = {"None", "None", "None", "Back to Boot"}; // Массив приложений | Apps array
    int appCount = 4; // Количество пунктов | Number of items
    int selected = 0; // Текущий выбранный пункт | Currently selected item
    
    while (true) { // Бесконечный цикл меню | Infinite menu loop
        drawGenericMenu("|-----Apps Menu-----|", apps_standart, selected, appCount); // Рисуем меню | Draw menu
        
        int btn = getButtonPress(); // Получаем нажатие кнопки | Get button press
        
        if (btn == BUTTON_A) { // Если кнопка A | If button A
            selected = (selected + 1) % appCount; // Следующий пункт | Next item
        }
        else if (btn == BUTTON_B) { // Если кнопка B | If button B
            if (selected == 0) { // Пункт 0 | Item 0
                q.print("Launching "); // Печатаем «Launching » | Print "Launching "
                apps_standart[0]; // (бесполезная строка) | (useless line)
                q.wait(1000); // Пауза 1 сек | 1 sec delay
                clear(); // Очищаем экран | Clear screen
                printCentered("This function is delevop", TFT_YELLOW); // Заглушка | Stub
                q.wait(2000); // Пауза 2 сек | 2 sec delay
                clear(); // Очищаем экран | Clear screen
            } else if (selected == 1) { // Пункт 1 | Item 1
                q.println("Launching "); // Печатаем «Launching » с новой строкой | Print "Launching " with newline
                apps_standart[1]; // (бесполезная строка) | (useless line)
                q.wait(1000); // Пауза 1 сек | 1 sec delay
                clear(); // Очищаем экран | Clear screen
                printCentered("This function is delevop", TFT_YELLOW); // Заглушка | Stub
                q.wait(2000); // Пауза 2 сек | 2 sec delay
                clear(); // Очищаем экран | Clear screen
            } else if (selected == 2) { // Пункт 2 | Item 2
                q.println("Launching "); // Печатаем «Launching » с новой строкой | Print "Launching " with newline
                apps_standart[2]; // (бесполезная строка) | (useless line)
                q.wait(1000); // Пауза 1 сек | 1 sec delay
                clear(); // Очищаем экран | Clear screen
                printCentered("This function is delevop", TFT_YELLOW); // Заглушка | Stub
                q.wait(2000); // Пауза 2 сек | 2 sec delay
                clear(); // Очищаем экран | Clear screen
            } else if (selected == 3) { // Пункт 3 (Back to Boot) | Item 3 (Back to Boot)
                printCentered(apps_standart[3], TFT_WHITE); // Печатаем «Back to Boot» | Print "Back to Boot"
                q.wait(1000); // Пауза 1 сек | 1 sec delay
                clear(); // Очищаем экран | Clear screen
                return; // Выход из меню | Exit menu
            }
            delay(500); // Пауза 500 мс после выбора | 500 ms delay after selection
        }
        delay(100); // Пауза 100 мс (антидребезг) | 100 ms delay (debounce)
    }
}
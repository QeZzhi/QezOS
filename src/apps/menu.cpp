#include <M5Unified.h>
#include "drivers/display.h"
#include <drivers/buttons.h>
#include "lib/Qlib.h"
#include "menu.h"

void runStandartMenu() {

    int appCount = 4;
    int selected = 0;

    while (true) {
        // Рисуем меню
        drawGenericMenu("|-----Apps Menu-----|", q.apps, selected, appCount);

        // Ждём нажатие кнопки
        int btn = getButtonPress(); // функция из buttons.h

        if (btn == BUTTON_A) {
            selected = (selected + 1) % appCount; // переключение вниз
        }
        else if (btn == BUTTON_B) {
            // Выбор приложения
            if (selected == 0) {
                q.println("Launching App 1...");
                // здесь код запуска App 1
            } else if (selected == 1) {
                q.println("Launching App 2...");
                // здесь код запуска App 2
            } else if (selected == 2) {
                q.println("Launching App 3...");
                // здесь код запуска App 3
            } else if (selected == 3) {
                q.println("Returning to Boot...");
                return; // выходим из меню и возвращаемся в загрузчик
            }
            delay(500);
        }
        delay(100);
    }
}
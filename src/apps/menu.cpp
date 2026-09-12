#include <M5Unified.h>
#include "drivers/display.h"
#include <drivers/buttons.h>
#include "lib/Qlib.h"
#include "menu.h"
#include "utils/delevop.h"

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
            if (selected == 0) {
                q.print("Launching ");
                q.apps[0];
                delevop();
            } else if (selected == 1) {
                q.println("Launching ");
                q.apps[1];
                delevop();
            } else if (selected == 2) {
                q.println("Launching ");
                q.apps[2];
                delevop();
            } else if (selected == 3) {
                q.println("Exit to bootloader ");
                q.apps[3];
                delevop();
                return;
            }
            delay(500);
        }
        delay(100);
    }
}
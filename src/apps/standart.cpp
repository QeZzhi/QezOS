#include <M5Unified.h>
#include "drivers/display.h"
#include <drivers/buttons.h>
#include "lib/Qlib.h"

void runStandartMenu() {
    const char* apps_standart[4] = {"None", "None", "None", "Back to Boot"};
    int appCount = 4;
    int selected = 0;
    
    while (true) {
        drawGenericMenu("|-----Apps Menu-----|", apps_standart, selected, appCount);
        
        int btn = getButtonPress();
        
        if (btn == BUTTON_A) {
            selected = (selected + 1) % appCount;
        }
        else if (btn == BUTTON_B) {
            if (selected == 0) {
                q.print("Launching ");
                apps_standart[0];
                q.wait(1000);
                clear();
                printCentered("This function is delevop", TFT_YELLOW);
                q.wait(2000);
                runStandartMenu();
            } else if (selected == 1) {
                q.println("Launching ");
                apps_standart[1];
                q.wait(1000);
                clear();
                printCentered("This function is delevop", TFT_YELLOW);
                q.wait(2000);
                runStandartMenu();
            } else if (selected == 2) {
                q.println("Launching ");
                apps_standart[2];
                q.wait(1000);
                clear();
                printCentered("This function is delevop", TFT_YELLOW);
                q.wait(2000);
                runStandartMenu();
            } else if (selected == 3) {
                printCentered(apps_standart[3], TFT_WHITE);
                q.wait(1000);
                clear();
                return;
            }
            delay(500);
        }
        delay(100);
    }
}
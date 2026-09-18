#include <M5Unified.h>
#include "drivers/display.h"
#include <drivers/buttons.h>
#include "lib/Qlib.h"

void runSecureMenu() {
    const char* apps_secure[4] = {"None", "None", "None", "Back to Boot"};
    int appCount = 4;
    int selected = 0;
    
    while (true) {
        drawGenericMenu("|-----Secure Boot-----|", apps_secure, selected, appCount);
        
        int btn = getButtonPress();
        
        if (btn == BUTTON_A) {
            selected = (selected + 1) % appCount;
        }
        else if (btn == BUTTON_B) {
            if (selected == 0) {
                q.print("Launching ");
                apps_secure[0];
                q.wait(1000);
                clear();
                printCentered("This function is delevop", TFT_YELLOW);
                q.wait(2000);
                runSecureMenu();
            } else if (selected == 1) {
                q.println("Launching ");
                apps_secure[1];
                q.wait(1000);
                clear();
                printCentered("This function is delevop", TFT_YELLOW);
                q.wait(2000);
                runSecureMenu();
            } else if (selected == 2) {
                q.println("Launching ");
                apps_secure[2];
                q.wait(1000);
                clear();
                printCentered("This function is delevop", TFT_YELLOW);
                q.wait(2000);
                runSecureMenu();
            } else if (selected == 3) {
                printCentered(apps_secure[3], TFT_WHITE);
                q.wait(1000);
                clear();
                return;
            }
        }
        q.wait(100);
    }
}
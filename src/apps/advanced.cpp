#include <M5Unified.h>
#include "drivers/display.h"
#include <drivers/buttons.h>
#include "lib/Qlib.h"
#include "utils/hardware_test.h"
#include "utils/reset.h"
#include "utils/system_info.h"

void runAdvancedOptionsMenu() {
    const char* options[] = {
        "Hardware Test",
        "System Info",
        "Reset Settings",
        "Back"
    };
    int count = 4;
    int selected = 0;
    
    while (true) {
        drawGenericMenu("Advanced Options", options, selected, count);
        int btn = getButtonPress();
        
        if (btn == BUTTON_A) {
            selected = (selected + 1) % count;
        } else if (btn == BUTTON_B) {
            switch (selected) {
                case 0: runHardwareTest(); break;
                case 1: showSystemInfo(); break;
                case 2: resetSettings(); break;
                case 3: return;
            }
        }
        q.wait(100);
    }
}
#include <M5Unified.h>
#include "bootloader.h"
#include "../drivers/display.h"
#include "../drivers/buttons.h"
#include "lib/Qlib.h"
#include "apps/menu.h"
#include "os/os.h"

int bootselect[3] = {0, 0, 0};           

void bootMenu() {
    int selected = 0;
    const char* options[3] = {"QezOS Standard Boot", "QezOS Advanced Options Boot", "QezOS Secure Boot"};



    while (true) {
        drawBootMenu(options, selected, 3);
        int btn = getButtonPress();
        if (btn == BUTTON_A) {
            selected = (selected + 1) % 3;
        } else if (btn == BUTTON_B) {
            if (selected == 0) {
                StandartBoot();
            } else if (selected == 1) {
                AdvancedOptionsBoot();
            } else {
                SecureBoot();
            }
        }
        q.wait(100);
    }
}


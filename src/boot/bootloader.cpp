#include <M5Unified.h>
#include "bootloader.h"
#include "../drivers/display.h"
#include "../drivers/buttons.h"
#include "lib/Qlib.h"
#include "utils/logger.h"

int bootselect[3] = {0, 0, 0};           

void StandardBoot() {
    clear();
    M5.Lcd.setTextColor(TFT_WHITE);
    M5.Lcd.setCursor(20, 50);
    M5.Lcd.println("QezOS Standard Boot");
    
    while (true) {
        q.wait(100);
    }
}

void AdvancedOptionsBoot() {
    clear();
    M5.Lcd.setTextColor(TFT_YELLOW);
    M5.Lcd.setCursor(20, 50);
    M5.Lcd.println("QezOS Advanced Options Boot");
    while (true) {
        q.wait(100);
    }
}

void SecureBoot() {
    clear();
    M5.Lcd.setTextColor(TFT_GREEN);
    M5.Lcd.setCursor(20, 50);
    M5.Lcd.println("QezOS Secure Boot");
    while(true) {
        q.wait(100);
    }
}

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
                logMessage("Starting QezOS Standard Boot");
                StandardBoot();
            } else if (selected == 1) {
                logMessage("Starting QezOS Advanced Options Boot");
                AdvancedOptionsBoot();
            } else {
                logMessage("Starting QezOS Secure Boot");
                SecureBoot();
            }
        }
        q.wait(100);
    }
}


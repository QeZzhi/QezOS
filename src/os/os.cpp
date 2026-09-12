#include "os.h"
#include <apps/menu.h>2
#include <M5Unified.h>
#includ "/lib/Qlib.h"
#include "drivers/display.h"

void StandartBoot() {
    M5.Lcd.setTextColor(TFT_WHITE);
    M5.Lcd.setCursor(20, 50);
    M5.Lcd.println("QezOS Standard Boot");
    q.wait(1000);

    runStandartBoot();
}

void AdvancedOptionsBoot() {
    clear();
    M5.Lcd.setTextColor(TFT_YELLOW);
    M5.Lcd.setCursor(20, 50);
    M5.Lcd.println("QezOS Advanced Options Boot");
    while (true) {
        q.wait(1000);
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
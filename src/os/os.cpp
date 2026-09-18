#include "os.h"
#include <M5Unified.h>
#include "lib/Qlib.h"
#include "drivers/display.h"
#include "apps/standart.h"
#include "apps/secure.h"
#include "apps/advanced.h"

void StandartBoot() {
    clear();
    M5.Lcd.setTextColor(TFT_WHITE);
    M5.Lcd.setCursor(20, 50);
    M5.Lcd.println("QezOS Standard Boot...");
    q.wait(1000);
    clear();
    runStandartMenu();
}

void AdvancedOptionsBoot() {
    clear();
    M5.Lcd.setTextColor(TFT_YELLOW);
    M5.Lcd.setCursor(20, 50);
    M5.Lcd.println("QezOS Advanced Options Boot...");
    q.wait(1000);
    clear();
    runAdvancedOptionsMenu();
    }

void SecureBoot() {
    clear();
    M5.Lcd.setTextColor(TFT_GREEN);
    M5.Lcd.setCursor(20, 50);
    M5.Lcd.println("QezOS Secure Boot...");
    q.wait(1000);
    clear();
    runSecureMenu();
}

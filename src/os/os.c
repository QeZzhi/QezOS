#include "m5_shim/m5_shim.h"
#include "os.h"
#include "drivers/display.h"
#include "standart.h"
#include "advanced.h"
#include "secure.h"

void StandartBoot() {
    clear();
    qz_lcd_set_text_color(TFT_WHITE);
    qz_lcd_set_cursor(20, 50);
    qz_lcd_println("QezOS Standard Boot...");
    delay(1000);
    clear();
    runStandartMenu();
}

void AdvancedOptionsBoot() {
    clear();
    qz_lcd_set_text_color(TFT_YELLOW);
    qz_lcd_set_cursor(20, 50);
    qz_lcd_println("QezOS Advanced Options Boot...");
    delay(1000);
    clear();
    runAdvancedOptionsMenu();
}

void SecureBoot() {
    clear();
    qz_lcd_set_text_color(TFT_GREEN);
    qz_lcd_set_cursor(20, 50);
    qz_lcd_println("QezOS Secure Boot...");
    delay(1000);
    clear();
    runSecureMenu();
}
#include <M5Unified.h>
#include "boot/bootloader.h"

void setup() {
    auto cfg = M5.config();
    M5.begin(cfg);
    M5.Lcd.setRotation(1);
    bootMenu();
}

void loop() {
    delay(1000);
}

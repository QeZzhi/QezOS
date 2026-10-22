#include <Arduino.h>
#include "m5_shim/m5_shim.h"
#include "boot/bootloader.h"

#define POWER_HOLD_PIN 4  // Пин, который удерживает питание на StickC Plus 2

void setup() {
    pinMode(POWER_HOLD_PIN, OUTPUT);
    digitalWrite(POWER_HOLD_PIN, HIGH); // Сначала подаем питание
    delay(100); // Даем плате время закрепиться
    
    qz_m5_begin();
    
    // ВАЖНО: Принудительно удерживаем питание
    pinMode(POWER_HOLD_PIN, OUTPUT);
    digitalWrite(POWER_HOLD_PIN, HIGH);
    
    qz_m5_set_rotation(3);
    bootMenu();
}

void loop() {
    qz_m5_update();      // Обновление состояния (кнопки, питание)
    delay(10);           // Небольшая пауза
}
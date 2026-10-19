#include <Arduino.h>
#include "m5_shim/m5_shim.h"
#include "boot/bootloader.h"

void setup() {
    qz_m5_begin();       // Инициализация M5
    qz_m5_set_rotation(1);  // Поворот экрана
    bootMenu();          // Запуск твоего C-меню
}

void loop() {
    qz_m5_update();      // Обновление состояния (кнопки, питание)
    delay(10);           // Небольшая пауза
}
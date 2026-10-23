#include <Arduino.h>
#include "m5_shim/m5_shim.h"
#include "boot/bootloader.h"

#define POWER_HOLD_PIN 4 

void setup() {
    pinMode(POWER_HOLD_PIN, OUTPUT);
    digitalWrite(POWER_HOLD_PIN, HIGH);
    delay(100); 
    
    qz_m5_begin();
    qz_m5_set_rotation(3);
    
    qz_canvas_init(); // Инициализируем Canvas после поворота
    
    bootMenu();
}

void loop() {
    qz_m5_update();
    delay(10);
}
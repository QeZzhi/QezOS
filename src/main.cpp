// ============================================================
// main.cpp — точка входа QezOS
// Инициализирует M5StickS3 и запускает загрузчик.
// main.cpp — QezOS entry point
// Initializes M5StickS3 and starts the bootloader.
// ============================================================

#include <M5Unified.h>            // M5.config, M5.begin, M5.Lcd | M5.config, M5.begin, M5.Lcd
#include "boot/bootloader.h"      // bootMenu | bootMenu

// ------------------------------------------------------------
// setup — вызывается один раз при запуске
// Инициализирует M5, поворачивает экран, запускает загрузчик
// ------------------------------------------------------------
void setup() { // Инициализация | Initialization
    auto cfg = M5.config(); // Конфигурация M5 по умолчанию | Default M5 config
    M5.begin(cfg); // Инициализируем M5 (экран, кнопки, звук) | Initialize M5 (screen, buttons, sound)
    M5.Lcd.setRotation(1); // Поворачиваем экран в альбомную ориентацию | Rotate screen to landscape
    bootMenu(); // Запускаем меню загрузки | Start boot menu
}

// ------------------------------------------------------------
// loop — вызывается в бесконечном цикле после setup
// У QezOS вся логика в bootMenu, поэтому loop пустой
// ------------------------------------------------------------
void loop() { // Основной цикл | Main loop
    delay(1000); // Пауза 1 сек (ничего не делаем) | 1 sec delay (do nothing)
}
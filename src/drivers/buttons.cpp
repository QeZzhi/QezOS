// ============================================================
// buttons.cpp — работа с кнопками M5StickS3
// Читает нажатия кнопок A и B, возвращает код нажатия.
// buttons.cpp — button handling for M5StickS3
// Reads presses of buttons A and B, returns press code.
// ============================================================

#include "buttons.h"     // BUTTON_A, BUTTON_B, BUTTON_NONE | BUTTON_A, BUTTON_B, BUTTON_NONE
#include <M5Unified.h>   // M5.update, M5.BtnA, M5.BtnB | M5.update, M5.BtnA, M5.BtnB

// ------------------------------------------------------------
// getButtonPress — получить нажатие кнопки
// Возвращает: BUTTON_A, BUTTON_B или BUTTON_NONE
// ------------------------------------------------------------
int getButtonPress() { // Получить нажатие | Get button press
    M5.update(); // Обновляем состояние кнопок | Update button state
    if (M5.BtnA.wasPressed()) return BUTTON_A; // Если нажата A — вернуть BUTTON_A | If A pressed — return BUTTON_A
    if (M5.BtnB.wasPressed()) return BUTTON_B; // Если нажата B — вернуть BUTTON_B | If B pressed — return BUTTON_B
    return BUTTON_NONE; // Ничего не нажато | Nothing pressed
}
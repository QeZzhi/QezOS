// ============================================================
// buttons.h — заголовок для работы с кнопками M5StickS3
// Определяет коды кнопок и функцию getButtonPress.
// buttons.h — button handling header for M5StickS3
// Defines button codes and the getButtonPress function.
// ============================================================

#pragma once // Включить этот файл только один раз | Include this file only once

// ------------------------------------------------------------
// Коды кнопок
// Меню получают эти константы вместо того, чтобы знать про M5
// ------------------------------------------------------------
#define BUTTON_A 1    // Кнопка A | Button A
#define BUTTON_B 2    // Кнопка B | Button B
#define BUTTON_NONE 0 // Ничего не нажато | Nothing pressed

// ------------------------------------------------------------
// getButtonPress — получить нажатие кнопки
// Возвращает BUTTON_A, BUTTON_B или BUTTON_NONE
// ------------------------------------------------------------
int getButtonPress(); // Получить нажатие | Get button press
// ============================================================
// display.h — заголовок для работы с дисплеем M5StickS3
// Объявляет функции рисования меню, очистки, вывода текста.
// display.h — display handling header for M5StickS3
// Declares functions for drawing menus, clearing, printing text.
// ============================================================

#pragma once // Включить этот файл только один раз | Include this file only once
#include <M5Unified.h> // Нужен тип uint16_t и TFT_* | Need uint16_t type and TFT_*

// ------------------------------------------------------------
// Функции для работы с дисплеем
// ------------------------------------------------------------

// Нарисовать меню загрузчика | Draw bootloader menu
void drawBootMenu(const char* options[], int selected, int count);

// Очистить экран | Clear screen
void clear();

// Напечатать текст в позиции (x, y) | Print text at position (x, y)
void printText(const char* text, int x, int y, uint16_t color);

// Нарисовать универсальное меню | Draw generic menu
void drawGenericMenu(const char* title, const char* options[], int selected, int count);

// Напечатать текст по центру экрана | Print centered text
void printCentered(const char* text, uint16_t color);
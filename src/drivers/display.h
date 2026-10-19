#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdint.h>
#include "m5_shim/m5_shim.h" // Подключаем наш C-шим для работы с LCD

#ifdef __cplusplus
extern "C" {
#endif

// Очистка экрана
void clear(void);

// Вывод текста по центру (примерно)
void printCentered(const char* text, uint16_t color);

// Отрисовка главного меню загрузки (Boot Menu)
// options - массив строк, selected - индекс выбранного, count - всего пунктов
void drawBootMenu(const char* options[], int selected, int count);

// Отрисовка универсального меню (для Apps Menu)
void drawGenericMenu(const char* title, const char* items[], int selected, int count);

#ifdef __cplusplus
}
#endif

#endif // DISPLAY_H
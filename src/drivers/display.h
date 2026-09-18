#pragma once
#include <M5Unified.h>

void drawBootMenu(const char* options[], int selected, int count);
void clear();
void printText(const char* text, int x, int y, uint16_t color);
void drawGenericMenu(const char* title, const char* options[], int selected, int count);
void printCentered(const char* text, uint16_t color);
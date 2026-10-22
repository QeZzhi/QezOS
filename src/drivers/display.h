#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdint.h>
#include "m5_shim/m5_shim.h"

#ifdef __cplusplus
extern "C" {
#endif

void clear(void);
void printCentered(const char* text, uint16_t color);
void drawBootMenu(const char* options[], int selected, int count);
void drawGenericMenu(const char* title, const char* options[], int selected, int count);

#ifdef __cplusplus
}
#endif

#endif
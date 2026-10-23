#include "display.h"
#include <string.h>
#include "m5_shim/m5_shim.h"

// Вспомогательная функция для красивого заголовка
static void drawBigTitle(const char* title) {
    qz_canvas_set_text_color(TFT_CYAN);
    qz_canvas_set_text_size(3); // Большой шрифт
    
    // Примерное центрирование (зависит от длины строки)
    // Для 240px ширины, если шрифт 3 (~18px на символ), 
    // "QezOS" (5 символов) = 90px. X = (240-90)/2 = 75.
    // Для длинных строк (например, "Advanced Options Boot") лучше поставить X=10 или 20, 
    // либо уменьшить шрифт до 2.
    
    if (strlen(title) < 10) {
        qz_canvas_set_cursor(80, 5); 
    } else {
        qz_canvas_set_text_size(2); // Для длинных заголовков шрифт поменьше
        qz_canvas_set_cursor(20, 10);
    }
    
    qz_canvas_println(title);
    qz_canvas_set_text_size(1); // Возвращаем нормальный шрифт
}

void drawBootMenu(const char* options[], int selected, int count) {
    qz_canvas_clear(TFT_BLACK); 
    
    drawBigTitle("QezOS");
    
    for (int i = 0; i < count; i++) {
        qz_canvas_set_cursor(20, 45 + (i * 20)); 
        if (i == selected) {
            qz_canvas_set_text_color(TFT_CYAN); 
            qz_canvas_print("> ");
        } else {
            qz_canvas_set_text_color(TFT_WHITE); 
            qz_canvas_print("  ");
        }
        qz_canvas_println(options[i]);
    }
    
    // Обводка
    qz_canvas_draw_rect(0, 0, 240, 135, TFT_CYAN); 
    qz_canvas_draw_rect(1, 1, 238, 133, TFT_CYAN);
    qz_canvas_push();
}

void drawGenericMenu(const char* title, const char* options[], int selected, int count) {
    qz_canvas_clear(TFT_BLACK); 
    
    // Теперь заголовок большой!
    drawBigTitle(title);
    
    for (int i = 0; i < count; i++) {
        qz_canvas_set_cursor(20, 45 + (i * 20)); // Подняли пункты, чтобы влезли под большой заголовок
        if (i == selected) {
            qz_canvas_set_text_color(TFT_CYAN);
            qz_canvas_print("> ");
        } else {
            qz_canvas_set_text_color(TFT_WHITE);
            qz_canvas_print("  ");
        }
        qz_canvas_println(options[i]);
    }
    
    // Обводка
    qz_canvas_draw_rect(0, 0, 240, 135, TFT_CYAN); 
    qz_canvas_draw_rect(1, 1, 238, 133, TFT_CYAN);
    qz_canvas_push();
}

void printCentered(const char* text, uint16_t color) {
    qz_canvas_clear(TFT_BLACK);
    qz_canvas_set_text_color(color);
    qz_canvas_set_cursor(20, 50); 
    qz_canvas_println(text);
    
    qz_canvas_draw_rect(0, 0, 240, 135, TFT_CYAN); 
    qz_canvas_draw_rect(1, 1, 238, 133, TFT_CYAN);
    qz_canvas_push();
}

void clear(void) {
    qz_canvas_clear(TFT_BLACK);
    qz_canvas_push();
}
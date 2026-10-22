#include "display.h"
#include <string.h>
#include "m5_shim/m5_shim.h"

void drawBootMenu(const char* options[], int selected, int count) {
    qz_lcd_start_write(); // НАЧАЛО ПАКЕТА (защита от мерцания)
    
    qz_lcd_fillScreen(TFT_BLACK);
    
    // Заголовок
    qz_lcd_set_text_color(TFT_CYAN);
    qz_lcd_set_text_size(3);
    qz_lcd_set_cursor(80, 5); // Центрируем для повернутого экрана (240 ширина)
    qz_lcd_println("QezOS");
    
    // Пункты меню
    qz_lcd_set_text_size(1);
    for (int i = 0; i < count; i++) {
        qz_lcd_set_cursor(20, 45 + (i * 20)); // Шаг 20 пикселей
        if (i == selected) {
            qz_lcd_set_text_color(TFT_GREEN); 
            qz_lcd_print("> ");
        } else {
            qz_lcd_set_text_color(TFT_WHITE); 
            qz_lcd_print("  ");
        }
        qz_lcd_println(options[i]);
    }
    
    qz_lcd_end_write(); // КОНЕЦ ПАКЕТА (вывод на экран)
}

void drawGenericMenu(const char* title, const char* options[], int selected, int count) {
    qz_lcd_start_write();
    
    qz_lcd_fillScreen(TFT_BLACK); 
    
    qz_lcd_set_text_color(TFT_CYAN);
    qz_lcd_set_cursor(20, 5); 
    qz_lcd_println(title);
    
    for (int i = 0; i < count; i++) {
        qz_lcd_set_cursor(20, 35 + (i * 20)); 
        if (i == selected) {
            qz_lcd_set_text_color(TFT_GREEN);
            qz_lcd_print("> ");
        } else {
            qz_lcd_set_text_color(TFT_WHITE);
            qz_lcd_print("  ");
        }
        qz_lcd_println(options[i]);
    }
    
    qz_lcd_end_write();
}

void printCentered(const char* text, uint16_t color) {
    qz_lcd_start_write();
    qz_lcd_set_text_color(color);
    qz_lcd_set_cursor(20, 50); 
    qz_lcd_println(text);
    qz_lcd_end_write();
}

void clear(void) {
    qz_lcd_start_write();
    qz_lcd_fillScreen(TFT_BLACK);
    qz_lcd_end_write();
}
#ifndef M5_SHIM_H
#define M5_SHIM_H

#define TFT_RED   0xF800
#define TFT_GREEN 0x07E0
#define TFT_BLUE  0x001F
#define TFT_WHITE 0xFFFF
#define TFT_BLACK 0x0000
#define TFT_YELLOW 0xFFE0
#define TFT_CYAN  0x07FF
#define TFT_GRAY  0x8410

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// Кнопки
int qz_btn_a_wasPressed();
int qz_btn_b_wasPressed();

// Базовая инициализация
void qz_m5_begin(void);
void qz_m5_update(void);
void qz_m5_set_rotation(int rotation);

// Дисплей
void qz_lcd_set_text_color(uint16_t color); // (исправил название, чтобы совпадало с .cpp)
void qz_lcd_set_text_size(int size);
void qz_lcd_set_cursor(int x, int y);
void qz_lcd_print(const char* text);
void qz_lcd_println(const char* text);  // Теперь принимает строку!
void qz_lcd_fillScreen(uint16_t color);
void qz_lcd_printf(const char* format, ...);   // Строка формата
int qz_lcd_textWidth(const char* text);
int qz_lcd_fontHeight(void);            // Возвращает int!

// Системное
void qz_speaker_tone(int a, int b);
void qz_speaker_stop();
int qz_esp_getFreeHeap(void);               // Возвращает int!
int qz_battery_level(void);
void qz_esp_restart(void);
int qz_esp_getFlashChipSize();
void delay(uint32_t ms);
uint32_t qz_millis(void);

#ifdef __cplusplus
}
#endif

#endif
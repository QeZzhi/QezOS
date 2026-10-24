#include "M5Unified.h"
#include "m5_shim.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdarg.h>
#include <stdio.h>

static M5Canvas canvas(&M5.Lcd);
static bool canvas_ready = false;

extern "C" void qz_m5_begin(void) { auto cfg = M5.config(); M5.begin(cfg); }
extern "C" void qz_m5_update(void) { M5.update(); }
extern "C" void qz_delay(uint32_t ms) { vTaskDelay(pdMS_TO_TICKS(ms)); }
extern "C" uint32_t qz_millis(void) { return millis(); }
extern "C" int qz_esp_getFreeHeap(void) { return ESP.getFreeHeap(); }
extern "C" int qz_esp_getFlashChipSize(void) { return ESP.getFlashChipSize(); }
extern "C" void qz_esp_restart(void) { ESP.restart(); }
extern "C" void qz_m5_set_rotation(int rotation) { M5.Lcd.setRotation(rotation); }

// Обычный дисплей
extern "C" void qz_lcd_start_write(void) { M5.Lcd.startWrite(); }
extern "C" void qz_lcd_end_write(void) { M5.Lcd.endWrite(); }
extern "C" void qz_lcd_fillScreen(uint16_t color) { M5.Lcd.fillScreen(color); }
extern "C" void qz_lcd_set_text_color(uint16_t color) { M5.Lcd.setTextColor(color); }
extern "C" void qz_lcd_set_text_size(int size) { M5.Lcd.setTextSize(size); }
extern "C" void qz_lcd_set_cursor(int x, int y) { M5.Lcd.setCursor(x, y); }
extern "C" void qz_lcd_print(const char* text) { if (text) M5.Lcd.print(text); }
extern "C" void qz_lcd_println(const char* text) { if (text) M5.Lcd.println(text); }
extern "C" void qz_lcd_printf(const char* format, ...) {
    if (!format) return;
    va_list args; va_start(args, format);
    char buffer[256]; vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args); M5.Lcd.print(buffer);
}
extern "C" void qz_canvas_draw_rect(int32_t x, int32_t y, int32_t w, int32_t h, uint16_t color) { if (canvas_ready) canvas.drawRect(x, y, w, h, color); }

// Canvas
extern "C" void qz_canvas_init(void) {
    canvas.createSprite(240, 135); 
    canvas.setTextWrap(true);
    canvas_ready = true;
}
extern "C" void qz_canvas_clear(uint16_t color) { if (canvas_ready) canvas.fillSprite(color); }
extern "C" void qz_canvas_set_text_color(uint16_t color) { if (canvas_ready) canvas.setTextColor(color); }
extern "C" void qz_canvas_set_text_size(int size) { if (canvas_ready) canvas.setTextSize(size); }
extern "C" void qz_canvas_set_cursor(int x, int y) { if (canvas_ready) canvas.setCursor(x, y); }
extern "C" void qz_canvas_print(const char* text) { if (canvas_ready && text) canvas.print(text); }
extern "C" void qz_canvas_println(const char* text) { if (canvas_ready && text) canvas.println(text); }
extern "C" void qz_canvas_push(void) { if (canvas_ready) canvas.pushSprite(0, 0); }
extern "C" void qz_canvas_printf(const char* format, ...) {
    if (!canvas_ready || !format) return;
    va_list args;
    va_start(args, format);
    char buffer[256];
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);
    canvas.print(buffer);
}
// Кнопки
extern "C" int qz_btn_a_wasPressed(void) { return M5.BtnA.wasPressed() ? 1 : 0; }
extern "C" int qz_btn_b_wasPressed(void) { return M5.BtnB.wasPressed() ? 1 : 0; }
extern "C" int qz_btn_a_wasLongPressed(void) { return M5.BtnA.wasHold() ? 1 : 0; }
extern "C" int qz_btn_a_isPressed(void) { return M5.BtnA.isPressed() ? 1 : 0; }
extern "C" int qz_btn_a_wasReleased(void) { return M5.BtnA.wasReleased() ? 1 : 0; }

// Звук
extern "C" void qz_speaker_stop(void) { M5.Speaker.stop(); }
extern "C" void qz_speaker_tone(int a, int b) { M5.Speaker.tone(a, b); }
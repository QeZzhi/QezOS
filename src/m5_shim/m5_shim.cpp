#include "M5Unified.h"
#include "m5_shim.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

extern "C" uint32_t qz_millis(void) {
    return millis();
}

extern "C" void Delay(uint32_t ms) {
    vTaskDelay(pdMS_TO_TICKS(ms));
}

extern "C" void qz_m5_begin(void) {
    auto cfg = M5.config();
    M5.begin(cfg);
}

extern "C" void qz_m5_update(void) {
    M5.update();
}

extern "C" int qz_esp_getFreeHeap(void) {
    return ESP.getFreeHeap();
}

extern "C" int qz_esp_getFlashChipSize() {
    return ESP.getFlashChipSize();
}

extern "C" void qz_lcd_printf(const char* format, ...) {
    va_list args;
    va_start(args, format);
    char buffer[256];
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);
    M5.Lcd.print(buffer);
}

extern "C" void qz_lcd_println(const char* text) {
    M5.Lcd.println(text);
}

extern "C" void qz_lcd_print(const char* text) {
    M5.Lcd.print(text);
}

extern "C" void qz_lcd_set_text_color(uint16_t color) {
    M5.Lcd.setTextColor(color);
}

extern "C" void qz_lcd_set_text_size(int size) {
    M5.Lcd.setTextSize(size);
}

extern "C" void qz_lcd_set_cursor(int x, int y) {
    M5.Lcd.setCursor(x, y);
}

extern "C" void qz_m5_set_rotation(int rotation) {
    M5.Lcd.setRotation(rotation);
}

extern "C" void qz_lcd_fillScreen(uint16_t color) {
    M5.Lcd.fillScreen(color);
}

extern "C" void qz_speaker_stop() {
    M5.Speaker.stop();
}
extern "C" void qz_speaker_tone(int a, int b) {
    M5.Speaker.tone(a, b);
}

extern "C" int qz_lcd_textWidth(const char* text) {
    return M5.Lcd.textWidth(text);
}

extern "C" int qz_lcd_fontHeight(void) {
    return M5.Lcd.fontHeight();
}

extern "C" int qz_btn_a_wasPressed() {
    return M5.BtnA.wasPressed() ? 1 : 0;
}

extern "C" int qz_btn_b_wasPressed() {
    return M5.BtnB.wasPressed() ? 1 : 0;
}

extern "C" int qz_battery_level(void) {
    return M5.Power.getBatteryLevel();
}

extern "C" void qz_esp_restart(void) {
    ESP.restart();
}
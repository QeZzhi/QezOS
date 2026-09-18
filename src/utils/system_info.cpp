#include "system_info.h"
#include <M5Unified.h>
#include "drivers/display.h"
#include "drivers/buttons.h"
#include "lib/Qlib.h"
#include "core/inc/asm_graphics.h"

void showSystemInfo() {
    clear();
    M5.Lcd.setTextColor(TFT_CYAN);
    M5.Lcd.setCursor(10, 10);
    M5.Lcd.println("=== System Info ===");
    
    M5.Lcd.setTextColor(TFT_WHITE);
    M5.Lcd.setCursor(10, 35);
    M5.Lcd.println("QezOS v0.1");
    
    M5.Lcd.setCursor(10, 55);
    M5.Lcd.println("CPU: ESP32-S3");
    M5.Lcd.setCursor(10, 75);
    M5.Lcd.printf("Freq: %d MHz\n", getCpuFrequencyMhz());
    
    M5.Lcd.setCursor(10, 100);
    M5.Lcd.printf("RAM: %d KB\n", ESP.getFreeHeap() / 1024);
    
    M5.Lcd.setCursor(10, 120);
    M5.Lcd.printf("Flash: %d MB\n", ESP.getFlashChipSize() / 1024 / 1024);
    M5.Lcd.setCursor(10, 140);
    M5.Lcd.printf("Uptime: %d s\n", millis() / 1000);
    M5.Lcd.setTextColor(TFT_GRAY);
    M5.Lcd.setCursor(10, 180);
    M5.Lcd.println("Press B to return");
    while (true) {
        int btn = getButtonPress();
        if (btn == BUTTON_B) {
            return;
        }
        q.wait(100);
    }
}
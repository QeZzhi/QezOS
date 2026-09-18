#include "hardware_test.h"
#include <M5Unified.h>
#include "drivers/display.h"
#include "drivers/buttons.h"
#include "lib/Qlib.h"
#include "core/inc/asm_graphics.h"
#include <apps/advanced.h>

void runHardwareTest() {
    testScreen();
    testButtons();
    testSound();
    testMemory();
    
    clear();
    M5.Lcd.setTextColor(TFT_GREEN);
    M5.Lcd.setCursor(10, 50);
    M5.Lcd.println("Hardware Test");
    M5.Lcd.setCursor(10, 80);
    M5.Lcd.println("COMPLETE!");
    q.wait(2000);
    
    runAdvancedOptionsMenu();
}

void testScreen() {
    
    fill_screen_fast(0xF800);
    q.wait(500);
    
    fill_screen_fast(0x07E0);
    q.wait(500);
    
    fill_screen_fast(0x001F);
    q.wait(500);
    
    fill_screen_fast(0xFFFF);
    q.wait(500);
    
    fill_screen_fast(0x0000);
    q.wait(300);
}

void testButtons() {
    clear();
    M5.Lcd.setTextColor(TFT_WHITE);
    M5.Lcd.setCursor(10, 20);
    M5.Lcd.println("Button Test");
    M5.Lcd.setCursor(10, 60);
    M5.Lcd.setTextColor(TFT_YELLOW);
    M5.Lcd.println("Press A");
    M5.Lcd.setCursor(10, 90);
    M5.Lcd.println("Press B");
    
    bool aPressed = false;
    bool bPressed = false;
    
    while (!aPressed || !bPressed) {
        M5.update();
        
        if (M5.BtnA.wasPressed() && !aPressed) {
            aPressed = true;
            M5.Lcd.setCursor(10, 120);
            M5.Lcd.setTextColor(TFT_GREEN);
            M5.Lcd.println("A: OK");
        }
        
        if (M5.BtnB.wasPressed() && !bPressed) {
            bPressed = true;
            M5.Lcd.setCursor(10, 150);
            M5.Lcd.setTextColor(TFT_GREEN);
            M5.Lcd.println("B: OK");
        }
        
        q.wait(50);
    }
    
    q.wait(1000);
}

void testSound() {
    clear();
    M5.Lcd.setTextColor(TFT_WHITE);
    M5.Lcd.setCursor(10, 20);
    M5.Lcd.println("Sound Test");
    M5.Lcd.setCursor(10, 60);
    M5.Lcd.println("Playing beep...");
    
    M5.Speaker.tone(1000, 200);
    q.wait(500);
    M5.Speaker.tone(2000, 200);
    q.wait(500);
    M5.Speaker.stop();
    
    q.wait(500);
}

void testMemory() {
    clear();
    M5.Lcd.setTextColor(TFT_WHITE);
    M5.Lcd.setCursor(10, 20);
    M5.Lcd.println("Memory Test");
    
    M5.Lcd.setCursor(10, 60);
    M5.Lcd.printf("Free RAM: %d bytes\n", ESP.getFreeHeap());
    M5.Lcd.setCursor(10, 90);
    M5.Lcd.printf("Free RAM: %d KB\n", ESP.getFreeHeap() / 1024);
    M5.Lcd.setCursor(10, 120);
    M5.Lcd.printf("Flash: %d MB\n", ESP.getFlashChipSize() / 1024 / 1024);
    
    q.wait(3000);
}
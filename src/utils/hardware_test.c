#include "hardware_test.h"
#include "m5_shim/m5_shim.h"
#include "drivers/display.h"
#include "drivers/buttons.h"
#include "core/inc/asm_graphics.h"
#include "os/advanced.h"
#include "stdbool.h"
#include <stdarg.h>

void runHardwareTest() {
    testScreen();
    testButtons();
    testSound();
    testMemory();

    clear();
    qz_lcd_set_text_color(TFT_GREEN);
    qz_lcd_set_cursor(10, 50);
    qz_lcd_println("Hardware Test");
    qz_lcd_set_cursor(10, 80);
    qz_lcd_println("COMPLETE!");
    delay(1000);
    
    runAdvancedOptionsMenu();
}

void testScreen() {
    // Используем нашу функцию из шима (m5_shim.h), которая работает через M5Unified
    qz_lcd_fillScreen(0xF800); // Красный
    qz_delay(500);
    
    qz_lcd_fillScreen(0x07E0); // Зеленый
    qz_delay(500);
    
    qz_lcd_fillScreen(0x001F); // Синий
    qz_delay(500);
    
    qz_lcd_fillScreen(0xFFFF); // Белый
    qz_delay(500);
    
    qz_lcd_fillScreen(0x0000); // Черный
    qz_delay(300);
}
void testButtons() {
    clear();
    qz_lcd_set_text_color(TFT_WHITE);
    qz_lcd_set_cursor(10, 30);
    qz_lcd_println("Button Test");
    qz_lcd_set_cursor(10, 60);
    qz_lcd_set_text_color(TFT_YELLOW);
    qz_lcd_println("Press A");
    qz_lcd_set_cursor(10, 90);
    qz_lcd_println("Press B");
    
    bool aPressed = false;
    bool bPressed = false;
    
    while (!aPressed || !bPressed) {
        qz_m5_update();
        
        if (qz_btn_a_wasPressed() && !aPressed) {
            aPressed = true;
            qz_lcd_set_cursor(10, 120);
            qz_lcd_set_text_color(TFT_GREEN);
            qz_lcd_println("A: OK");
        }
        
        if (qz_btn_b_wasPressed() && !bPressed) {
            bPressed = true;
            qz_lcd_set_cursor(10, 150);
            qz_lcd_set_text_color(TFT_GREEN);
            qz_lcd_println("B: OK");
        }
        
        delay(50);
    }
    
    delay(1000);
}

void testSound() {
    clear();
    qz_lcd_set_text_color(TFT_WHITE);
    qz_lcd_set_cursor(10, 20);
    qz_lcd_println("Sound Test");
    qz_lcd_set_cursor(10, 60);
    qz_lcd_println("Playing beep...");
    qz_speaker_tone(1000, 200);
    delay(500);
    qz_speaker_tone(2000, 200);
    delay(500);
    qz_speaker_stop();
    delay(500);
}

void testMemory() {
    clear();
    qz_lcd_set_text_color(TFT_WHITE);
    qz_lcd_set_cursor(10, 20);
    qz_lcd_println("Memory Test");
    
    qz_lcd_set_cursor(10, 60);
    qz_lcd_printf("Free RAM: %d bytes\n", qz_esp_getFreeHeap());
    qz_lcd_set_cursor(10, 90);
    qz_lcd_printf("Free RAM: %d KB\n", qz_esp_getFreeHeap() / 1024);
    qz_lcd_set_cursor(10, 120);
    qz_lcd_printf("Flash: %d MB\n", qz_esp_getFreeHeap() / 1024 / 1024);
    
    delay(3000);
}
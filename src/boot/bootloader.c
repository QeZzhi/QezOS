#include <stdio.h>
#include "bootloader.h"
#include "drivers/display.h"
#include "drivers/buttons.h"
#include "os/os.h" 
#include "m5_shim/m5_shim.h"


void boot_splash(void) {
    qz_canvas_clear(TFT_BLACK); 
    
    // --- Крупная надпись BOOTING ---
    qz_canvas_set_text_color(TFT_CYAN);
    qz_canvas_set_text_size(3); 
    qz_canvas_set_cursor(40, 20); 
    qz_canvas_println("BOOTING");
    qz_canvas_draw_rect(0, 55, 240, 1, TFT_CYAN); 
    qz_canvas_push();
    qz_delay(800); 
    
    qz_canvas_set_text_size(1); 
    
    // --- Строка 1 ---
    qz_canvas_set_cursor(20, 70); // X=20 для текста
    qz_canvas_set_text_color(TFT_WHITE);
    qz_canvas_print("Init CPU...");
    qz_canvas_set_cursor(160, 70); // X=160 для [ OK ] (жестко)
    qz_canvas_set_text_color(TFT_GREEN);
    qz_canvas_println("[ OK ]");
    qz_canvas_push(); 
    qz_delay(500);    
    
    // --- Строка 2 ---
    qz_canvas_set_cursor(20, 85); 
    qz_canvas_set_text_color(TFT_WHITE);
    qz_canvas_print("Init Display...");
    qz_canvas_set_cursor(160, 85); // X=160 для [ OK ]
    qz_canvas_set_text_color(TFT_GREEN);
    qz_canvas_println("[ OK ]");
    qz_canvas_push();
    qz_delay(500);
    
    // --- Строка 3 ---
    qz_canvas_set_cursor(20, 100); 
    qz_canvas_set_text_color(TFT_WHITE);
    qz_canvas_print("Mount FS...");
    qz_canvas_set_cursor(160, 100); // X=160 для [ OK ]
    qz_canvas_set_text_color(TFT_GREEN);
    qz_canvas_println("[ OK ]");
    qz_canvas_push();
    qz_delay(500);
    
    // --- Строка 4 ---
    qz_canvas_set_cursor(20, 115); 
    qz_canvas_set_text_color(TFT_WHITE);
    qz_canvas_print("Start m5_shim...");
    qz_canvas_set_cursor(160, 115); // X=160 для [ OK ]
    qz_canvas_set_text_color(TFT_GREEN);
    qz_canvas_println("[ OK ]");
    qz_canvas_push();
    qz_delay(500);
    
    qz_canvas_clear(TFT_BLACK);
    qz_canvas_push();
}

void bootMenu(void) {
    const char* options[] = {
        "Standart Boot",
        "Advanced Options",
        "Secure Boot",
        "Reboot"
    };
    int selected = 0;
    int count = 4;
    
    while (1) {
        drawBootMenu(options, selected, count);
        
        int btn = getButtonPress();
        
        if (btn == BUTTON_B) { 
            selected = (selected + 1) % count; 
        } 
        else if (btn == BUTTON_UP) {
            selected = (selected - 1 + count) % count; 
        }
        else if (btn == BUTTON_A) { 
            if (selected == 0) { clear(); StandartBoot(); } 
            else if (selected == 1) { clear(); AdvancedOptionsBoot(); } 
            else if (selected == 2) { clear(); SecureBoot(); } 
            else if (selected == 3) { clear(); qz_esp_restart(); }
        }
        qz_delay(100); 
    }
}
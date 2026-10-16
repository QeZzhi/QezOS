// ============================================================
// hardware_test.cpp — тест железа QezOS
// Проверяет экран, кнопки, звук и память M5StickS3.
// hardware_test.cpp — QezOS hardware test
// Checks screen, buttons, sound and memory of M5StickS3.
// ============================================================

#include "hardware_test.h"            // Объявления функций теста | Test function declarations
#include <M5Unified.h>                // M5.Lcd, M5.Speaker, M5.update | M5.Lcd, M5.Speaker, M5.update
#include "drivers/display.h"          // clear | clear
#include "drivers/buttons.h"          // getButtonPress | getButtonPress
#include "lib/Qlib.h"                 // q.wait | q.wait
#include "core/inc/asm_graphics.h"    // fill_screen_fast | fill_screen_fast
#include <apps/advanced.h>            // runAdvancedOptionsMenu | runAdvancedOptionsMenu

// ------------------------------------------------------------
// runHardwareTest — запустить все тесты по очереди
// Экран → кнопки → звук → память, потом возврат в меню
// ------------------------------------------------------------
void runHardwareTest() { // Запуск тестов | Run tests
    testScreen(); // Тест экрана | Screen test
    testButtons(); // Тест кнопок | Button test
    testSound(); // Тест звука | Sound test
    testMemory(); // Тест памяти | Memory test
    
    clear(); // Очищаем экран | Clear screen
    M5.Lcd.setTextColor(TFT_GREEN); // Зелёный цвет | Green color
    M5.Lcd.setCursor(10, 50); // Курсор | Cursor
    M5.Lcd.println("Hardware Test"); // Надпись «Hardware Test» | Message "Hardware Test"
    M5.Lcd.setCursor(10, 80); // Курсор ниже | Cursor below
    M5.Lcd.println("COMPLETE!"); // Надпись «COMPLETE!» | Message "COMPLETE!"
    q.wait(2000); // Пауза 2 сек | 2 sec delay
    
    runAdvancedOptionsMenu(); // Возврат в расширенное меню | Return to advanced menu
}

// ------------------------------------------------------------
// testScreen — тест экрана
// Заливает экран разными цветами: красный, зелёный, синий, белый, чёрный
// ------------------------------------------------------------
void testScreen() { // Тест экрана | Screen test
    fill_screen_fast(0xF800); // Красный (RGB565: F800) | Red (RGB565: F800)
    q.wait(500); // Пауза 0.5 сек | 0.5 sec delay
    
    fill_screen_fast(0x07E0); // Зелёный (07E0) | Green (07E0)
    q.wait(500); // Пауза | Delay
    
    fill_screen_fast(0x001F); // Синий (001F) | Blue (001F)
    q.wait(500); // Пауза | Delay
    
    fill_screen_fast(0xFFFF); // Белый (FFFF) | White (FFFF)
    q.wait(500); // Пауза | Delay
    
    fill_screen_fast(0x0000); // Чёрный (0000) | Black (0000)
    q.wait(300); // Пауза 0.3 сек | 0.3 sec delay
}

// ------------------------------------------------------------
// testButtons — тест кнопок
// Просит нажать A и B, ждёт пока обе не будут нажаты
// ------------------------------------------------------------
void testButtons() { // Тест кнопок | Button test
    clear(); // Очищаем экран | Clear screen
    M5.Lcd.setTextColor(TFT_WHITE); // Белый цвет | White color
    M5.Lcd.setCursor(10, 20); // Курсор | Cursor
    M5.Lcd.println("Button Test"); // Заголовок | Title
    M5.Lcd.setCursor(10, 60); // Курсор ниже | Cursor below
    M5.Lcd.setTextColor(TFT_YELLOW); // Жёлтый цвет | Yellow color
    M5.Lcd.println("Press A"); // Просьба нажать A | Ask to press A
    M5.Lcd.setCursor(10, 90); // Курсор ниже | Cursor below
    M5.Lcd.println("Press B"); // Просьба нажать B | Ask to press B
    
    bool aPressed = false; // A ещё не нажата | A not pressed yet
    bool bPressed = false; // B ещё не нажата | B not pressed yet
    
    while (!aPressed || !bPressed) { // Пока обе не нажаты | While both not pressed
        M5.update(); // Обновляем состояние кнопок | Update button state
        
        if (M5.BtnA.wasPressed() && !aPressed) { // Если A нажата впервые | If A pressed first time
            aPressed = true; // Помечаем | Mark
            M5.Lcd.setCursor(10, 120); // Курсор | Cursor
            M5.Lcd.setTextColor(TFT_GREEN); // Зелёный | Green
            M5.Lcd.println("A: OK"); // Надпись «A: OK» | Message "A: OK"
        }
        
        if (M5.BtnB.wasPressed() && !bPressed) { // Если B нажата впервые | If B pressed first time
            bPressed = true; // Помечаем | Mark
            M5.Lcd.setCursor(10, 150); // Курсор | Cursor
            M5.Lcd.setTextColor(TFT_GREEN); // Зелёный | Green
            M5.Lcd.println("B: OK"); // Надпись «B: OK» | Message "B: OK"
        }
        
        q.wait(50); // Пауза 50 мс (антидребезг) | 50 ms delay (debounce)
    }
    
    q.wait(1000); // Пауза 1 сек | 1 sec delay
}

// ------------------------------------------------------------
// testSound — тест звука
// Проигрывает два тона: 1000 Гц и 2000 Гц
// ------------------------------------------------------------
void testSound() { // Тест звука | Sound test
    clear(); // Очищаем экран | Clear screen
    M5.Lcd.setTextColor(TFT_WHITE); // Белый цвет | White color
    M5.Lcd.setCursor(10, 20); // Курсор | Cursor
    M5.Lcd.println("Sound Test"); // Заголовок | Title
    M5.Lcd.setCursor(10, 60); // Курсор ниже | Cursor below
    M5.Lcd.println("Playing beep..."); // Надпись | Message
    
    M5.Speaker.tone(1000, 200); // Тон 1000 Гц, 200 мс | Tone 1000 Hz, 200 ms
    q.wait(500); // Пауза | Delay
    M5.Speaker.tone(2000, 200); // Тон 2000 Гц, 200 мс | Tone 2000 Hz, 200 ms
    q.wait(500); // Пауза | Delay
    M5.Speaker.stop(); // Останавливаем динамик | Stop speaker
    
    q.wait(500); // Пауза | Delay
}

// ------------------------------------------------------------
// testMemory — тест памяти
// Показывает свободную RAM и размер Flash
// ------------------------------------------------------------
void testMemory() { // Тест памяти | Memory test
    clear(); // Очищаем экран | Clear screen
    M5.Lcd.setTextColor(TFT_WHITE); // Белый цвет | White color
    M5.Lcd.setCursor(10, 20); // Курсор | Cursor
    M5.Lcd.println("Memory Test"); // Заголовок | Title
    
    M5.Lcd.setCursor(10, 60); // Курсор ниже | Cursor below
    M5.Lcd.printf("Free RAM: %d bytes\n", ESP.getFreeHeap()); // Свободная RAM в байтах | Free RAM in bytes
    M5.Lcd.setCursor(10, 90); // Курсор ниже | Cursor below
    M5.Lcd.printf("Free RAM: %d KB\n", ESP.getFreeHeap() / 1024); // Свободная RAM в КБ | Free RAM in KB
    M5.Lcd.setCursor(10, 120); // Курсор ниже | Cursor below
    M5.Lcd.printf("Flash: %d MB\n", ESP.getFlashChipSize() / 1024 / 1024); // Размер Flash в МБ | Flash size in MB
    
    q.wait(3000); // Пауза 3 сек | 3 sec delay
}
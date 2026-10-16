// ============================================================
// display.cpp — работа с дисплеем M5StickS3
// Рисование меню, очистка экрана, вывод текста.
// display.cpp — display handling for M5StickS3
// Drawing menus, clearing screen, printing text.
// ============================================================

#include "display.h"                  // Объявления функций дисплея | Display function declarations
#include "core/inc/asm_graphics.h"    // fill_screen_fast (ассемблер) | fill_screen_fast (assembly)

// ------------------------------------------------------------
// drawBootMenu — нарисовать меню загрузчика
// options — массив пунктов, selected — выбранный, count — всего
// ------------------------------------------------------------
void drawBootMenu(const char* options[], int selected, int count) { // Меню загрузки | Boot menu
    clear(); // Очищаем экран | Clear screen
    M5.Lcd.setTextColor(TFT_WHITE); // Белый цвет текста | White text color
    M5.Lcd.setCursor(10, 20); // Курсор в (10, 20) | Cursor at (10, 20)
    M5.Lcd.println("|-----QezOS Boot Menu-----|"); // Заголовок меню | Menu title
    
    for (int i = 0; i < count; i++) { // Проходим по всем пунктам | Loop over all items
        M5.Lcd.setCursor(20, 60 + i * 30); // Курсор для i-го пункта | Cursor for i-th item
        if (i == selected) { // Если пункт выбран | If item is selected
            M5.Lcd.setTextColor(TFT_YELLOW); // Жёлтый цвет | Yellow color
            M5.Lcd.print("> "); // Стрелка выбора | Selection arrow
        } else { // Иначе | Otherwise
            M5.Lcd.setTextColor(TFT_GRAY); // Серый цвет | Gray color
            M5.Lcd.print("  "); // Отступ | Indent
        }
        M5.Lcd.println(options[i]); // Печатаем текст пункта | Print item text
    }
}

// ------------------------------------------------------------
// drawGenericMenu — нарисовать универсальное меню
// title — заголовок, options — пункты, selected — выбранный
// ------------------------------------------------------------
void drawGenericMenu(const char* title, const char* options[], int selected, int count) { // Универсальное меню | Generic menu
    clear(); // Очищаем экран | Clear screen
    M5.Lcd.setTextColor(TFT_WHITE); // Белый цвет текста | White text color
    M5.Lcd.setCursor(10, 20); // Курсор в (10, 20) | Cursor at (10, 20)
    M5.Lcd.println(title); // Печатаем заголовок | Print title
    
    for (int i = 0; i < count; i++) { // Проходим по всем пунктам | Loop over all items
        M5.Lcd.setCursor(20, 60 + i * 30); // Курсор для i-го пункта | Cursor for i-th item
        if (i == selected) { // Если пункт выбран | If item is selected
            M5.Lcd.setTextColor(TFT_CYAN); // Голубой цвет | Cyan color
            M5.Lcd.print("> "); // Стрелка выбора | Selection arrow
        } else { // Иначе | Otherwise
            M5.Lcd.setTextColor(TFT_GRAY); // Серый цвет | Gray color
            M5.Lcd.print("  "); // Отступ | Indent
        }
        M5.Lcd.println(options[i]); // Печатаем текст пункта | Print item text
    }
}

// ------------------------------------------------------------
// clear — очистить экран (быстро, через ассемблер)
// ------------------------------------------------------------
void clear() { // Очистка экрана | Clear screen
    fill_screen_fast(0x0000); // Заливаем чёрным через ассемблер | Fill black via assembly
}

// ------------------------------------------------------------
// setColor — залить экран цветом
// ------------------------------------------------------------
void setColor(uint16_t color) { // Установка цвета | Set color
    M5.Lcd.fillScreen(color); // Заливаем экран цветом | Fill screen with color
}

// ------------------------------------------------------------
// printText — напечатать текст в заданной позиции
// text — текст, x, y — координаты, color — цвет
// ------------------------------------------------------------
void printText(const char* text, int x, int y, uint16_t color) { // Печать текста | Print text
    M5.Lcd.setTextColor(color); // Цвет текста | Text color
    M5.Lcd.setCursor(x, y); // Курсор в (x, y) | Cursor at (x, y)
    M5.Lcd.println(text); // Печатаем текст | Print text
}

// ------------------------------------------------------------
// printCentered — напечатать текст по центру экрана
// text — текст, color — цвет
// ------------------------------------------------------------
void printCentered(const char* text, uint16_t color) { // Центрированный текст | Centered text
    M5.Lcd.setTextColor(color); // Цвет текста | Text color
    int textWidth = M5.Lcd.textWidth(text); // Ширина текста | Text width
    int textHeight = M5.Lcd.fontHeight(); // Высота текста | Text height
    int x = (135 - textWidth) / 2; // X по центру | X centered
    int y = (240 - textHeight) / 2; // Y по центру | Y centered
    M5.Lcd.setCursor(x, y); // Курсор в центр | Cursor to center
    M5.Lcd.println(text); // Печатаем текст | Print text
}
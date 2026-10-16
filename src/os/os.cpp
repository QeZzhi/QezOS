// ============================================================
// os.cpp — логика загрузки QezOS
// Показывает экран загрузки и запускает выбранное меню.
// os.cpp — QezOS boot logic
// Shows boot screen and runs the selected menu.
// ============================================================

#include "os.h"                // Объявления StandartBoot, AdvancedOptionsBoot, SecureBoot | Declarations of StandartBoot, AdvancedOptionsBoot, SecureBoot
#include <M5Unified.h>         // M5.Lcd, TFT_* | M5.Lcd, TFT_*
#include "lib/Qlib.h"          // q.wait | q.wait
#include "drivers/display.h"   // clear | clear
#include "apps/standart.h"     // runStandartMenu | runStandartMenu
#include "apps/secure.h"       // runSecureMenu | runSecureMenu
#include "apps/advanced.h"     // runAdvancedOptionsMenu | runAdvancedOptionsMenu

// ------------------------------------------------------------
// StandartBoot — стандартная загрузка QezOS
// Показывает экран «Standard Boot...» и запускает меню приложений
// ------------------------------------------------------------
void StandartBoot() { // Стандартная загрузка | Standard boot
    clear(); // Очищаем экран | Clear screen
    M5.Lcd.setTextColor(TFT_WHITE); // Белый цвет | White color
    M5.Lcd.setCursor(20, 50); // Курсор в (20, 50) | Cursor at (20, 50)
    M5.Lcd.println("QezOS Standard Boot..."); // Надпись | Message
    q.wait(1000); // Пауза 1 сек | 1 sec delay
    clear(); // Очищаем экран | Clear screen
    runStandartMenu(); // Запускаем меню приложений | Run apps menu
}

// ------------------------------------------------------------
// AdvancedOptionsBoot — расширенная загрузка QezOS
// Показывает экран «Advanced Options Boot...» и запускает меню
// ------------------------------------------------------------
void AdvancedOptionsBoot() { // Расширенная загрузка | Advanced boot
    clear(); // Очищаем экран | Clear screen
    M5.Lcd.setTextColor(TFT_YELLOW); // Жёлтый цвет | Yellow color
    M5.Lcd.setCursor(20, 50); // Курсор в (20, 50) | Cursor at (20, 50)
    M5.Lcd.println("QezOS Advanced Options Boot..."); // Надпись | Message
    q.wait(1000); // Пауза 1 сек | 1 sec delay
    clear(); // Очищаем экран | Clear screen
    runAdvancedOptionsMenu(); // Запускаем расширенное меню | Run advanced menu
    } // ← ЛИШНИЙ ОТСТУП (не критично, но стиль) | Extra indent (not critical, but style)

// ------------------------------------------------------------
// SecureBoot — безопасная загрузка QezOS
// Показывает экран «Secure Boot...» и запускает меню Secure
// ------------------------------------------------------------
void SecureBoot() { // Безопасная загрузка | Secure boot
    clear(); // Очищаем экран | Clear screen
    M5.Lcd.setTextColor(TFT_GREEN); // Зелёный цвет | Green color
    M5.Lcd.setCursor(20, 50); // Курсор в (20, 50) | Cursor at (20, 50)
    M5.Lcd.println("QezOS Secure Boot..."); // Надпись | Message
    q.wait(1000); // Пауза 1 сек | 1 sec delay
    clear(); // Очищаем экран | Clear screen
    runSecureMenu(); // Запускаем меню Secure | Run Secure menu
}
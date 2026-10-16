// ============================================================
// Qlib.h — заголовок Qlib для QezOS
// Класс Q даёт удобные функции: wait, print, println.
// Qlib.h — Qlib header for QezOS
// Class Q provides convenient functions: wait, print, println.
// ============================================================

#ifndef QLIB_H // Если QLIB_H ещё не определён | If QLIB_H is not defined yet
#define QLIB_H // Определяем QLIB_H | Define QLIB_H
#include <string> // ← НЕ НУЖЕН (ты не используешь std::string) | NOT NEEDED (you don't use std::string)
#include <M5Unified.h> // Нужен для M5, delay | Need for M5, delay

// ------------------------------------------------------------
// Q — класс-обёртка для QezOS
// Даёт удобные функции: wait, print, println
// ------------------------------------------------------------
class Q { // Класс Q | Class Q
public: // Публичные методы | Public methods
    void wait(int time); // Пауза | Wait
    void print(const char* text); // Печать без переноса | Print without newline
    void println(const char* text); // Печать с переносом | Print with newline
    bool boot_select[3]; // Массив выбора загрузки (не используется) | Boot selection array (unused)
};

// ------------------------------------------------------------
// Глобальный объект q
// Используется во всех меню QezOS
// ------------------------------------------------------------
extern Q q; // Объявление глобального q | Declaration of global q

#endif // Конец include guard | End of include guard
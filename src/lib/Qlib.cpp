// ============================================================
// Qlib.cpp — реализация Qlib (обёртки для QezOS)
// Класс Q даёт удобные функции: wait, print, println.
// Qlib.cpp — Qlib implementation (wrappers for QezOS)
// Class Q provides convenient functions: wait, print, println.
// ============================================================

#include <M5Unified.h>        // delay, M5 | delay, M5
#include "Qlib.h"             // Класс Q | Class Q
#include <iostream>           // (не используется, можно убрать) | (unused, can be removed)
#include "drivers/display.h"  // Функции дисплея | Display functions

// ------------------------------------------------------------
// Q::wait — пауза на time миллисекунд
// ------------------------------------------------------------
void Q::wait(int time) { // Пауза | Wait
    delay(time); // Arduino delay | Arduino delay
}

// ------------------------------------------------------------
// Q::print — напечатать текст (без переноса строки)
// ВНИМАНИЕ: вызывает q.println, а не q.print — это баг!
// ------------------------------------------------------------
void Q::print(const char *text) { // Печать | Print
    q.println(text); // ← БАГ: должно быть q.print, а не q.println | BUG: should be q.print, not q.println
}

// ------------------------------------------------------------
// Q::println — напечатать текст с переносом строки
// ------------------------------------------------------------
void Q::println(const char *text) { // Печать с новой строкой | Print with newline
    q.println(text); // ← РЕКУРСИЯ: вызывает сам себя! | RECURSION: calls itself!
}

// ------------------------------------------------------------
// Глобальный объект q
// Используется во всех меню QezOS: q.wait(100), q.print("...")
// ------------------------------------------------------------
Q q; // Глобальный экземпляр | Global instance
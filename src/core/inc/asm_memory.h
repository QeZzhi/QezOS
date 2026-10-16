// ============================================================
// asm_memory.h — заголовок ассемблерных функций памяти
// Быстрые замены стандартных memcpy, memset, memcmp, memmove.
// asm_memory.h — assembly memory functions header
// Fast replacements for standard memcpy, memset, memcmp, memmove.
// ============================================================

#ifndef ASM_MEMORY_H // Если ASM_MEMORY_H ещё не определён | If ASM_MEMORY_H is not defined yet
#define ASM_MEMORY_H // Определяем ASM_MEMORY_H | Define ASM_MEMORY_H

#include <stddef.h> // Нужен тип size_t | Need size_t type

#ifdef __cplusplus // Если компилируется как C++ | If compiled as C++
extern "C" { // Отключаем искажение имён | Disable name mangling
#endif

// ------------------------------------------------------------
// Копирование и заполнение памяти
// ------------------------------------------------------------

// Копировать n байт из src в dest | Copy n bytes from src to dest
void* memcpy_fast(void* dest, const void* src, size_t n);

// Заполнить n байт значением value | Fill n bytes with value
void* memset_fast(void* dest, int value, size_t n);

// Сравнить n байт двух областей | Compare n bytes of two regions
int memcmp_fast(const void* a, const void* b, size_t n);

// Переместить n байт (с защитой от перекрытия) | Move n bytes (overlap-safe)
void* memmove_fast(void* dest, const void* src, size_t n);

#ifdef __cplusplus // Если компилируется как C++ | If compiled as C++
} // Закрываем extern "C" | Close extern "C"
#endif

#endif // Конец include guard | End of include guard
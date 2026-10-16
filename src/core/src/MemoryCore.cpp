// ============================================================
// MemoryCore.cpp — обёртка над ассемблерной памятью
// Класс MemoryCore вызывает asm_memory.h из C++.
// MemoryCore.cpp — wrapper over assembly memory
// Class MemoryCore calls asm_memory.h from C++.
// ============================================================

#include "MemoryCore.h"            // Объявление класса MemoryCore | MemoryCore class declaration
#include "core/inc/asm_memory.h"   // Ассемблерные функции памяти | Assembly memory functions

namespace core { // Пространство имён core | Namespace core

// ------------------------------------------------------------
// MemoryCore::copy — копировать n байт
// ------------------------------------------------------------
void* MemoryCore::copy(void* dest, const void* src, size_t n) { // Копировать | Copy
    return memcpy_fast(dest, src, n); // Вызываем ассемблерную функцию | Call assembly function
}

// ------------------------------------------------------------
// MemoryCore::set — заполнить n байт значением
// ------------------------------------------------------------
void* MemoryCore::set(void* dest, int value, size_t n) { // Заполнить | Set
    return memset_fast(dest, value, n); // Вызываем ассемблерную функцию | Call assembly function
}

// ------------------------------------------------------------
// MemoryCore::compare — сравнить n байт
// ------------------------------------------------------------
int MemoryCore::compare(const void* a, const void* b, size_t n) { // Сравнить | Compare
    return memcmp_fast(a, b, n); // Вызываем ассемблерную функцию | Call assembly function
}

// ------------------------------------------------------------
// MemoryCore::move — переместить n байт (безопасно при перекрытии)
// ------------------------------------------------------------
void* MemoryCore::move(void* dest, const void* src, size_t n) { // Переместить | Move
    return memmove_fast(dest, src, n); // Вызываем ассемблерную функцию | Call assembly function
}

} // Конец namespace core | End of namespace core
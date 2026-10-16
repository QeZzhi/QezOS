// ============================================================
// MemoryCore.h — заголовок обёртки над ассемблерной памятью
// Класс MemoryCore вызывает asm_memory.h из C++.
// MemoryCore.h — wrapper header over assembly memory
// Class MemoryCore calls asm_memory.h from C++.
// ============================================================

#ifndef MEMORY_CORE_H // Если MEMORY_CORE_H ещё не определён | If MEMORY_CORE_H is not defined yet
#define MEMORY_CORE_H // Определяем MEMORY_CORE_H | Define MEMORY_CORE_H

#include <cstddef> // Нужен тип size_t | Need size_t type

namespace core { // Пространство имён core | Namespace core

// ------------------------------------------------------------
// MemoryCore — статический класс-обёртка над asm_memory.h
// Все методы статические — объект создавать не надо
// ------------------------------------------------------------
class MemoryCore { // Класс MemoryCore | Class MemoryCore
public: // Публичные методы | Public methods
    
    // Копировать n байт из src в dest | Copy n bytes from src to dest
    static void* copy(void* dest, const void* src, size_t n);
    
    // Заполнить n байт значением value | Fill n bytes with value
    static void* set(void* dest, int value, size_t n);
    
    // Сравнить n байт двух областей | Compare n bytes of two regions
    static int   compare(const void* a, const void* b, size_t n);
    
    // Переместить n байт (безопасно при перекрытии) | Move n bytes (overlap-safe)
    static void* move(void* dest, const void* src, size_t n);
};

} // Конец namespace core | End of namespace core

#endif // Конец include guard | End of include guard
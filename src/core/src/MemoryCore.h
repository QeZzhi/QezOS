#ifndef MEMORY_CORE_H
#define MEMORY_CORE_H

#include <cstddef>

namespace core {

class MemoryCore {
public:
    static void* copy(void* dest, const void* src, size_t n);
    static void* set(void* dest, int value, size_t n);
    static int   compare(const void* a, const void* b, size_t n);
    static void* move(void* dest, const void* src, size_t n);
};

} // namespace core

#endif
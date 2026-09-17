#include "MemoryCore.h"
#include "core/inc/asm_memory.h"

namespace core {

void* MemoryCore::copy(void* dest, const void* src, size_t n) {
    return memcpy_fast(dest, src, n);
}

void* MemoryCore::set(void* dest, int value, size_t n) {
    return memset_fast(dest, value, n);
}

int MemoryCore::compare(const void* a, const void* b, size_t n) {
    return memcmp_fast(a, b, n);
}

void* MemoryCore::move(void* dest, const void* src, size_t n) {
    return memmove_fast(dest, src, n);
}

} // namespace core
#ifndef ASM_MEMORY_H
#define ASM_MEMORY_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

void* memcpy_fast(void* dest, const void* src, size_t n);
void* memset_fast(void* dest, int value, size_t n);
int   memcmp_fast(const void* a, const void* b, size_t n);
void* memmove_fast(void* dest, const void* src, size_t n);

#ifdef __cplusplus
}
#endif

#endif
// ============================================================
// asm_math.h — заголовок ассемблерных математических функций
// Быстрые функции для математики (написаны на .S).
// asm_math.h — assembly math functions header
// Fast functions for math (written in .S).
// ============================================================

#ifndef ASM_MATH_H // Если ASM_MATH_H ещё не определён | If ASM_MATH_H is not defined yet
#define ASM_MATH_H // Определяем ASM_MATH_H | Define ASM_MATH_H

#ifdef __cplusplus // Если компилируется как C++ | If compiled as C++
extern "C" { // Отключаем искажение имён | Disable name mangling
#endif

// ------------------------------------------------------------
// Базовые операции
// ------------------------------------------------------------

// Модуль числа | Absolute value
int fast_abs_int(int x);

// Минимум из двух чисел | Minimum of two numbers
int fast_min_int(int a, int b);

// Максимум из двух чисел | Maximum of two numbers
int fast_max_int(int a, int b);

// ------------------------------------------------------------
// Векторы (3D)
// ------------------------------------------------------------

// Скалярное произведение векторов | Dot product of vectors
int vec3_dot(int* a, int* b);

// Сложение векторов | Vector addition
void vec3_add(int* out, int* a, int* b);

// ------------------------------------------------------------
// Числа с фиксированной точкой (fixed-point)
// ------------------------------------------------------------

// Умножение fixed-point чисел | Fixed-point multiplication
int fixed_mul(int a, int b);

// Деление fixed-point чисел | Fixed-point division
int fixed_div(int a, int b);

#ifdef __cplusplus // Если компилируется как C++ | If compiled as C++
} // Закрываем extern "C" | Close extern "C"
#endif

#endif // Конец include guard | End of include guard
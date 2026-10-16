// ============================================================
// MathCore.cpp — обёртка над ассемблерной математикой
// Класс MathCore вызывает asm_math.h из C++.
// MathCore.cpp — wrapper over assembly math
// Class MathCore calls asm_math.h from C++.
// ============================================================

#include "MathCore.h"            // Объявление класса MathCore | MathCore class declaration
#include "core/inc/asm_math.h"   // Ассемблерные математические функции | Assembly math functions

namespace core { // Пространство имён core | Namespace core

// ------------------------------------------------------------
// MathCore::abs — модуль числа
// ------------------------------------------------------------
int MathCore::abs(int x) { // Модуль | Absolute value
    return fast_abs_int(x); // Вызываем ассемблерную функцию | Call assembly function
}

// ------------------------------------------------------------
// MathCore::min — минимум из двух чисел
// ------------------------------------------------------------
int MathCore::min(int a, int b) { // Минимум | Minimum
    return fast_min_int(a, b); // Вызываем ассемблерную функцию | Call assembly function
}

// ------------------------------------------------------------
// MathCore::max — максимум из двух чисел
// ------------------------------------------------------------
int MathCore::max(int a, int b) { // Максимум | Maximum
    return fast_max_int(a, b); // Вызываем ассемблерную функцию | Call assembly function
}

// ------------------------------------------------------------
// MathCore::fixedMul — умножение fixed-point чисел
// ------------------------------------------------------------
int MathCore::fixedMul(int a, int b) { // Умножение fixed-point | Fixed-point multiplication
    return fixed_mul(a, b); // Вызываем ассемблерную функцию | Call assembly function
}

// ------------------------------------------------------------
// MathCore::fixedDiv — деление fixed-point чисел
// ------------------------------------------------------------
int MathCore::fixedDiv(int a, int b) { // Деление fixed-point | Fixed-point division
    return fixed_div(a, b); // Вызываем ассемблерную функцию | Call assembly function
}

} // Конец namespace core | End of namespace core
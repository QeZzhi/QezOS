// ============================================================
// MathCore.h — заголовок обёртки над ассемблерной математикой
// Класс MathCore вызывает asm_math.h из C++.
// MathCore.h — wrapper header over assembly math
// Class MathCore calls asm_math.h from C++.
// ============================================================

#ifndef MATH_CORE_H // Если MATH_CORE_H ещё не определён | If MATH_CORE_H is not defined yet
#define MATH_CORE_H // Определяем MATH_CORE_H | Define MATH_CORE_H

namespace core { // Пространство имён core | Namespace core

// ------------------------------------------------------------
// MathCore — статический класс-обёртка над asm_math.h
// Все методы статические — объект создавать не надо
// ------------------------------------------------------------
class MathCore { // Класс MathCore | Class MathCore
public: // Публичные методы | Public methods
    
    // Модуль числа | Absolute value
    static int abs(int x);
    
    // Минимум из двух чисел | Minimum of two numbers
    static int min(int a, int b);
    
    // Максимум из двух чисел | Maximum of two numbers
    static int max(int a, int b);
    
    // Умножение fixed-point чисел | Fixed-point multiplication
    static int fixedMul(int a, int b);
    
    // Деление fixed-point чисел | Fixed-point division
    static int fixedDiv(int a, int b);
};

} // Конец namespace core | End of namespace core

#endif // Конец include guard | End of include guard
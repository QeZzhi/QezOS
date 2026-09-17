#ifndef MATH_CORE_H
#define MATH_CORE_H

namespace core {

class MathCore {
public:
    static int abs(int x);
    static int min(int a, int b);
    static int max(int a, int b);
    static int fixedMul(int a, int b);
    static int fixedDiv(int a, int b);
};

} // namespace core

#endif
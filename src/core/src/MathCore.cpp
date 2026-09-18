#include "MathCore.h"
#include "core/inc/asm_math.h"

namespace core {

int MathCore::abs(int x) {
    return fast_abs_int(x);
}

int MathCore::min(int a, int b) {
    return fast_min_int(a, b);
}

int MathCore::max(int a, int b) {
    return fast_max_int(a, b);
}

int MathCore::fixedMul(int a, int b) {
    return fixed_mul(a, b);
}

int MathCore::fixedDiv(int a, int b) {
    return fixed_div(a, b);
}

}
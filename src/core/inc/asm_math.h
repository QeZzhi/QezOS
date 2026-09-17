#ifndef ASM_MATH_H
#define ASM_MATH_H

#ifdef __cplusplus
extern "C" {
#endif

int fast_abs_int(int x);
int fast_min_int(int a, int b);
int fast_max_int(int a, int b);

int vec3_dot(int* a, int* b);
void vec3_add(int* out, int* a, int* b);

int fixed_mul(int a, int b);
int fixed_div(int a, int b);

#ifdef __cplusplus
}
#endif

#endif
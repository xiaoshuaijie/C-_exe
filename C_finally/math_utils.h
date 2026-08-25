// math_utils.h
#pragma once
/**
 * @brief 返回两个值中的最大值
 *
 */
//__typeof__ 是 gcc 内置的取类型运算符。
#define MAX(a, b)           \
  ({                        \
    __typeof__(a) _a = (a); \
    __typeof__(b) _b = (b); \
    _a > _b ? _a : _b;      \
  })

/**
 * @brief 返回两个值中的最小值
 *
 */
#define MIN(a, b)           \
  ({                        \
    __typeof__(a) _a = (a); \
    __typeof__(b) _b = (b); \
    _a < _b ? _a : _b;      \
  })


void clamp_int(int *value, int min_val,int max_val);

/**
 * @brief Print and return the number of decimal digits in an integer.
 *
 * The sign is not counted. Zero has one digit.
 */
int count_digits(int value);

// int main(void) {
//     // 练习： 调用两个函数，验证结果
//     return 0;
// }

//gcc -std=gnu11 -Wall -Wextra main.c math_utils.c -o main

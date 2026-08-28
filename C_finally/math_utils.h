#pragma once
/**
 * @brief 返回两个值中的最大值
 *
 */
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


void clamp_int(int *value, int min_val, int max_val);

/**
 * @brief 返回一个整数十进制位数
 *
 * 不计符号位；0 的位数为 1。
 */
int count_digits(int value);
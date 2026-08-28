#include "math_utils.h"

void clamp_int(int *value, int min_val, int max_val)
{
    *value = MAX(min_val, MIN(*value, max_val));
}

int count_digits(int value)
{
    int digits = 0;

    do {
        ++digits;
        value /= 10;
    } while (value != 0);

    return digits;
}
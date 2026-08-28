#include <stdio.h>

#include "math_utils.h"

int main(void)
{
    int value;

    value = 5;
    clamp_int(&value, 0, 10);
    printf("clamp_int(5, 0, 10) = %d\n", value);

    value = 100;
    clamp_int(&value, 0, 10);
    printf("clamp_int(100, 0, 10) = %d\n", value);

    printf("count_digits(42) = %d\n", count_digits(42));
    printf("count_digits(-12345) = %d\n", count_digits(-12345));

    puts("All tests passed.");
    return 0;
}
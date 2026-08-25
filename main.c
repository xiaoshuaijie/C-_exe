#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    printf("=== C: sizeof 表达式验证 ===\n");
    printf("sizeof('A')   = %zu\n", sizeof('A'));
    printf("sizeof(true)  = %zu\n", sizeof(true));
    printf("sizeof(3.14)  = %zu\n", sizeof(3.14));
    printf("sizeof(3.14f) = %zu\n", sizeof(3.14f));
    printf("sizeof(3.14L) = %zu\n", sizeof(3.14L));
    return 0;
}

#pragma once

#include <stdio.h>

/* 默认开启日志；编译时用 -DNDEBUG 可关闭 */
#ifdef NDEBUG
    #define DEBUG_LOG(fmt, ...)  ((void)(0))
#else
    #define DEBUG_LOG(fmt, ...) \
        fprintf(stderr, "[%s:%d] " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#endif
//gcc -std=gnu11 -Wall -Wextra main.c -o main
// gcc -std=gnu11 -Wall -Wextra  -DNDEBUG  -Wno-unused-variable  main.c -o main
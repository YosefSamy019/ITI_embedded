//
// Created by asus on 2024-07-02.
//

#ifndef MAIN_C_DEBUG_H
#define MAIN_C_DEBUG_H

#include "stdio.h"

#define ENABLE_DEBUG ((volatile int)0)

#define PRINT_DEBUG(str, ...)                                                                           \
    if (ENABLE_DEBUG > 0)                                                                               \
        do {                                                                                            \
            printf("\033[1;32m[DEBUG INFO] [FILE %s] [LINE %d] [MSG \"%s\"]", __FILE__, __LINE__, str); \
            printf(str, __VA_ARGS__);                                                                   \
            printf("\n\n");                                                                             \
    } while (0)


#endif //MAIN_C_DEBUG_H

#include <stdio.h>

#include "STD_TYPES.h"

#define PRINT(dt) printf("Size of %4s is %d Byte\n", #dt , sizeof(dt))

void main(void) {
    PRINT(u8);
    PRINT(s8);
    
    PRINT(u16);
    PRINT(s16);
    
    PRINT(u32);
    PRINT(s32);
    
    PRINT(u64);
    PRINT(s64);

    PRINT(f32);
    PRINT(f64);
}
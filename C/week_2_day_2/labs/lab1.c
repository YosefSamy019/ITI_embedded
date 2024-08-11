#include <stdio.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

void main(void){
    u8 n = 0x00;
    
    printf("X=%X\n",n);
    
    SET_BIT(n,1);
    
    printf("X=%X\n",n);
    
    TOG_BIT(n,2);
    
    printf("X=%X\n",n);
    
    printf("X(0)=%d\n",GET_BIT(n,0));
    printf("X(1)=%d\n",GET_BIT(n,1));
    printf("X(2)=%d\n",GET_BIT(n,2));

}

#include <stdio.h>
#define SET_BIT(num, bit) ((num) = (num) | (1 << (bit)))
#define CLR_BIT(num, bit) ((num) = (num) & (!(1 << (bit))))
#define TOG_BIT(num, bit) ((num) = (num) ^ (1 << (bit)))
#define GET_BIT(num, bit) (((num) >> (bit)) & 0x01)

void main() {
    int n1 = 0x00;

    SET_BIT(n1, 0);
    CLR_BIT(n1, 1);
    TOG_BIT(n1, 2);

    printf("%X\n", n1);
    printf("bit 0 is %d", GET_BIT(n1, 2));
}
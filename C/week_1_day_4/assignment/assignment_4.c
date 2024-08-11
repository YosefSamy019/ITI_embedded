
#include <stdio.h>
int fun(int x, int *py, int **ppz);


void main(void) {
    int c, *b, **a;
    c = 4, b = &c, a = &b;
    printf("%d", fun(c, b, a));
}

int fun(int x, int *py, int **ppz) {
    int y, z;
    **ppz += 1;
    z = **ppz;
    *py += 2;
    y = *py;
    x += 3;
    return x + y + z;
}
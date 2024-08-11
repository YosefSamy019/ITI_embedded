
#include <stdio.h>
void main(){
    int x = 15;
    int y = 20;
    
    int z,k,l,m,n;
    
    z = x & y;
    k = x | y;
    l = x ^ y;
    m = x >> 3;
    n = x << 4;
    
    
    printf("z: %d\n",z);
    printf("k: %d\n",k);
    printf("l: %d\n",l);
    printf("m: %d\n",m);
    printf("n: %d\n",n);

    getchar();
}
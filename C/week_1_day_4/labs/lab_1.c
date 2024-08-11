#include <stdio.h>
void main(){
    int x=10, *p = &x;
    printf("X= %d\n",x);
    
    *p=20;
    printf("X= %d\n",x);
}
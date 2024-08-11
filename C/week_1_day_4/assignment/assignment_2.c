#define print(x) printf(#x); printf(" = %d\n",x);

#include <stdio.h>
void main(void){
    int x=1,y=2,z=3;
    int *p = &x,*q = &y,*r= &z;
    
    printf("Before\n");
    print(x);
    print(y);
    print(z);
    print(p);
    print(q);
    print(r);
    print(*p);
    print(*q);
    print(*r);

    printf("\nSwapping\n");
    r=p;
    p=q;
    q=r;
    
    print(x);
    print(y);
    print(z);
    print(p);
    print(q);
    print(r);
    print(*p);
    print(*q);
    print(*r);
}
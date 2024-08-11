#include <stdio.h>

int sumFrom1(int n){
    int v;
    if (n>0){
        v =  (n + sumFrom1(n-1));
    }else{
        v = 0;
    }
    
    return v;
}

void main(void){
    int num;
    printf("Enter num: ");
    scanf("%d",&num);
    
    printf("Out: %d",sumFrom1(num));
    
}
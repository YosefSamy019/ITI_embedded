#include <stdio.h>

void fun1(int n1, int n2);

void main(){
    int n1,  n2;
    printf("Enter 2 nums: ");
    scanf("%d%d",&n1,&n2);
    
    fun1(n1,n2);
}

void fun1(int n1, int n2){
    printf("sum: %d\n",n1+n2);
    printf("mul: %d\n",n1*n2);
    printf("rem: %d\n",n1%n2);
}
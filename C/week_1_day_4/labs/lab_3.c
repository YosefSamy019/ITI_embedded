#include <stdio.h>

void fun1(int* n1, int* n2,int *sum,int *dif);

int main(){
    int n1,  n2,s,d;
    printf("Enter 2 nums: ");
    scanf("%d%d",&n1,&n2);
    
    fun1(&n1,&n2,&s,&d);
    
    printf("Sum: %d\n",s);
    printf("Dif: %d\n",d);
}

void fun1(int* n1, int* n2,int *sum,int *dif){
   *sum = *n1+*n2;
   *dif = *n1-*n2;
}
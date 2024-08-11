#include <stdio.h>

int fun1(int* n1, int* n2);

int main(){
    int n1,  n2,s;
    printf("Enter 2 nums: ");
    scanf("%d%d",&n1,&n2);
    
    s=fun1(&n1,&n2);
    printf("Sum: %d",s);
}

int fun1(int* n1, int* n2){
   return *n1 + *n2;
}
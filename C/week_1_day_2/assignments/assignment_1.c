#include <stdio.h>

void main(){
    unsigned long long fact=1,num=0;
    
    printf("Enter unsigned num: ");
    scanf("%u",&num);
    
    while (num>0){
        fact = fact * num;
        num = num - 1;
    }
    
    printf("Fact: %u",fact);
}
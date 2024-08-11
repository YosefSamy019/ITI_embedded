#include <stdio.h>

void main()
{
    unsigned int age;
    
    printf("Enter Your Age: ");
    scanf("%u",&age);
    
    if(age < 16)
    {
        printf("No, You cant drive.\n");
    }else{
        printf("Yes, You can drive.\n");
    }
    
    
    getchar();
}
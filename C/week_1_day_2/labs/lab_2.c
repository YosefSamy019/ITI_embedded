#include <stdio.h>
void main()
{
    int grade=0;
    
    printf("Enter Your Grade: ");
    scanf("%u",&grade);
    
    
    printf("Grade: ");
    if(grade >= 0 && grade < 50)
    {
        printf("Fail");    
    }
    else if(grade >= 50 && grade < 65)
    {
        printf("Pass");    
    }
    else if(grade >= 65 && grade < 75)
    {
        printf("Good");    
    }
    else if(grade >=75 && grade < 85)
    {
        printf("Very Good");    
    }
    else if(grade >= 85)
    {
        printf("Excellent");    
    }
    printf("\n");
    
}
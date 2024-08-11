#include <stdio.h>
void main(){
    int sum=0,i,temp;
    
    for (i=0;i<10;i++){
        printf("Enter num %d:",i+1);
        scanf("%d",&temp);
        sum = sum + temp;
    }
    
    printf("Sum: %d",sum);
}

#include <stdio.h>

void main(void){
    int max,i,temp;
    
    printf("Enter Five Numbers: ");
    for(i=0;i<5;i++){
        scanf("%d",&temp);
        
        if(i==0){
            max = temp;
        }else if(temp > max){
            max = temp;
        }
    }
    
    printf("Max: %d\n",max);

}
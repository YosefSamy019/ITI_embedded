
#include <stdio.h>
#define SI 10

void main(void){
    int i;
    int arr[SI];
    int target;
    char flag = -1;
    
    printf("Enter 10 numbers: ");
    for (i=0;i<SI;i++){
        scanf("%d",arr+i);
    }
    
    printf("Enter num to search: ");
    scanf("%d",&target);
    
    for (i=0;i<SI;i++){
        if(target == arr[i]){
            flag = i;
            break;
        }
    }
    
    if(flag <0){
        printf("Not found");
    }else{
        printf("Found at index %d",flag);
    }

}
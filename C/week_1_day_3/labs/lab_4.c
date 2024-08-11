#include <stdio.h>
void main(){
    int si=0;
    printf("Enter size: ");
    scanf("%d",&si);
    
    int arr[si],i;
    
    for (i=0;i<si;i++){
        printf("Enter Number %d: ",i+1);
        scanf("%d",arr+i);
    }
    
    printf("\n\n");
    
    for (i=0;i<si;i++){
        printf("Number %d: %d\n",i+1,arr[i]);
        
    }
}
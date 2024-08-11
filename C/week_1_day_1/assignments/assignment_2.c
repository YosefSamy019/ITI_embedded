#include <stdio.h>

void main(){
    int n[3],i;
    
    
    for(i=0;i<3;i++){
        printf("Enter n%d: ",i+1);
        scanf("%d",n+i);
    }
    
    for(i=2;i>=0;i--){
        printf("Num %d: %d\n",i+1,n[i]);
    }
    
}
#include <stdio.h>
void main(){
    unsigned i,j,height=0,temp;
    
    printf("Enter height: ");
    scanf("%u",&height);
    
    for (i=0;i<height;i++){
        for (j=0;j< height - i - 1;j++){
            printf("  ");
        }
        
        for (j=0;j< i+1;j++){
            temp = i+j+1;
            printf("%u ",temp);
        }
        
        for (j=0;j< i;j++){
            temp -=1;
            printf("%u ",temp);
        }
        printf("\n");
    }
}
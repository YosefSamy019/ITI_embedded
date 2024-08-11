#include <stdio.h>

int max3(int n1,int n2, int n3);
int min3(int n1,int n2, int n3);

void main(){
    int n1,  n2, n3;
    printf("Enter 3 nums: ");
    scanf("%d%d%d",&n1,&n2,&n3);
    
    printf("Min: %d\n",min3(n1,n2,n3));
    printf("Max: %d\n",max3(n1,n2,n3));

}

int max3(int n1,int n2, int n3){
    int max=n1;
    if(n2 > max) max = n2;
    if(n3 > max) max = n3;

    return max;
}

int min3(int n1,int n2, int n3){
    int min=n1;
    if(n2 < min) min = n2;
    if(n3 < min) min = n3;

    return min;   
}

#include <stdio.h>
void main(){
    int si=0,sum=0;
    float avg=0.0f;
    printf("Enter size: ");
    scanf("%d",&si);
    
    int arr[si],i;
    
    for (i=0;i<si;i++){
        printf("Enter Number %d: ",i+1);
        scanf("%d",arr+i);
    }
    
    for (i=0;i<si;i++){
        sum = sum + arr[i];
    }
    avg = (float)sum/ si;
    
    printf("sum: %d\n",sum);
    printf("avg: %f\n",avg);

}
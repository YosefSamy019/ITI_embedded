#include <stdio.h>

int arrSum(int *base,int si);

int main(){
    int si=10,i;
    int arr[10];
    
    printf("Enter Numbers: \n");
    for (i=0;i<si;i++){
        scanf("%d",arr+i);
    }
    
    printf("\nSum: %d",arrSum(arr,si));
}

int arrSum(int *base,int si){
   int sum=0;
   
   while (si>= 0){
       sum += base[si];
       si--;
   }
   
   return sum;
}
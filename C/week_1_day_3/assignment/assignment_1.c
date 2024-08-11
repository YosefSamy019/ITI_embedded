#include <stdio.h>
#define SIZE 10

void main(void) {
    int i, arr[SIZE], min, max;

    for (i = 0; i < SIZE; i++) {
        printf("Enter num %d: ", i + 1);
        scanf("%d", arr + i);
    }


    min = arr[0];
    max = arr[0];
    for (i = 1; i < SIZE; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }

        if (arr[i] < min) {
            min = arr[i];
        }
    }
    
    printf("MIN: %d\n",min);
    printf("MAX: %d\n",max);

}
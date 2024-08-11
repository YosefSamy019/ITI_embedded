#include <stdio.h>
#define SIZE 10

void bubbleSort(int *arr, int si) {
    int i, j;

    for (i = 0; i < si; i++) {
        for (j = 0; j < si - 1 - i; j++) {

            if (arr[j + 1] < arr[j]) {
                arr[j + 1] = arr[j] ^ arr[j + 1];
                arr[j] = arr[j] ^ arr[j + 1];
                arr[j + 1] = arr[j] ^ arr[j + 1];
            }
        }
    }
}

void main() {
    int i, arr[SIZE];

    for (i = 0; i < SIZE; i++) {
        printf("Enter num %d: ", i + 1);
        scanf("%d", arr + i);
    }

    printf("\n\nBefore");
    for (i = 0; i < SIZE; i++) {
        printf("Num %d: %d\n", i + 1, arr[i]);
    }

    bubbleSort(arr, SIZE);

    printf("\n\nAfter");
    for (i = 0; i < SIZE; i++) {
        printf("Num %d: %d\n", i + 1, arr[i]);
    }
}
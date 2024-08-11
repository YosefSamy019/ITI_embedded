#include <stdio.h>
void swapArr(int *arr1, int *arr2, int si) {
    int i, t;

    for (i = 0; i < si; i++) {
        t = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = t;
    }
}

void printArr(int *arr, int si) {
    int i;

    printf("[ ");

    for (i = 0; i < si; i++) {
        printf("%d, ", arr[i]);
    }
    printf("]\n");
}

void main(void) {
    int arr1[] = { 1, 2, 3, 4, 5, 6 };
    int arr2[] = { 10, 20, 30, 40, 50, 60 };
    int si = 6;
    
    printf("Before:\n");
    printf("Arr1:\n");
    printArr(arr1,si);
    printf("Arr2:\n");
    printArr(arr2,si);
    
    swapArr(arr1,arr2,si);
    
    printf("After:\n");
    printf("Arr1:\n");
    printArr(arr1,si);
    printf("Arr2:\n");
    printArr(arr2,si);
}
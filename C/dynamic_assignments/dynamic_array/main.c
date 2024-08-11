#include <stdio.h>
#include <stdlib.h>

void printArr(int *arr, int si) {
    int i;

    printf("[ ");

    for (i = 0; i < si; i++) {
        printf("%d, ", arr[i]);
    }
    printf("]\n");
}

int getFailedNumber(int *arr, int si) {
    int i, count=0;


    for (i = 0; i < si; i++) {
        count = count + (arr[i] < 50);
    }

    return count;
}

int getHigh(int *arr, int si) {
    int i, v = arr[0];


    for (i = 1; i < si; i++) {
        if (arr[i] > v) {
            v = arr[i];
        }
    }

    return v;
}

int getLow(int *arr, int si) {
    int i, v = arr[0];


    for (i = 1; i < si; i++) {
        if (arr[i] < v) {
            v = arr[i];
        }
    }

    return v;
}

double getAvg(int *arr, int si) {
    int i, sum = 0;


    for (i = 0; i < si; i++) {
        sum += arr[i];
    }

    return (double)sum / si;
}

void main(void) {
    int si;
    printf("Enter array size: ");
    scanf("%d",&si);
    
    int i;
    int classA[si];
    int classB[si];
    int classC[si];

    for (i = 0; i < si; i++) {
        classA[i] = rand() % 101;
        classB[i] = rand() % 101;
        classC[i] = rand() % 101;
    }

    printf("\nClass A:\n");
    printArr(classA, si);
    printf("Failed: %d\n", getFailedNumber(classA, si));
    printf("Highest: %d\n", getHigh(classA, si));
    printf("Lowest: %d\n", getLow(classA, si));
    printf("Avg: %lf\n", getAvg(classA, si));


    printf("\nClass B:\n");
    printArr(classB, si);
    printf("Failed: %d\n", getFailedNumber(classB, si));
    printf("Highest: %d\n", getHigh(classB, si));
    printf("Lowest: %d\n", getLow(classB, si));
    printf("Avg: %lf\n", getAvg(classB, si));
    
    printf("\nClass C:\n");
    printArr(classC, si);
    printf("Failed: %d\n", getFailedNumber(classC, si));
    printf("Highest: %d\n", getHigh(classC, si));
    printf("Lowest: %d\n", getLow(classC, si));
    printf("Avg: %lf\n", getAvg(classC, si));
}
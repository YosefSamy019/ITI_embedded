#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

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
    int i;
    int classA[10];
    int classB[10];
    int classC[10];

    for (i = 0; i < SIZE; i++) {
        classA[i] = rand() % 101;
        classB[i] = rand() % 101;
        classC[i] = rand() % 101;
    }

    printf("\nClass A:\n");
    printArr(classA, SIZE);
    printf("Failed: %d\n", getFailedNumber(classA, SIZE));
    printf("Highest: %d\n", getHigh(classA, SIZE));
    printf("Lowest: %d\n", getLow(classA, SIZE));
    printf("Avg: %lf\n", getAvg(classA, SIZE));


    printf("\nClass B:\n");
    printArr(classB, SIZE);
    printf("Failed: %d\n", getFailedNumber(classB, SIZE));
    printf("Highest: %d\n", getHigh(classB, SIZE));
    printf("Lowest: %d\n", getLow(classB, SIZE));
    printf("Avg: %lf\n", getAvg(classB, SIZE));
    
    printf("\nClass C:\n");
    printArr(classC, SIZE);
    printf("Failed: %d\n", getFailedNumber(classC, SIZE));
    printf("Highest: %d\n", getHigh(classC, SIZE));
    printf("Lowest: %d\n", getLow(classC, SIZE));
    printf("Avg: %lf\n", getAvg(classC, SIZE));
}
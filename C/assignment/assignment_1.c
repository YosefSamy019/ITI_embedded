#include <stdio.h>
#include <stdlib.h>

#include "STD_TYPES.h"

typedef struct {
    f64 math, language, physics, chemistry;
} Student_t;

void main(void) {
    Student_t arr[10];
    u8 i;

    for (i = 0; i < 10; i++) {
        arr[i].math = (f64)(rand() % 1001) / 10.0;
        arr[i].language = (f64)(rand() % 1001) / 10.0;
        arr[i].physics = (f64)(rand() % 1001) / 10.0;
        arr[i].chemistry = (f64)(rand() % 1001) / 10.0;
    }
    
    printf("Enter user Index (max 9): ");
    scanf("%d",&i);
    
    if(i<9){
        printf("Math: \t\t%lf\n",arr[i].math);
        printf("language: \t%lf\n",arr[i].language);
        printf("physics: \t%lf\n",arr[i].physics);
        printf("chemistry: \t%lf\n",arr[i].chemistry);

    }else{
        printf("Out of range\n");
    }
}
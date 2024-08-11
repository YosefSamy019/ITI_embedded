
#include <stdio.h>
#include <math.h>
#define PI (22.0/7.0)

void main(void){
    int sides;
    double length,area;
    
    printf("Enter #sides: ");
    scanf("%d",&sides);
    
    printf("Enter length of side: ");
    scanf("%lf",&length);
    
    area = (sides * length * length * (1.0/tan(PI/sides))) / 4.0;
    
    
    printf("Area: %lf\n",area);
}
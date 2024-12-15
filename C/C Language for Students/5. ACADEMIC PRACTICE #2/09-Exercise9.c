#include <stdio.h>
#include <math.h>

int main()
{
    float x1, x2, y1, y2, res;
    printf("Enter x1: ");
    scanf("%f", &x1);
    printf("Enter y1: ");
    scanf("%f", &y1);
    printf("Enter x2: ");
    scanf("%f", &x2);
    printf("Enter y2: ");
    scanf("%f", &y2);
    res = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    printf("Distance between 2 points is %.2f", res);
}
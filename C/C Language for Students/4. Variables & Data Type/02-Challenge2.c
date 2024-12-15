#include <stdio.h>

int main()
{
    float lenght, breath;
    printf("Enter Lenght of the Rectangle: ");
    scanf("%f", &lenght);
    printf("Enter Breath of the Rectangle: ");
    scanf("%f", &breath);
    printf("Area of Rectangle is %.2f", lenght * breath);
    return 0;
}
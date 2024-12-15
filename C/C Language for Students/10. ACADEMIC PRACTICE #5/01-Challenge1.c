#include <stdio.h>

float area(float lenght, float breath)
{
    return lenght * breath;
}

int main()
{
    float height, breath;
    printf("Enter height: ");
    scanf("%f", &height);
    printf("Enter breath: ");
    scanf("%f", &breath);
    printf("Area = %.2f", area(height, breath));
    return 0;
}
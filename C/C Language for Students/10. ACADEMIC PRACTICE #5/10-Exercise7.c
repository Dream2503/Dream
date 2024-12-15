#include <stdio.h>
#include <math.h>

float derivative(float c, float x, float n)
{
    return n * c * pow(x, n-1);
}

int main()
{
    float c, x, n;
    printf("Enter c, x, n: ");
    scanf("%f %f %f", c, x, n);
    printf("Derivative = %.2f", derivative(c, x, n));
    return 0;
}
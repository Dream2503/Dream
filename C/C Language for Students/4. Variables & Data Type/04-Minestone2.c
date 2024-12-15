#include <stdio.h>

int main()
{
    // TASK 1
    /*
    float temp;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &temp);

    float res = (temp * 1.8) + 32;
    printf("Temperatue in Ferenheit is %.2f", res);
    */
    
    float temp;
    printf("Enter temperature in Ferenheit: ");
    scanf("%f", &temp);

    float res = (temp - 32) / 1.8;
    printf("Temperatue in Celsius is %.2f", res);
    return 0;
}
#include <stdio.h>

int main()
{
    float data, res;
    int temp;
    printf("Enter a floating point number: ");
    scanf("%f", &data);
    temp = (int)data;
    res = data - temp;
    printf("Result = %.2f", res);
    return 0;
}
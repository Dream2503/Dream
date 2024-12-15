#include <stdio.h>

int main()
{
    float res = 0.01;

    for (int i = 0; i < 30; i++)
        res *= 2;

    printf("Total amount = %.0f", res);
    return 0;
}
/*
Date: 23/09/24
By: Swapnaraj Mohanty (24BCSH93)
*/

#include <stdio.h>

int main() {
    int num1, num2, num3;
    printf("Enter 3 numbers for average: ");
    scanf("%d%d%d", &num1, &num2, &num3);
    printf("Average = %f\n", (num1 + num2 + num3) / 3.0);
    return 0;
}

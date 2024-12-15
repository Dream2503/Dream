#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swapNum(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void genericSwap(void *var1, void *var2, unsigned int size) {
    void *temp = malloc(size);
    memcpy(temp, var1, size);
    memcpy(var1, var2, size);
    memcpy(var2, temp, size);
    free(temp);
}

int main() {
    char num1, num2;
    printf("Enter a number1: ");
    scanf(" %c", &num1);
    printf("Enter a number2: ");
    scanf(" %c", &num2);
    printf("num1: %c\nnum2: %c\n", num1, num2);
    genericSwap(&num1, &num2, sizeof(num1));
    printf("num1: %c\nnum2: %c\n", num1, num2);
    return 0;
}
#include <stdio.h>

void swap(int *, int *);

int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d%d", &num1, &num2);
    swap(&num1, &num2);
    printf("Numbers after swapping %d and %d\n", num1, num2);
    return 0;
}

void swap(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

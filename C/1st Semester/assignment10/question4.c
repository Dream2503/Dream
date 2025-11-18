#include <stdio.h>

int add(int, int);
int sub(int, int);
int mul(int, int);
int div(int, int);

int main() {
    int choice, num1, num2, res;
    printf("Enter two numbers: ");
    scanf("%d%d", &num1, &num2);
    printf("Select a valid option to perform operation on the number\n");
    printf("1 - Addition\n");
    printf("2 - Subtraction\n");
    printf("3 - Multiplication\n");
    printf("4 - Division\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            res = add(num1, num2);
            break;
        case 2:
            res = sub(num1, num2);
            break;
        case 3:
            res = mul(num1, num2);
            break;
        case 4:
            res = div(num1, num2);
            break;
        default:
            printf("\nInvalid choice\n");
            return 0;
    }
    printf("\nYour result is %d\n", res);
    return 0;
}

int add(int num1, int num2) { return num1 + num2; }
int sub(int num1, int num2) { return num1 - num2; }
int mul(int num1, int num2) { return num1 * num2; }
int div(int num1, int num2) { return num1 / num2; }

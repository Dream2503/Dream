#include <stdio.h>

int main() {
    int income;
    float tax;
    printf("Enter the income: ");
    scanf("%d", &income);

    if (income > 0 && income <= 300000) {
        tax = 0;
    } else if (income > 300000 && income <= 700000) {
        tax = 0.05 * income;
    } else if (income > 700000 && income <= 1000000) {
        tax = 0.1 * income;
    } else if (income > 1000000 && income <= 1200000) {
        tax = 0.15 * income;
    } else if (income > 1200000 && income <= 1500000) {
        tax = 0.2 * income;
    } else {
        tax = 0.3 * income;
    }
    printf("payable tax = %f\n", tax);
    return 0;
}

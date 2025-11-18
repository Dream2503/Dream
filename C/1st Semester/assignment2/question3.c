#include <stdio.h>

int main() {
    float mark1, mark2, mark3, mark4, mark5, total;
    printf("Enter marks for 5 subjects: ");
    scanf("%f%f%f%f%f", &mark1, &mark2, &mark3, &mark4, &mark5);
    total = (mark1 + mark2 + mark3 + mark4 + mark5) / 5;
    printf("Total Percentage: %.2f\n", total);
    return 0;
}

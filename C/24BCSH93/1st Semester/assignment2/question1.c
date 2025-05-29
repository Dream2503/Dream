#include <stdio.h>

int main() {
    float CGPA;
    printf("Enter the CGPA: ");
    scanf("%f", &CGPA);
    printf("Equivalent percentage = %.2f\n", (CGPA - 0.5) * 10);
    return 0;
}

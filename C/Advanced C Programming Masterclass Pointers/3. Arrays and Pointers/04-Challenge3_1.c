#include <stdio.h>

void findAverage(int num1, int num2, float *average) {
    *average = (num1 + num2) / (float)2;
}

int main() {
    int num1 = 5, num2 = 6;
    float average;
    findAverage(num1, num2, &average);
    printf("%.1f", average);
    return 0;
}
#include <stdio.h>

double e(int x, int n) {
    double sum = 1;
    for (; n > 0; n--)sum = 1 + (x * sum)/ n;
    return sum;
}

int main() {
    printf("%lf", e(1, 10));
    return 0;
}
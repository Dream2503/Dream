#include <stdio.h>

double e(int x, int n) {
    static double sum = 1;
    if (n == 0)return sum;
    sum = 1 + (x * sum) / n ;
    return e(x, n-1);
}

int main() {
    printf("%lf", e(1, 10));
    return 0;
}
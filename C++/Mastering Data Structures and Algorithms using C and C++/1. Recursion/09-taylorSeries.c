#include <stdio.h>

double e(int x, int n) {
    static double p = 1, f = 1;
    double res;
    if (n == 0) return 1;
    res = e(x, n-1);
    p *= x;
    f *= n;
    return res + p / f;
}

int main() {
    printf("%lf", e(3, 20));
    return 0;
}
#include <stdio.h>

double e(int x, int n) {
    double s = 1, num = 1, den = 1;
    int i;

    for (i = 1; i <= n; i++) {
        num *= x;
        den *= i;
        s += num / den;
    }
    return s;
}

int main() {
    printf("%lf \n", e(1, 10));
    return 0;
}

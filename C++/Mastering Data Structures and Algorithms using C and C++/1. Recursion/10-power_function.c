#include <stdio.h>

int power(int m, int n) {
    if (n == 0) {
        return 1;
    }
    return power(m, n - 1) * m;
}

int power1(int m, int n) {
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 0) {
        return power1(m * m, n / 2);
    }
    return m * power1(m * m, (n - 1) / 2);
}

int Ipower(int m, int n) {
    int i, res = 1;

    for (i = 0; i < n; i++) {
        res *= m;
    }
    return res;
}

int main() {
    int r = Ipower(9, 3);
    printf("%d ", r);
    return 0;
}
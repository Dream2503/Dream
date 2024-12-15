#include <stdio.h>

int pow(int m, int n) {
    if (n == 0) return 1;
    return pow(m, n-1) * m;
}
int iPow(int m, int n) {
    int res = 1;
    for (int i = 1; i <= n; i++) res *= m;
    return res;
}
int fasPow(int m, int n) {
    if (n == 0) return 1;
    if (n % 2 == 0) return pow(m*m, n/2);
    return m * pow(m*m, (n-1)/2);
}

int main() {
    printf("%d", fasPow(5, 3));
    return 0;
}
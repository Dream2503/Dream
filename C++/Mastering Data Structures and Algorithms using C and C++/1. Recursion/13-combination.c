#include <stdio.h>

int combination(int n, int r) {
    if (n == r || r == 0) return 1;
    return combination(n-1, r-1) + combination(n-1, r);
}
int fact(int n) {
    if (n == 0)return 1;
    return fact(n-1) * n;
}
int nCr(int n, int r) {
    int num = fact(n), den = fact(r) * fact(n-r);
    return num / den;
}
int main() {
    printf("%d", combination(5, 3));
    return 0;
}
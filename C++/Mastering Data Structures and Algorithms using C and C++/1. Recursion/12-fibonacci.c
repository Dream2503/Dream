#include <stdio.h>

int fibonacci(int n) {
    static int f[40] = {0, 1};
    if (n <= 1) return f[n];
    if (f[n-1] == 0) f[n-1] = fibonacci(n-1);
    if (f[n-2] == 0) f[n-2] = fibonacci(n-2);
    return f[n-2] + f[n-1];
}
int iterFibonacci(int n) {
    int term1 = 0, term2 = 1, sum = 0;
    if (n <= 1) return n;

    for (int i = 2; i <= n; i++) {
        sum = term1 + term2;
        term1 = term2;
        term2 = sum;
    }
    return sum;
}
int recurFibonacci(int n) {
    if (n <= 1) return n;
    return recurFibonacci(n-2) + recurFibonacci(n-1);
}

int main() {
    printf("%d\n", iterFibonacci(5));
    return 0;
}
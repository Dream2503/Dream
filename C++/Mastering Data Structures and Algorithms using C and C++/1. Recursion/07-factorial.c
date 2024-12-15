#include <stdio.h>

int fact(int n) {
    if (n == 0)return 1;
    return fact(n-1) * n;
}
int iFact(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++)fact *= i;
    return fact;
}

int main() {
    printf("%d", fact(5));
    return 0;
}
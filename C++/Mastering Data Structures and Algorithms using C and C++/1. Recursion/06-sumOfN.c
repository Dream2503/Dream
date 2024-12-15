#include <stdio.h>

int sum(int n) {
    if (n == 0)return 0;
    return sum(n-1) + n;
}
int iSum(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) sum += i;
    return sum;
}

int main() {
    printf("%d", iSum(5));
    return 0;
}
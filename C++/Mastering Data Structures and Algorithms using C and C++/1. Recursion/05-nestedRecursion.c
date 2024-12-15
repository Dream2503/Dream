#include <stdio.h>

int func(int n) {
    if (n > 100) return n - 10;
    return func(func(n+11));
}

int main() {
    printf("%d", func(95));
    return 0;
}
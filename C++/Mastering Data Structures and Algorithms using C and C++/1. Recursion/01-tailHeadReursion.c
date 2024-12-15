#include <stdio.h>

void head(int n) {
    if (n > 0) {
        printf("%d", n);
        head(n-1);
    }
}
void tail(int n) {
    if (n > 0) {
        tail(n-1);
        printf("%d", n);
    }
}

int main() {
    head(3);
    tail(3);
    return 0;
}
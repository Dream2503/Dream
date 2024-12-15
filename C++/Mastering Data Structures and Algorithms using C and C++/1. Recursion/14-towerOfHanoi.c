#include <stdio.h>

void TOH(int n, int A, int B, int C) {
    static int cnt = 0;

    if (n > 0) {
        TOH(n-1, A, C, B);
        cnt++;
        printf("%ld. (%d, %d)\n", cnt, A, C);
        TOH(n-1, B, A, C);
    }
}
int main() {
    TOH(16, 1, 2, 3);
    return 0;
}
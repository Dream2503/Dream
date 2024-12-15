#include <stdio.h>

int nonStatic(int n) {
    if (n > 0) return nonStatic(n-1) + n;
    return 0;
}
int staticGlobal(int n) {
    static int x;
    
    if (n > 0) {
        x++;
        return staticGlobal(n-1) + x;
    } return 0;
}

int main() {
    printf("%d\n", nonStatic(5));
    printf("%d", staticGlobal(5));
    return 0;
}
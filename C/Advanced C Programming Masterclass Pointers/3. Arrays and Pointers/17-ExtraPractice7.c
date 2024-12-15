#include <stdio.h>

void convertBinary(int num) {
    if (num == 1)
        printf("%d", num);
    else {
        convertBinary(num / 2);
        printf("%d", num % 2);
        
    }
}

int main() {
    convertBinary(12);
    return 0;
}
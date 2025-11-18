#include <stdio.h>

int main() {
    int num, i, j;
    printf("Enter the number: ");
    scanf("%d", &num);

    for (i = 1; i <= num * 2; i++) {
        for (j = 1; j <= i; j++) {
            if (i % 2 != 0) {
                printf("%d ", j);
            }
        }
        if (i % 2 != 0) {
            printf("\n");
        }
    }
    return 0;
}

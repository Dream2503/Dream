#include <stdio.h>

int main() {
    int num, i, j;
    printf("Enter the number: ");
    scanf("%d", &num);

    for (i = 1; i <= num; i++) {
        for (j = 1; j <= i; j++) {
            printf("%c ", 64 + j);
        }
        printf("\n");
    }
    return 0;
}

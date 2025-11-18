#include <stdio.h>

int main() {
    int num, i, j, cnt = 1;
    printf("Enter the number: ");
    scanf("%d", &num);

    for (i = num; i >= 1; i--) {
        for (j = 1; j < i; j++) {
            printf("  ");
        }
        for (j = 1; j <= cnt; j++) {
            printf("%d ", j);
        }
        for (j = cnt - 1; j >= 1; j--) {
            printf("%d ", j);
        }
        cnt++;
        printf("\n");
    }
    return 0;
}

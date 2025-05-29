#include <stdio.h>

int main() {
    int num, i;
    printf("Enter a number: ");
    scanf("%d", &num);

    for (i = 1; i <= num; i++) {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}

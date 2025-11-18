#include <stdio.h>

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    for (; num != 0; num--) {
        if (num % 7 == 0)
            continue;
        printf("%d ", num);
    }
    printf("\n");
    return 0;
}

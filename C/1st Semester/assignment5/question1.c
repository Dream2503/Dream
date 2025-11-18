#include <stdio.h>

int main() {
    int num, i = 1;
    printf("Enter a number: ");
    scanf("%d", &num);

    while (i <= num) {
        printf("%d ", i);
        i++;
    }
    printf("\n");
    return 0;
}

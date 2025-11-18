#include <stdio.h>

int main() {
    int array[5], i;
    printf("Enter 5 elements:\n");

    for (i = 0; i < 5; i++) {
        scanf("%d", &array[i]);
    }
    printf("Even elements are: ");
    for (i = 0; i < 5; i++) {
        if (array[i] % 2 == 0) {
            printf("%d ", array[i]);
        }
    }
    printf("\n");
    return 0;
}

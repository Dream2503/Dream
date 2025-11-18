#include <stdio.h>

int main() {
    int array[5], i, temp;
    printf("Enter 5 elements:\n");

    for (i = 0; i < 5; i++) {
        scanf("%d", &array[i]);
    }
    for (i = 0; i < 5 / 2; i++) {
        temp = array[i];
        array[i] = array[5 - i - 1];
        array[5 - i - 1] = temp;
    }
    printf("Reversed array is: ");

    for (i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}

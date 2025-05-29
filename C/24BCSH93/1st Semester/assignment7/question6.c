#include <stdio.h>

int main() {
    int array[5], value, i;
    printf("Enter 5 elements:\n");

    for (i = 0; i < 5; i++) {
        scanf("%d", &array[i]);
    }
    printf("Enter the value to search: ");
    scanf("%d", &value);

    for (i = 0; i < 5; i++) {
        if (array[i] == value) {
            printf("Element found\n");
            return 0;
        }
    }
    printf("Element not found\n");
    return 0;
}

#include <stdio.h>

int max(int *, int);

int main() {
    int size, i;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int array[size];
    printf("Enter the array elements: ");

    for (i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    printf("Maximum element of the array is %d\n", max(array, size));
    return 0;
}

int max(int *array, int size) {
    int res = 0, i;

    for (i = 0; i < size; i++) {
        if (res < *array) {
            res = *array;
        }
        array++;
    }
    return res;
}

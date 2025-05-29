#include <stdio.h>

int sum(int *, int);

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int array[size], i;
    printf("Enter the array elements: ");

    for (i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    printf("Sum of the elements of the array is %d\n", sum(array, size));
    return 0;
}

int sum(int *array, int size) {
    int res = 0, i;

    for (i = 0; i < size; i++) {
        res += *(array + i);
    }
    return res;
}

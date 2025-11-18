#include <stdio.h>
#include <stdlib.h>

int main() {
    int size, i, sum = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int *array = (int *) malloc(sizeof(int) * size);
    printf("Enter the array elements: ");

    for (i = 0; i < size; i++) {
        scanf("%d", array + i);
    }
    for (i = 0; i < size; i++) {
        sum += *(array + i);
    }
    printf("Sum of the elements of the array is %d\n", sum);
    free(array);
    array = NULL;
    return 0;
}

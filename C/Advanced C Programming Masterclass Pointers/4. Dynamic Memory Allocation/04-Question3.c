#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createArray(int **array, int size) {
    *array = (int*)malloc(sizeof(int) * size);
}

void printArray(int *array, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
}

int main() {
    int *array;
    createArray(&array, 5);

    for (int i = 0; i < 5; i++) {
        printf("Enter #%d element of the array: ", i +1);
        scanf("%d", array + i);
    };

    printArray(array, 5);
    return 0;
}
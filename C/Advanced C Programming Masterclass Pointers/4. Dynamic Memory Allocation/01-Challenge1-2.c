#include <stdio.h>
#include <malloc.h>

int *createArray(int size) {
    int *array = (int*)malloc(sizeof(int) * size);
    
    for (int i = 0; i < size; i++) {
        printf("Enter #%d element of the array: ", i +1);
        scanf("%d", array + i);
    }
    return array;
}

void printArray(int *array, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", *(array + i));
}

int main() {
    int *array = createArray(5);
    printArray(array, 5);
    return 0;
}
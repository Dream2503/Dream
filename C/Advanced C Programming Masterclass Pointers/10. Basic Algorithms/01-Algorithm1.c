#include <stdio.h>
#include <stdlib.h>

void printArray(int *array, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
}

int *mergeSortedArray(int *array1, unsigned size1, int *array2, unsigned size2) {
    int *array = (int*)calloc(size1+size2, sizeof(int));
    int i = 0, j = 0;

    while (i < size1 || j < size2) {
        if (i == size1) {
            for (j; j < size2; j++)
                array[i+j] = array2[j];
        } else if (j == size2) {
            for (j; j < size2; j++)
                array[i+j] = array1[i];
        } else {
            if (array1[i] > array2[j]) {
                array[i+j] = array2[j];
                j++;
            } else if (array1[i] < array2[j]) {
                array[i+j] = array1[i];
                i++;
            }
            else {
                array[i+j] = array1[i];
                i++;
                array[i+j] = array2[j];
                j++;
            }
        }
    }
    return array;
}

int main() {
    int array1[] = {1, 3, 4, 7}, array2[] = {2, 5, 8};
    int *res = mergeSortedArray(array1, 4, array2, 3);
    printArray(res, 7);
    return 0;
}
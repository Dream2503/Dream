#include <stdio.h>
#include <stdlib.h>

void insert(int array[], int size) {
    int temp = array[size], i = size;

    while (i > 1 && temp > array[i/2]) {
        array[i] = array[i/2];
        i = i/2;
    }
    array[i] = temp;
}
void swap(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
void delete(int array[], int size) {
    int var = array[1], i = 1, j = 2;
    array[1] = array[size];

    while (j < size) {
        if (array[j+1] > array[j]) j++;
        if (array[i] < array[j]) {
            swap(&array[i], &array[j]);
            i = j;
            j *= 2;
        } else break;
    }
    array[size] = var;
}
void heapSort(int array[], int size) {
    for (int i = 2; i <= size; i++) insert(array, i);
    for (int i = size; i > 1; i--) delete(array, i);
}

int main() {
    int array[] = {-1, 10, 20, 30, 25, 5, 40, 35};
    for (int i = 2; i <= 7; i++) insert(array, i);
    for (int i = 1; i < 8; i++) printf("%d ", array[i]);
    return 0;
}
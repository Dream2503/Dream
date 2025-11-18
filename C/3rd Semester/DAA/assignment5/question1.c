//  Q1. Implementation of Heap Sort and display the working of it.

#include <stdio.h>
#include <stdlib.h>

void heap_sort(int*, int);
void build_max_heap(int*);
void max_heapify(int*, int);
int* create_array(int);
void display_array(int*, int);

int heap_size, max_heapify_call = 0;

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int* array = create_array(size);
    heap_sort(array, size);
    printf("\nThe array elements after sorted are: ");
    display_array(array, size);
    free(array);
    return 0;
}

void heap_sort(int* array, int size) {
    int i;
    heap_size = size;
    build_max_heap(array);

    for (i = size - 1; i > 0; i--) {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        printf("The partial sorted array at i=%d: ", i);
        display_array(array, size);
        heap_size--;
        printf("\nMax Heapify call from heap sort for i=%d\n", i);
        max_heapify(array, 0);
    }
}

void build_max_heap(int* array) {
    int i;
    printf("\nBuild Max Heap call on array: ");
    display_array(array, heap_size);

    for (i = heap_size / 2 - 1; i >= 0; i--) {
        max_heapify(array, i);
    }
}

void max_heapify(int* array, int i) {
    printf("Max Heapify call %d on array for i=%d i.e. A[i]=%d\n", ++max_heapify_call, i, array[i]);
    printf("Array before: ");
    display_array(array, heap_size);
    int left = (i + 1) * 2 - 1, right = left + 1, max = i;

    if (left < heap_size && array[left] > array[max]) {
        max = left;
    }
    if (right < heap_size && array[right] > array[max]) {
        max = right;
    }
    if (max != i) {
        int temp = array[i];
        array[i] = array[max];
        array[max] = temp;
        printf("Array after: ");
        display_array(array, heap_size);

        if (max < heap_size / 2) {
            max_heapify(array, max);
        }
    } else {
        printf("Array after: ");
        display_array(array, heap_size);
    }
}

int* create_array(int size) {
    int *array = (int*)malloc(sizeof(int) * size), i;

    if (!array) {
        printf("Memory was not allocated");
        exit(0);
    }
    printf("Enter the array elements: ");

    for (i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    return array;
}

void display_array(int* array, int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

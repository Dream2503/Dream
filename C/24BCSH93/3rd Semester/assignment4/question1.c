//  Q1. Implementation of Merge Sort and display the working of it.

#include <stdio.h>
#include <stdlib.h>

void merge_sort(int*, int, int);
void merge(int*, int, int, int);
int* create_array(int);
void display_array(int*, int, int);

int merge_sort_call = 1, merge_call = 1, *temp_array;

int main() {
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    int* array = create_array(size);
    temp_array = (int*)malloc(sizeof(int) * size);

    if (!temp_array) {
        printf("Memory was not allocated during creation of temp_array");
        exit(0);
    }
    merge_sort(array, 0, size - 1);
    printf("Final sorted array: ");
    display_array(array, 0, size - 1);
    free(array);
    free(temp_array);
    return 0;
}

void merge_sort(int* array, int low, int high) {
    printf("Merge Sort call %d with low=%d and high=%d\n", merge_sort_call++, low, high);
    display_array(array, low, high);

    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(array, low, mid);
        merge_sort(array, mid + 1, high);
        merge(array, low, mid, high);
    }
}

void merge(int* array, int low, int mid, int high) {
    printf("Merge call %d with low=%d, mid=%d, high=%d\n", merge_call++, low, mid, high);
    printf("Before merge ");
    display_array(array, low, high);
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high) {
        if (array[i] <= array[j]) {
            temp_array[k++] = array[i++];
        } else {
            temp_array[k++] = array[j++];
        }
    }
    while (i <= mid) {
        temp_array[k++] = array[i++];
    }
    while (j <= high) {
        temp_array[k++] = array[j++];
    }
    for (k = low; k <= high; k++) {
        array[k] = temp_array[k];
    }
    printf("After merge ");
    display_array(array, low, high);
}

int* create_array(int n) {
    int *array = (int*)malloc(sizeof(int) * n), i;

    if (!array) {
        printf("Memory was not allocated during creation of array");
        exit(0);
    }
    printf("Enter the array elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    return array;
}

void display_array(int* array, int low, int high) {
    int i;
    printf("The array elements are: ");

    for (i = low; i <= high; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\n");
}

//  Q1. Implementation of Randomized Quick Sort and display the working of it.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomized_quick_sort(int*, int, int);
void quick_sort(int*, int, int);
int randomized_partition(int*, int, int);
int partition(int*, int, int);
int random_index(int, int);
int* create_array(int);
void display_array(int*, int, int);

int quick_sort_call = 1, partition_call = 1;

int main() {
    srand(time(NULL));
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    int* array = create_array(size);
    randomized_quick_sort(array, 0, size - 1);
    printf("Final sorted array: ");
    display_array(array, 0, size - 1);
    free(array);
    return 0;
}

void randomized_quick_sort(int* array, int low, int high) {
    printf("Randomized Quick Sort call %d with low=%d and high=%d\n", quick_sort_call++, low, high);
    display_array(array, low, high);

    if (low < high) {
        int mid = randomized_partition(array, low, high);
        randomized_quick_sort(array, low, mid - 1);
        randomized_quick_sort(array, mid + 1, high);
    }
}

void quick_sort(int* array, int low, int high) {
    printf("Quick Sort call %d with low=%d and high=%d\n", quick_sort_call++, low, high);
    display_array(array, low, high);

    if (low < high) {
        int mid = partition(array, low, high);
        quick_sort(array, low, mid - 1);
        quick_sort(array, mid + 1, high);
    }
}

int randomized_partition(int* array, int low, int high) {
    int i = random_index(low, high), temp;
    printf("Random index chosen is %d with element %d\n", i, array[i]);
    temp = array[i];
    array[i] = array[high];
    array[high] = temp;
    return partition(array, low, high);
}

int partition(int* array, int low, int high) {
    printf("Partition call %d with low=%d, high=%d\n", partition_call++, low, high);
    printf("Before partition ");
    display_array(array, low, high);
    int pivot = array[high], i = low, j, temp;

    for (j = low; j <= high; j++) {
        if (array[j] <= pivot) {
            temp = array[j];
            array[j] = array[i];
            array[i++] = temp;
        }
    }
    printf("After partition ");
    display_array(array, low, high);
    return i - 1;
}

int random_index(int low, int high) { return low + rand() % (high - low + 1); }

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

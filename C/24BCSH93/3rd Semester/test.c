//  Q. Implementation of Bubble, Insertion, Selection, Merge and Heap Sort with random values then calculate the time taken to sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 100000

void bubble_sort(int*);
void selection_sort(int*);
void insertion_sort(int*);
void heap_sort(int*);
void max_heapify(int*, int, int);
void merge_sort(int*, int, int);
void quick_sort(int*, int, int);
int* create_array(int, int);
int* copy(int*);
void display_array(int*);
void display_time(char[], clock_t, clock_t);

unsigned long long int read = 0, write = 0;

int main() {
    srand(time(NULL));
    clock_t start, end;
    int low, high;
    printf("Enter the range of random numbers to generate: ");
    scanf("%d%d", &low, &high);
    start = clock();
    int *array = create_array(low, high), *copy_array;
    printf("Array before sorting:\n");
    display_array(array);
    display_time("create and display array", start, clock());

    copy_array = copy(array);
    start = clock();
    bubble_sort(copy_array);
    end = clock();
    printf("Array after sorting using bubble sort:\n");
    display_array(copy_array);
    free(copy_array);
    display_time("bubble sort", start, end);

    copy_array = copy(array);
    start = clock();
    selection_sort(copy_array);
    end = clock();
    printf("Array after sorting using selection sort:\n");
    display_array(copy_array);
    free(copy_array);
    display_time("selection_sort", start, end);

    copy_array = copy(array);
    start = clock();
    insertion_sort(copy_array);
    end = clock();
    printf("Array after sorting using insertion sort:\n");
    display_array(copy_array);
    free(copy_array);
    display_time("insertion sort", start, end);

    copy_array = copy(array);
    start = clock();
    heap_sort(copy_array);
    end = clock();
    printf("Array after sorting using heap sort:\n");
    display_array(copy_array);
    free(copy_array);
    display_time("heap_sort", start, end);

    copy_array = copy(array);
    start = clock();
    read = write = 0;
    merge_sort(copy_array, 0, n - 1);
    end = clock();
    printf("Array after sorting using merge sort:\n");
    display_array(copy_array);
    free(copy_array);
    display_time("merge_sort", start, end);

    copy_array = copy(array);
    start = clock();
    read = write = 0;
    quick_sort(copy_array, 0, n - 1);
    end = clock();
    printf("Array after sorting using quick sort:\n");
    display_array(copy_array);
    free(copy_array);
    display_time("quick_sort", start, end);

    free(array);
    return 0;
}

void bubble_sort(int* array) {
    int i, j, temp;
    read = write = 0;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                read += 2;
                write += 2;
            }
            read += 2;
        }
    }
}

void selection_sort(int* array) {
    int i, j, min, temp;
    read = write = 0;

    for (i = 0; i < n - 1; i++) {
        min = i;

        for (j = i + 1; j < n; j++) {
            if (array[j] < array[min]) {
                min = j;
            }
            read += 2;
        }
        if (min != i) {
            temp = array[min];
            array[min] = array[i];
            array[i] = temp;
            read += 2;
            write += 2;
        }
    }
}

void insertion_sort(int* array) {
    int i, j, key;
    read = write = 0;

    for (i = 1; i < n; i++) {
        key = array[i];
        read++;
        j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
            read++;
            write++;
        }
        array[j + 1] = key;
        read++;
        write++;
    }
}

void heap_sort(int* array) {
    int i;
    read = write = 0;

    for (i = n / 2 - 1; i >= 0; i--) {
        max_heapify(array, n, i);
    }
    for (i = n - 1; i > 0; i--) {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        max_heapify(array, i, 0);
        read += 2;
        write += 2;
    }
}

void max_heapify(int* array, int heap_size, int i) {
    int l = i * 2 + 1, r = i * 2 + 2, max = i;

    if (l < heap_size && array[l] > array[max]) {
        max = l;
    }
    if (r < heap_size && array[r] > array[max]) {
        max = r;
    }
    if (max != i) {
        int temp = array[i];
        array[i] = array[max];
        array[max] = temp;

        if (max < heap_size / 2) {
            max_heapify(array, heap_size, max);
        }
        read += 2;
        write += 2;
    }
    read += 4;
}

void merge_sort(int* array, int low, int high) {
    static int temp_array[n];

    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(array, low, mid);
        merge_sort(array, mid + 1, high);
        int i = low, j = mid + 1, k = low;

        while (i <= mid && j <= high) {
            if (array[i] <= array[j]) {
                temp_array[k++] = array[i++];
            } else {
                temp_array[k++] = array[j++];
            }
            read += 3;
            write++;
        }
        while (i <= mid) {
            temp_array[k++] = array[i++];
            read++;
            write++;
        }
        while (j <= high) {
            temp_array[k++] = array[j++];
            read++;
            write++;
        }
        for (k = low; k <= high; k++) {
            array[k] = temp_array[k];
            read++;
            write++;
        }
    }
}

void quick_sort(int* array, int low, int high) {
    if (low < high) {
        int idx = low + rand() % (high - low + 1), temp;
        temp = array[idx];
        array[idx] = array[high];
        array[high] = temp;
        int pivot = array[high], i = low, j;

        for (j = low; j <= high; j++) {
            if (array[j] <= pivot) {
                temp = array[j];
                array[j] = array[i];
                array[i++] = temp;
                read += 2;
                write += 2;
            }
            read++;
        }
        int mid = i - 1;
        quick_sort(array, low, mid - 1);
        quick_sort(array, mid + 1, high);
        read += 3;
        write += 2;
    }
}

int* create_array(int low, int high) {
    int *array = (int*)malloc(sizeof(int) * n), i;

    if (!array) {
        exit(0);
    }
    for (i = 0; i < n; i++) {
        array[i] = low + rand() % (high - low + 1);
        write++;
    }
    return array;
}

int* copy(int* array) {
    int *res = (int*)malloc(sizeof(int) * n), i;

    if (!res) {
        exit(0);
    }
    for (i = 0; i < n; i++) {
        res[i] = array[i];
    }
    return res;
}

void display_array(int* array) {
    int i;
    printf("\nFirst 64 elements of the array: ");

    for (i = 0; i < 64; i++) {
        printf("%d ", array[i]);
    }
    printf("\nTotal number of array reads: %ld and array writes: %ld\n", read, write);
}

void display_time(char name[], clock_t start, clock_t end) {
    printf("\nTime taken using %s: %.2lfms\n", name, (double)(end - start) / CLOCKS_PER_SEC * 1000);
}

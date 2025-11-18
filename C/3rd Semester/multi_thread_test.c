// Q1. Implementation of Multi-threaded Merge Sort with random values and calculate the time taken.

#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <time.h>
#define N 1000000000
#define THREADS 32
#define CHUNK (N / THREADS)

void merge_sort(char*, int, int);
char* create_array(int, int);
char* copy(char*);
void display_array(char*);
void display_time(char[], double, double);

typedef struct {
    char* array;
    int low;
    int high;
} Task;
static char temp_array[N];

int thread_func(void* arg);
void merge_chunks(char*, int, int, int, int);
void parallel_merge_sort(char*);

double now_ms(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 1e3 + ts.tv_nsec / 1e6;
}

int main() {
    srand(time(NULL));
    clock_t start, end;
    int low = -128, high = 127;

    char *array = create_array(low, high), *copy_array;
    printf("Array before sorting:\n");
    display_array(array);

    start = now_ms();
    parallel_merge_sort(array);
    end = now_ms();
    printf("Array after sorting using multi-threaded merge sort:\n");
    display_array(array);
    free(array);
    display_time("multi-threaded merge sort", start, end);

    // free(array);
    return 0;
}

int thread_func(void* arg) {
    Task* task = arg;
    merge_sort(task->array, task->low, task->high);
    return 0;
}

void merge_sort(char* array, int low, int high) {
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
    }
}

void parallel_merge_sort(char* array) {
    thrd_t threads[THREADS];
    Task args[THREADS];

    for (int i = 0; i < THREADS; i++) {
        args[i].array = array;
        args[i].low = i * CHUNK;
        args[i].high = i == THREADS - 1 ? N - 1 : (i + 1) * CHUNK - 1;
        thrd_create(&threads[i], thread_func, &args[i]);
    }
    for (int i = 0; i < THREADS; i++) {
        thrd_join(threads[i], NULL);
    }
}

char* create_array(int low, int high) {
    char* array = (char*)malloc(sizeof(char) * N);
    for (int i = 0; i < N; i++) {
        array[i] = low + rand() % (high - low + 1);
    }
    return array;
}

char* copy(char* array) {
    char* res = (char*)malloc(sizeof(char) * N);
    for (int i = 0; i < N; i++) {
        res[i] = array[i];
    }
    return res;
}

void display_array(char* array) {
    printf("\nFirst 32 elements of the array: ");
    for (int i = 0; i < 32; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void display_time(char name[], double start, double end) {
    printf("Time taken using %s: %.2lf ms\n\n", name, end - start);
}

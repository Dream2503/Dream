#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data, size;
} Array;

typedef struct {
    Array array;
    int value, idx;
} Element;

Array k_way_merge(Array*, int);
void build_min_heap(Element*);
void min_heapify(Element*, int);
Array* create_arrays(int);
void display(Array);

int heap_size;

int main() {
    int k, i;
    printf("Enter the total number array to create: ");
    scanf("%d", &k);
    Array* arrays = create_arrays(k);

    for (i = 0; i < k; i++) {
        display(arrays[i]);
    }
    Array res = k_way_merge(arrays, k);
    display(res);

    for (i = 0; i < k; i++) {
        free(arrays[i].data);
    }
    free(res.data);
    free(arrays);
    return 0;
}

Array k_way_merge(Array* arrays, int k) {
    heap_size = k;
    Element* heap = (Element*)malloc(sizeof(Element) * heap_size);

    if (!heap) {
        printf("Memory was not allocated");
        exit(0);
    }
    int i, n = 0;

    for (i = 0; i < k; i++) {
        Element element = {arrays[i], arrays[i].data[0], 1};
        heap[i] = element;
        n += arrays[i].size;
    }
    Array res = {(int*)malloc(sizeof(int) * n), n};

    if (!res.data) {
        printf("Memory was not allocated");
        exit(0);
    }
    for (i = heap_size / 2 - 1; i >= 0; i--) {
        min_heapify(heap, i);
    }
    i = 0;

    while (heap_size) {
        Element min_element = heap[0];
        res.data[i++] = min_element.value;

        if (min_element.idx < min_element.array.size) {
            Element element = {min_element.array, min_element.array.data[min_element.idx], min_element.idx + 1};
            heap[0] = element;
        } else {
            heap[0] = heap[heap_size - 1];
            heap_size--;
        }
        min_heapify(heap, 0);
    }
    free(heap);
    return res;
}

void min_heapify(Element* heap, int i) {
    int left = (i + 1) * 2 - 1, right = left + 1, min = i;

    if (left < heap_size && heap[left].value < heap[min].value) {
        min = left;
    }
    if (right < heap_size && heap[right].value < heap[min].value) {
        min = right;
    }
    if (min != i) {
        Element temp = heap[i];
        heap[i] = heap[min];
        heap[min] = temp;

        if (min < heap_size / 2) {
            min_heapify(heap, min);
        }
    }
}


Array* create_arrays(int k) {
    Array* arrays = (Array*)malloc(sizeof(Array) * k);
    int i, j;

    if (!arrays) {
        printf("Memory was not allocated");
        exit(0);
    }
    for (i = 0; i < k; i++) {
        printf("Enter the size of array%d: ", i + 1);
        scanf("%d", &arrays[i].size);
        arrays[i].data = (int*)malloc(sizeof(int) * arrays[i].size);

        if (!arrays[i].data) {
            printf("Memory was not allocated");
            exit(0);
        }
        printf("Enter the array%d elements: ", i + 1);

        for (j = 0; j < arrays[i].size; j++) {
            scanf("%d", &arrays[i].data[j]);
        }
    }
    return arrays;
}

void display(Array array) {
    int i;
    printf("The array elements are: ");

    for (i = 0; i < array.size; i++) {
        printf("%d ", array.data[i]);
    }
    printf("\n");
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void bubbleSort(int *array, int size) {
    bool flag;
    size--;

    for (int i = 0; i < size; i++) {
        flag = false;

        for (int j = 0; j < size - i; j++) {
            if (array[j] > array[j+1]) swap(&array[j], &array[j+1]);
            flag = true;
        }
        if (!flag) return;
    }
}
void insertionSort(int *array, int size) {
    int temp, j;

    for (int i = 1; i < size; i++) {
        temp = array[i];
        j = i - 1;
        while (j > -1 && array[j] > temp) array[j+2] = array[j--];
        array[j+1] = temp;
    }
}
void selectionSort(int *array, int size) {
    int i, j, k;
    
    for (i = 0; i < size - 1; i++) {
        for (j = i + 1, k = i; j < size; j++) if (array[j] < array[k]) k = j;
        swap(&array[i], &array[k]);
    }
}
int partition(int *array, int low, int high) {
    int pivot = array[low], i = low, j = high;

    do {
        do {i++;} while (array[i] <= pivot);
        do {j--;} while (array[j] > pivot);
        if (i < j) swap(&array[i], &array[j]);
    } while (i < j);
    swap(&array[low], &array[j]);
    return j;
};
void quickSort(int *array, int low, int high) {
    if (low < high) {
        int temp = partition(array, low, high);
        quickSort(array, low, temp-1);
        quickSort(array, temp+1, high); 
    }
}
void merge(int *array, int low, int mid, int high) {
    int *list = (int*)malloc((high+1)*sizeof(int)), i = low, j = mid  + 1, k = low;

    while (i <= mid && j <= high) {
        if (array[i] < array[j]) list[k++] = array[i++];
        else if (array[i] > array[j]) list[k++] = array[j++];
        else {
            list[k++] = array[i++];
            list[k++] = array[j++];
        }
    }
    for (; i <= mid; i++) list[k++] = array[i++];
    for (; j <= high; j++) list[k++] = array[j++];
    for (i = low; i <= high; i++) array[i] = list[i];
};
void mergeSort(int *array, int size) {
    int k = 2, low, mid, high;

    for (; k <= size; k *= 2) {
        for (int i = 0; i + k - 1 < size; i += k) {
            low = i;
            high = i + k - 1;
            mid = (low + high) / 2;
            merge(array, low, mid, high);
        }
    }
    if (k / 2 < size) merge(array, 0, k / 2, size - 1);
}
void countSort(int *array, int size) {
    int max = array[0], i, j;
    for (i = 1; i < size; i++) if (array[i] > max) max = array[i];
    int *list = (int*)malloc((++max)*sizeof(int));
    for (i = 0; i < max; i++) list[i] = 0;
    for (i = 0; i < size; i++) list[array[i]]++;
    i = j = 0;

    while (i < max) {
        if (list[i] > 0) {
            array[j++] = i;
            list[i]--;
        } else i++;
    }
}
void radixSort(int *array, int size) {
    typedef struct Node {
        int data;
        struct Node *next;
    } Node;
    Node **list = (Node**)malloc(10*sizeof(Node*)), *current;
    int max = array[0], i, j, div;
    for (i = 1; i < size; i++) if (array[i] > max) max = array[i];

    for (int k = 1; k <= max; k *= 10) {
        for (i = 0; i < 10; i++) list[i] = NULL;
        for (i = 0; i < size; i++) {
            div = (array[i] / k) % 10;

            if (!list[div]){
                list[div] = (Node*)malloc(sizeof(Node));
                list[div]->data = array[i];
                list[div]->next = NULL;
            }else {
                current = list[div];
                while (current->next) current = current->next;
                current->next = (Node*)malloc(sizeof(Node));
                current = current->next;
                current->data = array[i];
                current->next = NULL;
            }
        }
        for (i = j = 0; i < 10; i++) {
            current = list[i];

            while (current) {
                array[j++] = current->data;
                current = current->next;
            }
        }
    }
}
void shellSort(int *array, int size) {
    for (int gap = size / 2, i, j, temp; gap >= 1; gap /= 2) {
        for (i = gap; i < size; i++) {
            temp = array[i];
            j = i - gap;

            while (j > -1 && array[j] > temp) {
                array[j+gap] = array[j];
                j -= gap;
            }
            array[j+gap] = temp;
        }
    }
}

int main() {
    return 0;
}
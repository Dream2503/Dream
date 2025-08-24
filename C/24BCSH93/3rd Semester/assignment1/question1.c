// Implementation of Iterative Linear Search

#include <stdio.h>
#include <stdlib.h>

int* create_array(int);
int binary_search(int*, int, int);
void display_array(int*, int);

int main() {
    int size, key;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int* array = create_array(size);
    display_array(array, size);
    printf("Enter the key to search in the array: ");
    scanf("%d", &key);
    int pos = binary_search(array, size, key);

    if (pos == -1) {
        printf("The element %d is not found in the array\n", key);
    } else {
        printf("The element %d found at index %d in the array\n", key, pos);
    }
    free(array);
    return 0;
}

int* create_array(int size) {
    int *array = (int*)malloc(sizeof(int) * size), i;
    printf("Enter %d array elements: ", size);

    for (i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    return array;
}

int binary_search(int* array, int size, int key) {
    int i;

    for (i = 0; i < size; i++) {
        if (array[i] == key) {
            return i;
        }
    }
    return -1;
}

void display_array(int* array, int size) {
    int i;
    printf("The array elements are: ");

    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

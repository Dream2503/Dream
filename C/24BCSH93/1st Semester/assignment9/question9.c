#include <stdio.h>

int max(int[], int);

int main() {
    int size, i;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int array[size];
    printf("Enter the elements of the array: ");

    for (i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    printf("Maximum element of the array is %d\n", max(array, size));
    return 0;
}

int max(int array[], int size) {
    int i, res = array[0];

    for (i = 1; i < size; i++) {
        if (res < array[i]) {
            res = array[i];
        }
    }
    return res;
}

#include <stdio.h>

int main() {
    int size, i, pos;
    printf("Enter the total no. of elements: ");
    scanf("%d", &size);
    int array[size];
    printf("Enter the array elements: ");

    for (i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    printf("Enter the postion of the element to delete: ");
    scanf("%d", &pos);

    for (i = pos; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    size--;
    printf("Array elements after deleting are: ");

    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}

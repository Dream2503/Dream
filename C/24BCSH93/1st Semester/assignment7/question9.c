#include <stdio.h>

int main() {
    int size, i, flag, temp;
    printf("Enter total no. of elements:");
    scanf("%d", &size);
    int array[size];
    printf("Enter the array elements: ");

    for (i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    for (i = 0; i < size - 1; i++) {
        flag = 0;

        for (i = 0; i < size - i - 1; i++) {
            if (array[i] > array[i + 1]) {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }
    printf("Sorted array is: ");

    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}

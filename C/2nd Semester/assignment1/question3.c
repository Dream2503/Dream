/*
Name:- Swapnaraj Mohanty
SIC :- 24BCSH93
Sec :- C2

Q. Write a user defined function to delete an element from the array that is passed to it as function argument. Call it
in main().
*/

#include <stdio.h>

int delete(int[], int *, int);

int main() {
    int array[20], n, i, pos, key;
    printf("Enter the no. of elements of the array: ");
    scanf("%d", &n);

    printf("Enter the array elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    printf("Enter the position to delete the element in the array: ");
    scanf("%d", &pos);

    key = delete(array, &n, pos);

    printf("The array after deletion is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\nValue deleted is %d\n", key);
    return 0;
}

int delete(int array[], int *n, int pos) {
    int i, key = array[pos];

    for (i = pos; i < *n - 1; i++) {
        array[i] = array[i + 1];
    }
    *n -= 1;
    return key;
}

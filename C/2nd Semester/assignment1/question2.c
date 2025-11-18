/*
Name:- Swapnaraj mohanty
SIC :- 24BCSH93
Sec :- C2

Q. Write a user defined function to insert an element into the array at certain position that is passed to it as
function argument. Call it in main().
*/

#include <stdio.h>

void insert(int[], int *, int, int);

int main() {
    int array[20], n, i, key, pos;
    printf("Enter the no. of elements of the array: ");
    scanf("%d", &n);

    printf("Enter the array elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    printf("Enter the value and position to insert a element in the array: ");
    scanf("%d%d", &key, &pos);

    insert(array, &n, key, pos);

    printf("The array after insertion is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}

void insert(int array[], int *n, int key, int pos) {
    int i;

    for (i = *n - 1; i >= pos; i--) {
        array[i + 1] = array[i];
    }
    array[pos] = key;
    *n += 1;
}

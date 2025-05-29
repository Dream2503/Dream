/*
Name:- Swapnaraj Mohanty
SIC :- 24BCSH93
Sec :- C2

Q. Write a user defined function to search for an element in the array by linear search algorithm. Call it in main() to
display the position of the element if it is found, other display suitable error message if it in not found.
*/

#include <stdio.h>

int linear_search(int[], int, int);

int main() {
    int array[20], n, i, key, pos;
    printf("Enter the no. of elements of the array: ");
    scanf("%d", &n);

    printf("Enter the array elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    printf("Enter the key to search: ");
    scanf("%d", &key);

    pos = linear_search(array, n, key);

    if (pos == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", pos);
    }
    return 0;
}

int linear_search(int array[], int n, int key) {
    int i;

    for (i = 0; i < n; i++) {
        if (array[i] == key) {
            return i;
        }
    }
    return -1;
}

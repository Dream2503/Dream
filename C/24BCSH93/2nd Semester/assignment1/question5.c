/*
Name:- Swapnaraj Mohanty
SIC :- 24BCSH93
Sec :- C2

Q. Write a user defined function to search for an element in the array by using binary search algorithm. Call it in
main() to display the position of the element if it is found, otherwise display suitable error message if it is not
found.
*/

#include <stdio.h>

int binary_search(int[], int, int);

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

    pos = binary_search(array, n, key);

    if (pos == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", pos);
    }
    return 0;
}

int binary_search(int array[], int n, int key) {
    int low = 0, mid, high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;

        if (array[mid] > key) {
            low = mid + 1;
        } else if (array[mid] > key) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

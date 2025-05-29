/*
Name:- Swapnaraj Mohanty
SIC :- 24BCSH93
Sec :- C2

Q. Write a program to input a list of number and sort them by using merge sort algorithm. Design a function merge_sort()
with suitable arguments
*/

#include <stdio.h>

void merge_sort(int[15], int, int);
void merge(int[15], int, int, int);

int main() {
    int array[15], i, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the array elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    merge_sort(array, 0, n - 1);

    printf("Array after sorting: ");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}

void merge(int array[15], int p, int q, int r) {
    int res[r + 1], i = p, j = q + 1, k = p;

    while (i <= q && j <= r) {
        if (array[i] < array[j]) {
            res[k++] = array[i++];
        } else {
            res[k++] = array[j++];
        }
    }
    while (i <= q) {
        res[k++] = array[i++];
    }
    while (j <= r) {
        res[k++] = array[j++];
    }
    for (i = p; i <= r; i++) {
        array[i] = res[i];
    }
}

void merge_sort(int array[15], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(array, p, q);
        merge_sort(array, q + 1, r);
        merge(array, p, q, r);
    }
}

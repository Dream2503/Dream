/*
Name:- Swapnaraj Mohanty
SIC :- 24BCSH93
Sec :- C2

Q. Write a function to merge two arrays A and B after inputting them in main(). Call it in main() to show the merged
array C.
*/

#include <stdio.h>

void merge(int[], int, int[], int, int[], int *);

int main() {
    int array1[20], array2[20], array[40], n1, n2, n, i;
    printf("Enter the no. of elements of the first array: ");
    scanf("%d", &n1);

    printf("Enter the elements of the first array: ");
    for (i = 0; i < n1; i++) {
        scanf("%d", &array1[i]);
    }
    printf("Enter the no. of elements of the second array: ");
    scanf("%d", &n2);

    printf("Enter the elements of the second array: ");
    for (i = 0; i < n2; i++) {
        scanf("%d", &array2[i]);
    }
    merge(array1, n1, array2, n2, array, &n);

    printf("The merged array is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}

void merge(int array1[], int n1, int array2[], int n2, int array[], int *n) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (array1[i] < array2[j]) {
            array[k++] = array1[i++];
        } else {
            array[k++] = array2[j++];
        }
    }
    while (i < n1) {
        array[k++] = array1[i++];
    }
    while (j < n2) {
        array[k++] = array2[j++];
    }
    *n = n1 + n2;
}

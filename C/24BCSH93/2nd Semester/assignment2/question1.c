/*
Name:- Swapnaraj Mohanty
SIC :- 24BCSH23
Sec :- C2

Q. Write a program to input a list of number and sort them by using bubble sort algorithm. Design a function
bubble_sort() with suitable arguments
*/

#include <stdio.h>

void bubble_sort(int[], int);

int main() {
    int array[20], n, i;
    printf("Enter the no. of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the array elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    bubble_sort(array, n);

    printf("Array elements after sorting is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}

void bubble_sort(int array[], int n) {
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

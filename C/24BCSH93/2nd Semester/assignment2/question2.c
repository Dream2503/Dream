/*
Name:- Swapanaraj Mohanty
SIC :- 24BCSH23
Sec :- C2

Q. Write a program to input a list of number and sort them by using selection sort algorithm. Design a function selection_sort() with suitable arguments
*/

#include <stdio.h>

void selection_sort(int[], int);

int main() {
	int array[20], n, i;
	printf("Enter the no. of elements in the array: ");
	scanf("%d", &n);

	printf("Enter the array elements: ");
	for (i = 0; i < n; i++) {
		scanf("%d", &array[i]);
	}
	selection_sort(array, n);

	printf("Array elements after sorting is: ");
	for (i = 0; i < n; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	return 0;
}

void selection_sort(int array[], int n) {
	int i, j, min, temp;

	for (j = 0; j < n - 1; j++) {
		min = j;
		
		for (i = j + 1; i < n; i++) {
			if (array[i] < array[min]) {
				min = i;
			}
		}
		if (min != j) {
			temp = array[j];
			array[j] = array[min];
			array[min] = temp;
		}
	}
}
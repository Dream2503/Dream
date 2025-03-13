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

	for (i = 0; i < n - 1; i++) {
		min = i;
		
		for (j = i + 1; j < n; j++) {
			if (array[j] < array[min]) {
				min = j;
			}
		}
		if (min != i) {
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
		}
	}
}
/*
Name:- Swapanaraj Mohanty
SIC :- 24BCSH23
Sec :- C2

Q. Write a program to input a list of number and sort them by using insertion sort algorithm. Design a function insertion_sort() with suitable arguments
*/

#include <stdio.h>

void insertion_sort(int[], int);

int main() {
	int array[20], n, i;
	printf("Enter the no. of elements in the array: ");
	scanf("%d", &n);

	printf("Enter the array elements: ");
	for (i = 0; i < n; i++) {
		scanf("%d", &array[i]);
	}
	insertion_sort(array, n);

	printf("Array elements after sorting is: ");
	for (i = 0; i < n; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	return 0;
}

void insertion_sort(int array[], int n) {
	int j, i, temp;

	for (i = 1; i < n; i++) {
		temp = array[i];
		j = i - 1;

		while (j >= 0 && array[j] > temp) {
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = temp;
	}
}
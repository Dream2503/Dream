/*
Name:- Swapnaraj Mohanty
SIC :- 24BCSH93
Sec :- C2

Q. Write a program to input a list of number and sort them by using quick sort algorithm. Design a function quick_sort() with suitable arguments
*/

#include <stdio.h>

void quick_sort(int[15], int, int);
int partition(int[15], int, int);

int main() {
    int array[15], i, n;
	printf("Enter the number of elements: ");
	scanf("%d", &n);

	printf("Enter the array elements: ");
	for (i = 0; i < n; i++) {
		scanf("%d", &array[i]);
	}
	quick_sort(array, 0, n - 1);

	printf("Array after sorting: ");
	for (i = 0; i < n; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	return 0;
}

int partition(int array[15], int p, int r) {
	int x = array[p], i = p - 1, j = r + 1, temp;

	while (i < j) {
		for (i = i + 1; array[i] < x; i++);
		for (j = j - 1; array[j] > x; j--);

		if (i < j) {
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		} else {
			return j;
		}
	}
    return p;
}

void quick_sort(int array[15], int p, int r) {
    if (p < r) {
		int q = partition(array, p, r);
 		quick_sort(array, p, q);
		quick_sort(array, q + 1, r);
	}
}
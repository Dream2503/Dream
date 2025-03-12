/*
Name:- Swapnaraj Mohanty
SIC :- 24BCSH93
Sec :- C2

Q. Write a function to find the largest and smallest element of an array. Call it in main() to show the output.
*/

#include <stdio.h>

void max_min(int[], int); 

int main() {
	int array[20], n, i;
	printf("Enter the no. of elements in the array: ");
	scanf("%d", &n);

	printf("Enter the array elements: ");
	for (i = 0; i < n; i++) {
		scanf("%d", &array[i]);
	}
	max_min(array, n);
	return 0;
}

void max_min(int array[], int n) {
	int large = array[0], small = array[0], i;
	
	for (i = 1; i < n; i++) {
		if (array[i] > large) {
			large = array[i];
		} else if (array[i] < small) {
			small = array[i];
		}
	}
	printf("Largest element is %d\n", large);
	printf("Smallest elements is %d\n", small);
}
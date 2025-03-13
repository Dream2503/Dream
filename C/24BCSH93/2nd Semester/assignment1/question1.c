/*
   Name:- Swapnaraj Mohanty
   SIC:- 24BCSH93
   Sec:- C2

   Q. Write a user defined function to create an array and input elements into it, and then display the elements by using another function. Call them in main().
*/

#include <stdio.h>

void create(int[], int);
void display(int[], int);

int main() {
	int array[20], n;
	printf("Enter the no. of elements of the array: ");
	scanf("%d", &n);
	create(array, n);
	display(array, n);
	return 0;
}

void create(int array[], int n) {
	int i;
	printf("Enter the array elements: ");

	for (i = 0; i < n; i++) {
		scanf("%d", &array[i]);
	}
}

void display(int array[], int n) {
	int i;
	printf("Array elements are: ");
	
	for (i = 0; i < n; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}
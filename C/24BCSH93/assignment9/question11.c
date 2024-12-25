#include <stdio.h>

void sort(int[], int);

int main() {
	int size, i;
	printf("Enter the size of the array: ");
	scanf("%d", &size);
	int array[size];
	printf("Enter the elements of the array: ");

	for (i = 0; i < size; i++) {
		scanf("%d", &array[i]);
	}
	sort(array, size);
	printf("Sorted array is ");

	for (i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	return 0;
}

void sort(int array[], int size) {
	int i, j, temp;
	
	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - i -1; j++) {
			if (array[j] > array[j+1]) {
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
}

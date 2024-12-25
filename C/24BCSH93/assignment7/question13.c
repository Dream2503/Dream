#include <stdio.h>

int main() {
	int size, i, j, temp;
	printf("Enter the total no. of elements: ");
	scanf("%d", &size);
	
	int array[size];
	printf("Enter the array elements: ");

	for (i = 0; i < size; i++) {
		scanf("%d", &array[i]);
	}
	for (i = 0; i < 2; i++) {
		for (j = 0; j < size - i - 1; j++) {
			if (array[j] > array[j+1]) {
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;;
			}
		}
	}
	printf("The second largest element in the array is: %d\n", array[size-2]);
	return 0;

}


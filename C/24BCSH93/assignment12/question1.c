#include <stdio.h>

int main() {
	int size;
	printf("Enter the size of the array: ");
	scanf("%d", &size);
	int array[size], i, sum = 0, *ptr = array;
	printf("Enter the array elements: ");

	for (i = 0; i < size; i++) {
		scanf("%d" , &array[i]);
	}
	for (i = 0; i < size; i++) {
		sum += *(ptr + i);
	}
	printf("Sum of elements of the array is %d\n", sum);
	return 0;
}

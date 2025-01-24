#include <stdio.h>

int main() {
	int size, i, pos, value;
	printf("Enter the total no. of elements: ");
	scanf("%d", &size);
	int array[size+1];
	printf("Enter the array elements: ");
	
	for (i = 0; i < size; i++) {
		scanf("%d", &array[i]);
	}
	printf("Enter the value and position of the element to insert: ");
	scanf("%d%d", &value, &pos);

	for (i = size-1; i >= pos; i--) {
		array[i+1] = array[i];
	}
	array[pos] = value;
	size++;
	printf("Array elements after inserting are: ");
	
	for (i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	return 0;
}
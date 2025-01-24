#include <stdio.h>
#include <stdlib.h>

int main() {
	int size, i, max = 0;
	printf("Enter the size of the array: ");
	scanf("%d", &size);
	int *array = (int*)malloc(sizeof(int) * size);
	printf("Enter the array elements: ");
	
	for (i = 0; i < size; i++) {
		scanf("%d", array + i);
	}
	for (i = 0; i < size; i++) {
		if (max < *(array + i)) {
			max = *(array + i);
		}
	}
	printf("Maximum element of the array is %d\n", max);
	free(array);
	array = NULL;
	return 0;
}
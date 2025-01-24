#include <stdio.h>
#include <stdlib.h>

int main() {
	int size, i, flag = 0;
	printf("Enter the size of the array: ");
	scanf("%d", &size);
	int *array = (int*)malloc(sizeof(int) * size), key;
	printf("Enter the array elements: ");
	
	for (i = 0; i < size; i++) {
		scanf("%d", array + i);
	}
	printf("Enter the key to search: ");
	scanf("%d", &key);

	for (i = 0; i < size; i++) {
		if (key == *(array + i)) {
			flag = 1;
		}
	}
	if (flag) {
		printf("Element is present in the array\n");
	} else {
		printf("Element is not present in the array\n");
	}
	free(array);
	array = NULL;
	return 0;
}
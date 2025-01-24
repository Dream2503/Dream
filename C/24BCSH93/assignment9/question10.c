#include <stdio.h>

int search(int[], int, int);

int main() {
	int size, i, key, flag;
	printf("Enter the size of the array: ");
	scanf("%d", &size);
	int array[size];
	printf("Enter the elements of the array: ");

	for (i = 0; i < size; i++) {
		scanf("%d", &array[i]);
	}
	printf("Enter the key to search: ");
	scanf("%d", &key);
	flag = search(array, size, key);
	
	if (flag) {
		printf("The element is present in the array\n");
	} else {
		printf("The element is not present in the array\n");
	}
	return 0;
}

int search(int array[], int size, int key) {
	int i;

	for (i = 0; i < size; i++) {
		if (array[i] == key) {
			return 1;
		}
	}
	return 0;
}
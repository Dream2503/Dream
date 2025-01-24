#include <stdio.h>

int main() {
	int array1[5], array2[5], res[10], i;
	printf("Enter 5 elements for array1:\n");
	
	for (i = 0; i < 5; i++) {
		scanf("%d", &array1[i]);
	}
	printf("Enter 5 elements for array2:\n");
	
	for (i = 0; i < 5; i++) {
		scanf("%d", &array2[i]);
	}
	for (i = 0; i < 5; i++) {
		res[i] = array1[i];
	}
	for (i = 0; i < 5; i++) {
		res[5+i] = array2[i];
	}
	printf("Resultant array: ");
	
	for (i = 0; i < 10; i++) {
		printf("%d ", res[i]);
	}
	printf("\n");
	return 0;
}
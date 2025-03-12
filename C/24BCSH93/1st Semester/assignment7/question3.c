#include <stdio.h>

int main() {
	int array[5], sum = 0, i;
	printf("Enter 5 elements:\n");
	
	for (i = 0; i < 5; i++) {
		scanf("%d", &array[i]);
	}
	for (i = 0; i < 5; i++) {
		if (array[i] % 2 != 0) {
			sum += array[i];
		}
	}
	printf("Sum of odd elements are: %d\n", sum);
	return 0;
}
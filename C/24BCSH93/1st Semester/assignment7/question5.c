#include <stdio.h>

int main() {
	int array[5], max, i;
	printf("Enter 5 elements:\n");
	
	for (i = 0; i < 5; i++) {
		scanf("%d", &array[i]);
	}
	max = array[0];

	for (i = 0; i < 5; i++) {
		if (max < array[i]) {
			max = array[i];
		}
	}
	printf("Maximum element is %d\n", max);
	return 0;
}
#include <stdio.h>

int main() {
	int size, i, even = 0, odd = 0;
	printf("Enter the size of the array: ");
	scanf("%d", &size);
	int array[size];
	printf("Enter the array elements: ");

	for (i = 0; i < size; i++) {
		scanf("%d", &array[i]);
	}	
	for (i = 0; i < size; i++) {
		if (array[i] % 2 == 0) {
			even++;
		}
		else {
			odd++;
		}
	}
	printf("No. of even numbers in the array is %d\n", even);
	printf("No. of odd numbers in the array is %d\n", odd);
	return 0;
}
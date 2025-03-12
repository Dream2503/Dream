#include <stdio.h>

int main() {
	int lr, ur, sum = 0;
	printf("Enter the lowe range and the upper range  numbers: ");
	scanf("%d%d", &lr, &ur);

	for (; lr <= ur; lr++) {
		if (lr % 2 == 0) {
			sum += lr;
		}
	}
	printf("Sum of all even numbers are: %d\n", sum);
	return 0;
}
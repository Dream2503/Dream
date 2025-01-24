#include <stdio.h>

int main() {
	int i, num, sum = 1;
	printf("Enter a number: ");
	scanf("%d", &num);

	for (i = 3; i <= num; i++) {
		if (num % i == 0 && i % 2 == 1) {
			sum += i;
		}
	}
	printf("Sum of all odd factors are %d\n", sum);
	return 0;
}
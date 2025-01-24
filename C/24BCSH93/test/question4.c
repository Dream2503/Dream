#include <stdio.h>

int main() {
	int num, i, sum = 0;
	printf("Enter a number: ");
	scanf("%d", &num);

	for (i = 1; i < num; i++) {
		if (num % i == 0) {
			sum += i;
		}
	}
	if (num == sum) {
		printf("Perfect Number\n");
	} else {
		printf("Not a Perfect Number\n");
	}
	return 0;
}
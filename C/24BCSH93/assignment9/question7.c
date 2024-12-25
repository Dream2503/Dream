#include <stdio.h>

int recurSumDigits(int);

int main() {
	int num;
	printf("Enter a number: ");
	scanf("%d", &num);
	printf("Sum of the digits is %d\n", recurSumDigits(num));
	return 0;
}

int recurSumDigits(int num) {
	if (num == 0) {
		return 0;
	}
	return (num % 10) + recurSumDigits(num/10);
}

#include <stdio.h>
#include <math.h>

int is_armstrong(int);

int main() {
	int num;
	printf("Enter a number: ");
	scanf("%d", &num);
	if (is_armstrong(num)) {
		printf("The number is an amstrong number\n");
	} else {
		printf("The number is not an amstrong number\n");
	}
	return 0;
}

int is_armstrong(int num) {
	int temp = num, digits = 0, amg = 0;

	while (temp != 0) {
		temp /= 10;
		digits++;
	}
	temp = num;

	while (temp != 0) {
		amg += pow(temp % 10, digits);
		temp /= 10;
	}
	return num == amg;
}

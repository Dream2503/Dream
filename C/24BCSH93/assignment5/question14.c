#include <stdio.h>
#include <math.h>

int main() {
	int num, temp, digits = 0, amg = 0;
	printf("Enter a number: ");
	scanf("%d", &num);
	temp = num;

	while (temp != 0) {
		temp /= 10;
		digits++;
	}
	temp = num;

	while (temp != 0) {
		amg += pow(temp % 10, digits);
		temp /= 10;
	}
	num == amg ? printf("It is an armstrong number\n") : printf("It is not an armstrong number\n");
	return 0;
}

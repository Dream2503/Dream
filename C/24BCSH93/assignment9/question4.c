#include <stdio.h>

int checkPrime(int);

int main() {
	int num, flag;
	printf("Enter a number: ");
	scanf("%d", &num);
	flag = checkPrime(num);

	if (flag) {
		printf("It is a prime number\n");
	} else {
		printf("It is a composite number\n");
	}
	return 0;
}

int checkPrime(int num) {
	int i;

	for (i = 2; i <= num / 2; i++) {
		if (num % i == 0) {
			return 0;
		}
	}
	return 1;
}
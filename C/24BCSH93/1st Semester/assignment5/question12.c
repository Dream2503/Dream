#include <stdio.h>

int main() {
	int num, i, flag = 0;
	printf("Enter a number: ");
	scanf("%d", &num);

	for (i = 2; i <= num / 2; i++) {
		if (num % i == 0) {
			flag = 1;
			break;
		}
	}
	if (flag) {
		printf("It is a composite number\n");
	} else {
		printf("It is a prime number\n");
	}
	return 0;
}
#include <stdio.h>

int main() {
	int num;
	printf("Enter a number: ");
	scanf("%d", &num);

	switch (num % 2) {
		case 0:
			printf("Number is even\n");
			break;
		default:
			printf("Number is odd\n");
	}
	return 0;
}
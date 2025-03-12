#include <stdio.h>

int main() {
	int num;
	printf("Enter a number: ");
	scanf("%d", &num);

	if (num != 0) {
		if (num > 0) {
			printf("It is a positive number\n");
		} else {
			printf("It is a negative number\n");
		}
	} else {
		printf("It is equal to zero\n");
	}
	return 0;
}
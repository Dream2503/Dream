#include <stdio.h>

int main() {
	int num;
	printf("Enter a number: ");
	scanf("%d", &num);
	num % 2 == 0 ? printf("%d is an even number\n", num) : printf("%d is an odd number\n", num);
	return 0;
}

#include <stdio.h>

int main() {
	int num;
	printf("Enter a number: ");
	scanf("%d", &num);
	if (num % 15 == 0) printf("The number is divisible by 3 and 5\n");
	else printf("The number is not divisible by 3 and 5\n");
	return 0;
}

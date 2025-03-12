#include <stdio.h>

int main() {
	int num, res = 0;
	printf("Enter the number: ");
	scanf("%d",&num);
	
	while (num != 0) {
		res += (num % 10);
		num /= 10;
	}

	printf("Sum of digits: %d\n", res);
	return 0;
}
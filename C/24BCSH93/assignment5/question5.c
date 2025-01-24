#include <stdio.h>

int main() {
	int num, sum = 0;

	do {
		printf("Enter a number: ");
		scanf("%d", &num);
		sum += num;	
	} while (sum <= 100);
	printf("Final Sum is %d\n", sum - num);
	return 0;
}
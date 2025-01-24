#include <stdio.h>

int main() {
	int num, i = 1;
	printf("Enter a number: ");
	scanf("%d", &num);

	do {
		printf("%d ", i);
		i++;
	} while (i <= num);
	printf("\n");
	return 0;
}
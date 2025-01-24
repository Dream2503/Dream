#include <stdio.h>

int main() {
	int last = 0, first = 1, num, temp;
	printf("Enter a number: ");
	scanf("%d", &num);
	printf("0 ");

	do {
		printf("%d ", first);
		temp = first;
		first += last;
		last = temp;
	} while (first <= num);
	printf("\n");
	return 0;
}
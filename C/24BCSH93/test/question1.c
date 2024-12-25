#include <stdio.h>

int main() {
	int inch;
	printf("Enter the total inches: ");
	scanf("%d", &inch);
	printf("%d feet and %d inches\n", inch / 12, inch % 12);
	return 0;
}

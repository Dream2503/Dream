#include <stdio.h>

int main() {
	int cp, sp;
	printf("Enter the cost price and the selling price: ");
	scanf("%d%d", &cp, &sp);

	if (cp - sp >= 0) {
		printf("Loss\n");
	} else {
		printf("Profit\n");
	}
	return 0;
}
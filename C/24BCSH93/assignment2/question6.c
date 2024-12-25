#include <stdio.h>

int main() {
	int grams;
	printf("Enter the grams: ");
	scanf("%d", &grams);
	printf("%d KG %d grams\n", grams / 1000, grams % 1000);
	return 0;
}

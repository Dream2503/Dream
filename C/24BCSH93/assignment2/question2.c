#include <stdio.h>

int main() {
	float F;
	printf("Enter the temperature in F: ");
	scanf("%f", &F);
	printf("Temperature in C: %.2f\n", 0.56 * (F - 32));
	return 0;
}
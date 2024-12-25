#include <stdio.h>

int main() {
	float amount;
	printf("Enter the total amount: ");
	scanf("%f", &amount);
	
	if (amount > 10000) amount -= 2000;
	else if (amount > 6000) amount -= 0.1 * amount;
	else if (amount > 3000) amount -= 0.07 * amount;
	else if (amount >= 1000) amount -= 0.05 * amount;

	printf("Total paybale amount is %f\n", amount);
	return 0;
}

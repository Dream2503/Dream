#include <stdio.h>

int main() {
	float price1, price2, price3, total;
	int quant1, quant2, quant3;
	printf("Enter the 3 prices of the products: ");
	scanf("%f%f%f", &price1, &price2, &price3);
	printf("Enter the respective quantities: ");
	scanf("%d%d%d", &quant1, &quant2, &quant3);
	total = (price1 * quant1) + (price2 * quant2) + (price3 * quant3);
	total += total * .1;
	printf("Total bill: %.2.2f\n", total);
	return 0;
}
#include <stdio.h>

int main() {
	float price1, price2, price3, price4, discount, total;
	printf("Enter the prices of 4 different products: ");
	scanf("%f%f%f%f", &price1, &price2, &price3, &price4);
	total = price1 + price2 + price3 + price4;
	discount = 0.07 * total;
	total -= discount;
	total += total > 1000 ? -150 : 0;
	printf("Discount by shop = %f RS\n", discount);
	printf("Final playable amount after additional discount = %f RS\n", total);
	return 0;
}
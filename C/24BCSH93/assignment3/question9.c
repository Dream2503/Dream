#include <stdio.h>

int main() {
	int cost_price, selling_price;
	printf("Enter the cost price and the selling price: ");
	scanf("%d%d", &cost_price, &selling_price);
	if (cost_price - selling_price >= 0) printf("Loss\n");
	else printf("Profit\n");
	return 0;
}

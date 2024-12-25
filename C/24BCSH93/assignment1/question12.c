/* 
Date: 23/09/24
By: Swapnaraj Mohanty (24BCSH93)
*/

#include <stdio.h>

int main() {
	int p, r ,t;
	printf("Enter the principle account, rate of interest and time period: ");
	scanf("%d%d%d", &p, &r, &t);
	printf("Simple Interest = %f\n", (p * r * t) / 100.0);
	return 0;
}

/* 
Date: 23/09/24
By: Swapnaraj Mohanty (24BCSH93)
*/

#include <stdio.h>

int main() {
	int num1, num2;
	printf("Enter 2 numbers: ");
	scanf("%d%d", &num1, &num2);
	
	int temp = num1;
	num1 = num2;
	num2 = temp;
	
	printf("Swapped numbers: %d and %d\n", num1, num2);
	return 0;
}
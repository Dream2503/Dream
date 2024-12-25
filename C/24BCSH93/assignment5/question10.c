#include <stdio.h>

int main() {
	int num, bin = 0, factor = 1;
	printf("Enter a number: ");
	scanf("%d", &num);
	
	while (num != 0) {
		bin += (num % 2) * factor;
		num /= 2;
		factor *= 10;
	}
	printf("Binary equivalent is %d\n", bin);
	return 0;
}

#include <stdio.h>
#include <math.h>

int main() {
	int bin, dec = 0, i = 0;
	printf("Enter a binary number: ");
	scanf("%d", &bin);

	while (bin != 0) {
		dec += (bin % 10) * pow(2, i);
		i++;
		bin /= 10;
	}
	printf("Decimal Equivalent is %d\n", dec);
	return 0;
}

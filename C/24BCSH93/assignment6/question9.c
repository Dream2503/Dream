#include <stdio.h>
#include <math.h>

int main() {
	int lr, ur, temp, digits, amg;
	printf("Enter lower range and upper range numbers: ");
	scanf("%d%d", &lr, &ur);

	for (; lr <= ur; lr++) {
		digits = amg = 0;
		temp = lr;

		while (temp != 0) {
			temp /= 10;
			digits++;
		}
		temp = lr;
	
		while (temp != 0) {
			amg += pow(temp % 10, digits);
			temp /= 10;
		}
		if (lr == amg) {
			printf("%d ", lr);
		}
	}
	printf("\n");
	return 0;
}
#include <stdio.h>

int main() {
	int lr, ur, temp, rev;
	printf("Enter lower range and upper range number: ");
	scanf("%d%d", &lr, &ur);

	for (; lr <= ur; lr++) {
		rev = 0;
		temp = lr;

		while (temp != 0) {
			rev = (rev * 10) + (temp % 10);
			temp /= 10;
		}
		if (rev == lr) printf("%d ", lr);
	}
	printf("\n");
	return 0;
}

#include <stdio.h>

int sumOddRange(int, int);

int main() {
	int lr, ur, res;
	printf("Enter the lower range and upper range: ");
	scanf("%d%d", &lr, &ur);
	res = sumOddRange(lr, ur);
	printf("Sum of all the odd numbers in the range %d to %d is %d\n", lr, ur, res);
	return 0;
}

int sumOddRange(int lr, int ur) {
	int res = 0;

	for (; lr <= ur; lr++) {
		if (lr % 2 != 0) {
			res += lr;
		}
	}
	return res;
}
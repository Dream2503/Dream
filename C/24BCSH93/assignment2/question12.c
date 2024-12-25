#include <stdio.h>

int main() {
	int a, b, c, min;
	printf("Enter 3 numbers: ");
	scanf("%d%d%d", &a, &b, &c);
	min = a < b ? (a < c ? a : (b < c ? b : c)) : (b < c ? b : (a < c ? a : c));
	printf("Min : %d\n", min);
	return 0;
}

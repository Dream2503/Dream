#include <stdio.h>

int main() {
	int a, b, c;
	printf("Enter three numbers: ");
	scanf("%d%d%d", &a, &b, &c);
	printf("res = %d\n", a < b ? (a < c ? a : (b < c ? b : c)) : b < c ? b : (a < c ? a : c));
	return 0;
}

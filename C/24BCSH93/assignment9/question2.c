#include <stdio.h>

int max(int, int);

int main() {
	int num1, num2, num3, temp;
	printf("Enter three numbers: ");
	scanf("%d%d%d", &num1, &num2, &num3);
	temp = max(num1, num2);
	printf("Largest number is %d\n", max(temp, num3));
	return 0;
}

int max(int a, int b) {
	return (a > b) ? a : b;
}

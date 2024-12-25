#include <stdio.h>

int recurFact(int);

int main() {
	int num;
	printf("Enter a number: ");
	scanf("%d", &num);
	printf("Factorial of the number is %d\n", recurFact(num));
	return 0;
}

int recurFact(int num) {
	if (num == 1) {
		return 1;
	}
	return num * recurFact(num - 1);
}

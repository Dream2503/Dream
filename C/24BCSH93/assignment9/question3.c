#include <stdio.h>

int fact(int);

int main() {
	int num;
	printf("Enter a number: ");
	scanf("%d", &num);
	printf("Factorial of the number is %d\n", fact(num));
	return 0;
}

int fact(int num) {
	int res = 1, i;
	
	for (i = 2; i <= num; i++) {
		res *= i;
	}
	return res;
}

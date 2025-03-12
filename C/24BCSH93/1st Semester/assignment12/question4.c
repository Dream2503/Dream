#include <stdio.h>

int *max(int*, int*);

int main() {
	int num1, num2;
	printf("Enter two numbers: ");
	scanf("%d%d", &num1, &num2);
	int *res = max(&num1, &num2);
	printf("Maximum of two numbers is %d\n", *res);
	return 0;
}

int *max(int *num1, int *num2) {
	return (*num1 > *num2) ? num1 : num2;
}
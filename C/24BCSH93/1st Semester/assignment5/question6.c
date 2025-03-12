#include <stdio.h>

int main() {
	int num, fact = 1;
	printf("Enter a number: ");
	scanf("%d", &num);
	
	for (; num > 0; num--) {
		fact *= num;
	}
	printf("Factorial is %d\n", fact);
	return 0;
}
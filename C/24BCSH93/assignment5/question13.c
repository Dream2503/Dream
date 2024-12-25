#include <stdio.h>

int main() {
	int num, temp, rev = 0;
	printf("Enter a number: ");
	scanf("%d", &num);
	temp = num;

	while (temp != 0) {
		rev = (rev * 10) + (temp % 10);
		temp /= 10;
	}
	if (rev == num) printf("It is a palindrome number\n");
	else printf("It is not a palindrome number\n");
	return 0;
}

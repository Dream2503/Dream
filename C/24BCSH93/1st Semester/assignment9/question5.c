#include <stdio.h>

int checkPalindrome(int);

int main() {
	int num, flag;
	printf("Enter a number: ");
	scanf("%d", &num);
	flag = checkPalindrome(num);

	if (flag) {
		printf("It is a palindrome number\n");
	} else {
		printf("It is not a palindrome number\n");
	}
	return 0;
}

int checkPalindrome(int num) {
	int rev = 0, temp = num;

	while (temp) {
		rev = (rev * 10) + (temp % 10);
		temp /= 10;
	}
	return rev == num;
}
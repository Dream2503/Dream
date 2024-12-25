#include <stdio.h>

int main() {
	char ch;
	printf("Enter an alphabet: ");
	scanf(" %c", &ch);
	if (ch < 97) ch += 32;
	if (ch == 'a'|| ch == 'e' || ch =='i' || ch =='o'|| ch == 'u') printf("is a vowel\n");
	else printf("not a vowel\n");
	return 0;
}

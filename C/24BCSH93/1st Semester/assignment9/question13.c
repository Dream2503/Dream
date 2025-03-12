#include <stdio.h>

int XSTRLEN(char[]);

int main() {
	char str[30];
	printf("Enter a string: ");
	scanf("%s", str);
	printf("Size of string is %d\n", XSTRLEN(str));
	return 0;
}

int XSTRLEN(char str[]) {
	int size;
	for (size = 0; str[size]; size++);
	return size;
}
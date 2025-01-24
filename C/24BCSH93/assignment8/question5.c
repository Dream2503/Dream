#include <stdio.h>

int main() {
	char str[20];
	int i = 0, size;
	printf("Enter a string: ");
	scanf("%s", str);

	while (str[i] != '\0') {
		i++;
	}
	size = i;
	printf("The size of the string is %d\n", size);
	return 0;
}
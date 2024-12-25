#include <stdio.h>

int main() {
	char str[20];
	int i = 0;
	printf("Enter a string: ");
	scanf("%s", str);

	while (str[i] != '\0') {
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] -= 32;
		}
		i++;
	}

	printf("The upper case string is %s\n", str);
	return 0;
}

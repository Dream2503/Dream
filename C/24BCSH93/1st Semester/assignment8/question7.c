#include <stdio.h>

int main() {
	char str1[20], str2[20];
	int i = 0;
	printf("Enter a string: ");
	scanf("%s", str1);

	while (str1[i] != '\0') {
		str2[i] = str1[i];
		i++;
	}
	str2[i] = '\0';
	printf("The copied string is %s\n", str2);
	return 0;
}
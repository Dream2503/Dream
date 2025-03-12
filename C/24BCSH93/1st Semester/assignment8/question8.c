#include <stdio.h>

int main() {
	char str1[20], str2[20], str[40];
	int i = 0, j = 0;
	printf("Enter the first string: ");
	scanf("%s", str1);
	printf("Enter the second string: ");
	scanf("%s", str2);

	while (str1[i] != '\0') {
		str[i] = str1[i];
		i++;
	}
	while (str2[j] != '\0') {
		str[i] = str2[j];
		i++; j++;
	}
	str[i] = '\0';
	printf("The concatenated string is %s\n", str);
	return 0;
}
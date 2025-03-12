#include <stdio.h>

int main() {
	char str[100] = "Receive th thee character from keyboard";
	char key[10] = "the";
	int i, j, res, flag = 1, curr;
	printf("The given string is --> %s\n", str);
	printf("the required substr --> %s\n", key);

	for (i = 0; str[i]; i++) {
		curr = i;
		if (str[i] == key[0]) {
			res = i;

			for (j = 0; key[j] && str[i]; j++, i++) {
				if (str[i] != key[j]) {
					flag = 0;
					break;
				}
			}
			if (flag) {
				printf("substr found at %d\n", res);
				return 0;
			}
		}
		i = curr;
		flag = 1;
	}
	printf("substr not found in the string\n");
	return 0;
}
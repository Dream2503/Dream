#include <stdio.h>
#include <stdlib.h>

int main() {
	char *name = (char*)malloc(10);
	printf("Enter your first name: ");
	scanf("%s", name);
	printf("Your first name: %s\n", name);
	name = (char*)realloc(name, 20);
	printf("Enter the entire name: ");
	scanf(" %[^\n]", name);
	printf("Entire name is %s\n", name);
	free(name);
	name = NULL;
	return 0;
}
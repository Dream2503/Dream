#include <stdio.h>

typedef struct product {
	char Pname[30];
	int PId;
	float price;
} product;

int main() {
	product p[3], *ptr = p;
	int i;

	for (i = 0; i < 3; i++) {
		printf("Enter name, id and price for product%d: ", i + 1);
		scanf("%s%d%f", ptr->Pname, &ptr->PId, &ptr->price);
		ptr++;
	}
	ptr = p;
	printf("Name\tID\tPrice\n");

	for (i = 0; i < 3; i++) {
		printf("%s\t%d\t%f\n", ptr->Pname, ptr->PId, ptr->price);
		ptr++;
	}
	return 0;
}
#include <stdio.h>

struct book {
	char name[30], author[30];
	float price;
};

int main() {
	struct book b1;
	printf("Enter the name, author and price of the book: ");
	scanf("%s%s%f", b1.name, b1.author, &b1.price);
	printf("Details of the book are: \n");
	printf("Name: %s\nAuthor: %s\nPrice: %f\n", b1.name, b1.author, b1.price);
	return 0;
}

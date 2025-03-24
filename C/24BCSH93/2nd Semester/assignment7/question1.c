/*
Name:- Swapanarj Mohanty
SIC :- 24BCSH93
Sec :- C2

Q.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} Node;

Node *start = NULL;

void create(Node*);
void display(Node*);

int main() {
	start = (Node*)malloc(sizeof(Node));
	create(start);
	display(start);
	return 0;
}

void create(Node* node) {
	node->data = 10;
	node->next = (Node*)malloc(sizeof(Node));
	node = node->next;
	node->data = 20;
	node->next = NULL;
}

void display(Node* node) {
	if (!node) {
		printf("The Linked List is empty\n");
	} else {
		printf("The elements in the Linked List are: ");

		while (node) {
			printf("%d ", node->data);
			node = node->next;
		}
		printf("\n");
	}
}
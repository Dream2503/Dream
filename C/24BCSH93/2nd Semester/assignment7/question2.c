/*
Name:- Swapnaraj Mohanty
SIC :- 24BCSH93
Sec :- C2

Q. Write a program to implement a Linked List more than one node. The user should have the option to insert a new node dynamically or exit the list. It should have the same operations(functions) defined in Question1. Also it should show how many nodes are there in the linked list at the end.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} Node;

void create_list(Node*);
void traverse(Node*);

int main() {
	Node *node = (Node*)malloc(sizeof(Node));
	
	if (!node) {
		printf("Memory was not allocated\n");
		exit(0);
	}
	create_list(node);
	traverse(node);
	return 0;
}

void create_list(Node* node) {
	int ch = 1;

	do {
		printf("Enter an element to append to the list: ");
		scanf("%d", &node->data);
		printf("Enter '1' to continue appending or '0' to stop: ");
		scanf("%d", &ch);
		
		switch (ch) {
			case 0:
				node->next = NULL;
				break;

			case 1:
				node->next = (Node*)malloc(sizeof(Node));
				node = node->next;

				if (!node) {
					printf("Memory was not allocated\n");
					exit(0);
				}
				break;

			default:
				printf("Invalid input\n");
				exit(0);
		}
	} while (ch != 0);
}

void traverse(Node* node) {
	if (!node) {
		printf("\nThe Linked List is empty\n");
	} else {
		int len = 0;
		printf("\nThe elements in the Linked List are: ");
		
		while (node) {
			printf("%d ", node->data);
			node = node->next;
			len++;
		}
		printf("\nTotal length of the Linked List is %d\n", len);
	}
}
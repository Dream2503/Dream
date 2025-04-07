/*
Name:- Swapnaraj Mohanty
SIC :- 24BCSH93
Sec :- C2

Q. Write a program to implement a Linked List with two nodes: node1 and node2. The value to be stored in node1 and node2 are 40 and 30 respectively. It should have the following operation (function):
	(i) void createList(NODE*) to create the linked list.
	(ii) void traverse(NODE*) to display the node value of the list.
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

	if (node == NULL) {
		printf("Memory was not allocated\n");
		exit(0);
	}
	create_list(node);
	traverse(node);
	return 0;
}

void create_list(Node* node) {
	node->data = 40;
	node->next = (Node*)malloc(sizeof(Node));
	node = node->next;
	
	if (node == NULL) {
		printf("Memory was not allocated\n");
		exit(0);
	}
	node->data = 30;
	node->next = NULL;
}

void traverse(Node* node) {
	if (node == NULL) {
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
/*
Name:- Swapnaraj Mohanty
SIC :- 24BCSH93
Sec :- C2

Q. Write a program to search for a particular node in a linked list created by using the function createList(NODE*). It should show the location of the node if it is found, otherwise show the message node not found.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} Node;

void create_list(Node*);
int search(Node*, int);

int main() {
	Node *node = (Node*)malloc(sizeof(Node));
	int key, pos;
	
	if (!node) {
		printf("Memory was not allocated\n");
		exit(0);
	}
	create_list(node);
	
	printf("Enter the key to search: ");
	scanf("%d", &key);
	pos = search(node, key);

	if (pos == -1) {
		printf("Element not found in the Linked List\n");
	} else {
		printf("Element found at location %d in the Linked List\n", pos);
	}
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

int search(Node* node, int key) {
	int pos = 1;

	while (node) {
		if (node->data == key) {
			return pos;
		}
		node = node->next;
		pos++;
	}
	return -1;
}
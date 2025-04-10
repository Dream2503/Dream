/*
Name:- Swapnaraj Mohanty
SIC :- 24BCSH93
Sec :- C2

Q. Merge
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} Node;

void create_list(Node*);
Node *merge(Node*, Node*);
void traverse(Node*);

int main() {
	Node *node1 = (Node*)malloc(sizeof(Node));
	Node *node2 = (Node*)malloc(sizeof(Node));
	
	if (node1 == NULL || node2 == NULL) {
		printf("Memory was not allocated\n");
		exit(0);
	}
	printf("Creating List1: \n");
	create_list(node1);
	printf("Creating List2: \n");
	create_list(node2);
	Node *node = merge(node1, node2);
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

				if (node == NULL) {
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

Node *merge(Node *node1, Node *node2) {
	Node *node = NULL, *res = NULL;
	
	if (node1 == NULL) {
		return node2;
	}


void traverse(Node* node) {
	if (node == NULL) {
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

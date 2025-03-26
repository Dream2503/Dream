/*
Name:- Swapanarj Mohanty
SIC :- 24BCSH93
Sec :- C2

Q. Write a menu-driven program ro perform the following operations on a Linked List.
	(i) Create a linked list
	(ii) Traverse a linked list
	(iii) Insert a node at the beginning of the linked list
	(iv) Insert a node at the end of the linked list
	(v) Insert a node at a given position in the linked list
	(vi) Insert a node after a specific node in the linked list
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} Node;

Node *start = NULL;

void create_list(Node*);
void insert_beg(Node*);
void insert_end(Node*);
void insert_at(Node*);
void insert_after(Node*);
void traverse(Node*);

int main() {
	Node *start = (Node*)malloc(sizeof(Node));
	
	if (start == NULL) {
		printf("Memory was not allocated\n");
		exit(0);
	}
	create_list(start);
	insert_beg(start);
	start = start;
	traverse(start);
	/*
	insert_end(node);
	traverse(node);
	insert_at(node);
	traverse(node);
	insert_after(node);
	traverse(node);
	*/
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

void insert_beg(Node* node) {
	start = (Node*)malloc(sizeof(Node));

	if (start == NULL) {
		printf("Memory was not allocated\n");
		exit(0);
	}
	printf("\nEnter the element to insert at the beginning: ");
	scanf("%d", &start->data);
	start->next = node;
}

void insert_end(Node* node) {
	while (node->next != NULL) {
		node = node->next;
	}
	node->next = (Node*)malloc(sizeof(Node));
	node = node->next;

	if (node == NULL) {
		printf("Memory was not allocated\n");
		exit(0);
	}
	printf("\nEnter the element to insert at the end: ");
	scanf("%d", &node->data);
	node->next = NULL;
}

void insert_at(Node *node) {
	int idx, pos = 1;
	printf("\nEnter the position to insert the element: ");
	scanf("%d", &idx);

	if (idx <= 1) {
		printf("Invalid postion\n");
		return;
	}
	while (node->next != NULL && pos != idx - 1) {
		node = node->next;
		pos++;
	}
	if (node->next == NULL) {
		printf("Invalid postion\n");
		return;
	}
	Node *new = (Node*)malloc(sizeof(Node));

	if (new == NULL) {
		printf("Memory was not allocataed\n");
		exit(0);
	}
	printf("Enter the element to insert: ");
	scanf("%d", &new->data);
	new->next = node->next;
	node->next = new;
}

void insert_after(Node* node) {
	int element;
	printf("\nEnter the after which element to insert: ");
	scanf("%d", &element);

	while (node != NULL && node->data != element) {
		node = node->next;
	}
	if (node == NULL) {
		printf("Element %d is not found\n", element);
		exit(0);
	} else {
		Node *new = (Node*)malloc(sizeof(Node));
		
		if (new == NULL) {
			printf("Memory was not allocated\n");
			exit(0);
		}
		printf("Enter the element to insert: ");
		scanf("%d", &new->data);
		new->next = node->next;
		node->next = new;
	}
}

void traverse(Node* node) {
	if (node == NULL) {
		printf("The Linked List is empty\n");
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
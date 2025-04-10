/*
Name:- Swapnaraj Mohanty
SIC :- 24BCSH93
Sec :- C2

Q. Write a menu-driven program ro perform the following operations on a Linked List.
	(i) Create a linked list
	(ii) Traverse a linked list
	(iii) Delete a node from the beginning of the linked list
	(iv) Delete a node from the end of the linked list
	(v) Delete a node from a given position in the linked list
	(vi) Delete a node after a specific node in the linked list
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} Node;

Node *start = NULL;

void create_list(Node*);
void delete_beg(Node*);
void delete_end(Node*);
void delete_at(Node*);
void delete_after(Node*);
void traverse(Node*);

int main() {
	Node *node = (Node*)malloc(sizeof(Node));
	int ch;
	start = node;
	
	if (node == NULL) {
		printf("Memory was not allocated\n");
		exit(0);
	}
	create_list(node);
	traverse(node);

	while (1) {
		printf("\n\tMenu-Driven program for insertion in linked list\n");
		printf("1. Delete a node from the beginning\n");
		printf("2. Delete a node from the end\n");
		printf("3. Delete a node from the given position\n");
		printf("4. Delete a node after a specific node\n");
		printf("5. Exit the program\n");
		printf("\nEnter your choice: ");
		scanf("%d", &ch);

		switch (ch) {
			case 1:
				delete_beg(node);
				node = start;
				traverse(node);
				break;

			case 2:
				delete_end(node);
				node = start;
				traverse(node);
				break;

			case 3:
				delete_at(node);
				node = start;
				traverse(node);
				break;

			case 4:
				delete_after(node);
				traverse(node);
				break;

			case 5:
				printf("\nThank You for using the program\n");
				return 0;

			default:
				printf("\nInvalid input. Try again...\n");
		}
	}
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

void delete_beg(Node* node) {
	if (node == NULL) {
		printf("Linked list is empty\n");
	} else {
		start = node->next;
		free(node);
	}
}

void delete_end(Node* node) {
	if (node == NULL) {
		printf("Linked list is empty\n");
	} else if (node->next == NULL) {
		free(node);
		start = NULL;
	} else {
		Node *prev;

		while (node->next != NULL) {
			prev = node;
			node = node->next;
		}
		prev->next = NULL;
		free(node);
	}
}

void delete_at(Node *node) {
	int idx, pos = 1;
	printf("\nEnter the position to delete the element: ");
	scanf("%d", &idx);

	if (node == NULL || idx < 1) {
		printf("Invalid postion\n");
		return;
	}
	if (idx == 1) {
		start = node->next;
		free(node);
		return;
	}

	while (node->next != NULL && pos != idx - 1) {
		node = node->next;
		pos++;
	}

	if (node->next == NULL) {
		printf("Invalid postion\n");
	} else {
		Node *prev = node;
		node = node->next;
		prev->next = node->next;
		free(node);
	}
}

void delete_after(Node* node) {
	int element;
	printf("\nEnter the after which element to insert: ");
	scanf("%d", &element);

	while (node != NULL && node->data != element) {
		node = node->next;
	}

	if (node == NULL) {
		printf("Element %d is not found\n", element);
	} else if (node ->next == NULL) {
		printf("No element to delete\n");
		return;
	} else {
		Node *prev = node;
		node = node->next;
		prev->next = node->next;
		free(node);
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

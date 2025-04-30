/*
Name:- Swapnaraj Mohanty
SIC :- 24BCSH93
Sec :- C2

Q. Write a menu-driven program to perform the following operations on a Circular Linked List.
	(i) Create a Circular linked list
	(ii) Traverse the linked list
	(iii) Insert a node at the beginning
	(iv) Insert a node at the end
	(v) Insert a node after a given node
	(vi) Delete a node from the beginning
	(vii) Delete a node from the end
	(viii) Delete a node after a given node
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
void insert_after(Node*);
void delete_beg(Node*);
void delete_end(Node*);
void delete_after(Node*);
void traverse(Node*);

int main() {
	Node *node = (Node*)malloc(sizeof(Node));
	int ch;
	start = node;
	
	if (start == NULL) {
		printf("Memory was not allocated\n");
		exit(0);
	}
	create_list(node);
	traverse(node);

	while (1) {
		printf("\n\tMenu-Driven program for Circular Linked List\n");
		printf("1. Insert a node at the beginning\n");
		printf("2. Insert a node at the end\n");
		printf("3. Insert a node after a given node\n");
		printf("4. Delete a node from the beginning\n");
		printf("5. Delete a node from the end\n");
		printf("6. Delete a node after a given node\n");
		printf("7. Traverse the Linked List\n");
		printf("0. Exit the program\n");
		printf("\nEnter your choice: ");
		scanf("%d", &ch);

		switch (ch) {
			case 1:
				insert_beg(node);
				node = start;
				traverse(node);
				break;

			case 2:
				insert_end(node);
				node = start;
				traverse(node);
				break;

			case 3:
				insert_after(node);
				traverse(node);
				break;

			case 4:
				delete_beg(node);
				node = start;
				traverse(node);
				break;

			case 5:
				delete_end(node);
				node = start;
				traverse(node);
				break;

			case 6:
				delete_after(node);
				traverse(node);
				break;

			case 7:
				traverse(node);
				break;

			case 0:
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
				node->next = start;
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
	Node *new = (Node*)malloc(sizeof(Node));

	if (new == NULL) {
		printf("Memory was not allocated\n");
		exit(0);
	}
	printf("\nEnter the element to insert at the beginning: ");
	scanf("%d", &new->data);
	
	if (start == NULL) {
		start = new;
		new->next = start;
	} else {
		new->next = node;

		while (node->next != start) {
			node = node->next;
		}
		node->next = new;
		start = new;
	}
}

void insert_end(Node* node) {
	if (node == NULL) {
		node = (Node*)malloc(sizeof(Node));
		start = node;
		node->next = start;
	} else {
		while (node->next != start) {
			node = node->next;
		}
		node->next = (Node*)malloc(sizeof(Node));
		node = node->next;
	}
	if (node == NULL) {
		printf("Memory was not allocated\n");
		exit(0);
	}
	printf("\nEnter the element to insert at the end: ");
	scanf("%d", &node->data);
	node->next = start;
}

void insert_after(Node* node) {
	int element;
	printf("\nEnter the after which element to insert: ");
	scanf("%d", &element);

	if (node == NULL) {
		printf("Linked List is empty\n");
		return;
	}
	do {
		if (node->data == element) {
			break;
		}
		node = node->next;
	} while (node != start);

	if (node == start) {
		printf("Element %d is not found\n", element);
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

void delete_beg(Node* node) {
	if (node == NULL) {
		printf("Linked list is empty\n");
	} else if (node->next == start) {
		free(start);
		start = NULL;
	} else {
		while (node->next != start) {
			node = node->next;
		}
		Node *temp = start;
		start = start->next;
		free(temp);
		node->next = start;
	}
}

void delete_end(Node* node) {
	if (node == NULL) {
		printf("Linked list is empty\n");
	} else if (node->next == start) {
		free(node);
		start = NULL;
	} else {
		Node *prev;

		while (node->next != start) {
			prev = node;
			node = node->next;
		}
		prev->next = start;
		free(node);
	}
}

void delete_after(Node* node) {
	int element;
	printf("\nEnter the after which element to delete: ");
	scanf("%d", &element);

	if (node == NULL) {
		printf("Linked List is empty\n");
		return;
	}
	do {
		if (node->data == element) {
			break;
		}
		node = node->next;
	} while (node != start);

	if (node == start) {
		printf("Element %d is not found\n", element);
	} else if (node->next == start) {
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
		do {
			printf("%d ", node->data);
			node = node->next;
			len++;
		} while (node != start);
		printf("\nTotal length of the Linked List is %d\n", len);
	}
}
/*
Name:- Swapnaraj Mohanty
SIC :- 24BCSH93
Sec :- C2

Q. Write a menu-driven program ro perform the following operations on a Linked List.
	(i) Create a linked list
	(ii) Traverse a linked list
	(iii) Insert a node at the beginning of the linked list
	(iv) Insert a node at the end of the linked list
	(v) Insert a node at a given position in the linked list
	(vi) Insert a node after a specific node in the linked list
	(vii) Delete a node from the beginning of the linked list
	(viii) Delete a node from the end of the linked list
	(ix) Delete a node from a given position in the linked list
	(x) Delete a node after a specific node in the linked list
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
void delete_beg(Node*);
void delete_end(Node*);
void delete_at(Node*);
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
		printf("\n\tMenu-Driven program for insertion & deletion in linked list\n");
		printf("1. Insert a node at the beginning\n");
		printf("2. Insert a node at the end\n");
		printf("3. Insert a node at the given position\n");
		printf("4. Insert a node after a specific node\n");
		printf("5. Delete a node from the beginning\n");
		printf("6. Delete a node from the end\n");
		printf("7. Delete a node from the given position\n");
		printf("8. Delete a node after a specific node\n");
		printf("9. Traverse the Linked List\n");
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
				insert_at(node);
				node = start;
				traverse(node);
				break;

			case 4:
				insert_after(node);
				traverse(node);
				break;

			case 5:
				delete_beg(node);
				node = start;
				traverse(node);
				break;

			case 6:
				delete_end(node);
				node = start;
				traverse(node);
				break;

			case 7:
				delete_at(node);
				node = start;
				traverse(node);
				break;

			case 8:
				delete_after(node);
				traverse(node);
				break;

			case 9:
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
	if (node == NULL) {
		node = (Node*)malloc(sizeof(Node));
		start = node;
	} else {
		while (node->next != NULL) {
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
	node->next = NULL;
}

void insert_at(Node *node) {
	int len = 0, idx, i;

	while (node != NULL) {
		len++;
		node = node->next;
	}
	node = start;
	
	printf("\nEnter the position to insert the element: ");
	scanf("%d", &idx);

	if (idx < 1 || idx > len) {
		printf("Invalid position\n");
	} else if (idx == 1) {
		start = (Node*)malloc(sizeof(Node));

		if (start == NULL) {
			printf("Memory was not allocated\n");
		    exit(0);
		}
	    printf("\nEnter the element to insert: ");
		scanf("%d", &start->data);
        start->next = node;
	} else {
		for (i = 1; i < idx - 1; i++) {
			node = node->next;
		}
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

void insert_after(Node* node) {
	int element;
	printf("\nEnter the after which element to insert: ");
	scanf("%d", &element);

	while (node != NULL && node->data != element) {
		node = node->next;
	}
	if (node == NULL) {
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
	int len = 0, idx, i;

	while (node != NULL) {
		len++;
		node = node->next;
	}
	node = start;
	printf("\nEnter the position to delete the element: ");
	scanf("%d", &idx);

	if (idx < 1 || idx > len) {
		printf("Invalid position\n");
	} else if (idx == 1) {
		start = start->next;
		free(node);
    } else {
		for (i = 1; i < idx - 1; i++) {
			node = node->next;
		}
		Node *temp = node->next;
		node->next = temp->next;
		free(temp);
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
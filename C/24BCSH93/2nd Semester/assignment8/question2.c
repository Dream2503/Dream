/*
Name:- Swapnaraj Mohanty
SIC :- 24BCSH93
Sec :- C2

Q. Write a program to sort the nodes of a single linked list in ascending order by using bubble sort algorithm.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} Node;

Node *start = NULL;

void create_list(Node*);
void sort(Node*);
void traverse(Node*);

int main() {
	Node *node = (Node*)malloc(sizeof(Node));
	start = node;

	if (node == NULL) {
		printf("Memory was not allocated\n");
		exit(0);
	}
	create_list(node);
	sort(node);
	node = start;
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

void sort(Node *node) {
	int n = 0, i, j, temp;

	if (node == NULL) {
		return;
	}
	while (node) {
		n++;
		node = node->next;
	}
	for (i = 0; i < n - 1; i++) {
		node = start;

		for (j = 0; j < n - i - 1; j++) {
			if (node->data > node->next->data) {
				temp = node->data;
				node->data = node->next->data;
				node->next->data = temp;
			}
			node = node->next;
		}
	}

	/*	Bubble sort for array
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				swap(array[j], array[j + 1]);
			}
		}
	}
	*/
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
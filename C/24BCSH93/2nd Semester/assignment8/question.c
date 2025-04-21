/*
Name:- Swapnaraj Mohanty
SIC :- 24BCSH93
Sec :- C2

Q. Implement a stack using Linked List
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} Node;

Node *start = NULL, *end = NULL;

void push(int);
int pop();
void traverse();

int main() {
	int ch, element;

	while (1) {
		printf("\n\t\tMenu-Driven program for stack\n");
		printf("1. Push an element to the stack\n");
		printf("2. Pop an element from the stack\n");
		printf("3. Display stack\n");
		printf("4. To exit the program\n\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);
		printf("\n");

		switch (ch) {
			case 1:
				printf("Enter the element to push: ");
				scanf("%d", &element);
				push(element);
				break;

			case 2:
				element = pop();

				if (element != -1) {
					printf("Popped element %d from the stack\n", element);
				}
				break;

			case 3:
				traverse();
				break;

			case 4:
				printf("Thank you for using the program\n");
				return 0;

			default:
				printf("Invalid choice. Try again\n");
		}
	}
}

void push(int element) {
	if (start == NULL) {
		end = (Node*)malloc(sizeof(Node));
		start = end;
	} else {
		end->next = (Node*)malloc(sizeof(Node));
		end = end->next;
	}
		
	if (end == NULL) {
		printf("Memory was not allocated\n");
		exit(0);
	}
	end->data = element;
	end->next = NULL;
}

int pop() {
	if (start == NULL) {
		printf("Stack Underflow\n");
		return -1;
	}
	Node *node = start;
	int res;

	while (node->next != end) {
		node = node->next;
	}
	res = end->data;
	free(end);
	end = node;
}

void traverse() {
	if (start == NULL) {
		printf("The Stack is empty\n");
	} else {
		Node *node = start;
		printf("The elements in the Stack are: ");

		while (node) {
			printf("%d ", node->data);
			node = node->next;
		}
		printf("\n");
	}
}

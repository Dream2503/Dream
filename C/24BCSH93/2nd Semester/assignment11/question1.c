/*
Name:- Swapnaraj Mohanty
SIC :- 24BCSH93
Sec :- C2

Q. Write a program to implement a Stack by using Linked List. It should have the following operations (functions).
	(i) void push(int) to insert an element into the stack
	(ii) int pop() to remove an element from the top of the stack
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} Node;

Node *top = NULL;

void push(int);
int pop();
void traverse();

int main() {
	int ch, element;

	while (1) {
		printf("\n\t\tMenu-Driven program for Stack\n");
		printf("1. Push an element to the Stack\n");
		printf("2. Pop an element from the Stack\n");
		printf("3. Display Stack\n");
		printf("4. To exit the program\n");
		printf("\nEnter your choice: ");
		scanf("%d", &ch);
		printf("\n");

		switch (ch) {
			case 1:
				printf("Enter the element to push: ");
				scanf("%d", &element);
				push(element);
				traverse();
				break;

			case 2:
				element = pop();

				if (element != -1) {
					printf("Popped element %d from the Stack\n", element);
					traverse();
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
	Node *node = (Node*)malloc(sizeof(Node));
	
	if (!node) {
		printf("Memory was not allocated\n");
		exit(0);
	}
	node->data = element;
	node->next = top;
	top = node;
}

int pop() {
	if (!top) {
		printf("Stack Underflow\n");
		return -1;
	}
	Node *temp = top;
	int res = top->data;
	top = top->next;
	free(temp);
	return res;
}

void traverse() {
	if (!top) {
		printf("The Stack is empty\n");
	} else {
		Node *node = top;
		printf("The elements in the Stack are: ");

		while (node) {
			printf("%d ", node->data);
			node = node->next;
		}
		printf("\n");
	}
}
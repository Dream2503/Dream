/*
Name:- Swapnaraj Mohanty
SIC :- 24BCSH93
Sec :- C2

Q. Write a program to implement a stack by using array. It should have the following operations (functions).
	(i) void push(int) to insert an element into the stack
	(ii) int pop() to remove an element from the top of the stack
	(iii) bool isfull() to check the stack is full or not
	(iv) bool isempty() to check the stack is empty or not.
*/

#include <stdio.h>
#include <stdbool.h>
#define n 3

int stack[n], top = -1;

void push(int);
int pop();
bool is_full();
bool is_empty();
void display();

int main() {
	push(1);
	push(2);
	push(3);
	display();
	push(4);
	pop();
	display();
	pop();
	pop();
	display();
	pop();
	return 0;
}

void push(int element) {
	if (is_full()) {
		printf("Stack Overload\n");
	} else {
		stack[++top] = element;
	}
}

int pop() {
	if (is_empty()) {
		printf("Stack Underflow\n");
	} else {
		return stack[top--];
	}
}

bool is_full() {
	return top == n - 1;
}

bool is_empty() {
	return top == -1;
}

void display() {
	int i;

	if (is_empty()) {
		printf("No elements in the stack\n");
	} else {
		printf("Elements of the stack: ");

		for (i = 0; i <= top; i++) {
			printf("%d ", stack[i]);
		}
		printf("\n");
	}
}
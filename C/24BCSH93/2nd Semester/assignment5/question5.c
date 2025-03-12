/*
Name:- Swapnaraj Mohanty
SIC :- 24BCSH93
Sec :- C2

Q. Write a function to reverse a string by using stack. Test in main().
*/

#include <stdio.h>
#include <stdbool.h>
#define n 30

char stack[n];
int top = -1;

void push(char);
char pop();
bool is_full();
bool is_empty();
void reverse(char[], char[]);

int main() {
	char string[n], reversed[n];
	printf("Enter a string: ");
	scanf("%s", string);
	reverse(string, reversed);
	printf("Reversed string is %s\n", reversed);
	return 0;
}

void push(char element) {
	if (is_full()) {
		printf("Stack Overload\n");
	} else {
		stack[++top] = element;
	}
}

char pop() {
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

void reverse(char string[], char reversed[]) {
	int i = 0;

	while (string[i] != '\0') {
		push(string[i]);
		i++;
	}
	i = 0;

	while (!is_empty()) {
		reversed[i] = pop();
		i++;
	}
	reversed[i] = '\0';
}
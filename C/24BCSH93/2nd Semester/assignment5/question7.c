/*
Name:- Swapnaraj Mohanty
SIC :- 24BCSH93
Sec :- C2

Q. Write a function to check the validity of an expression containing nested brackets by using stack. Assume the different Test in main().
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
bool is_pair(char, char);
bool validate_braces(char[]);

int main() {
	char expression[n];
	printf("Enter an expression: ");
	scanf("%s", expression);
	
	if (validate_braces(expression)) {
		printf("The expression is valid\n");
	} else {
		printf("The expression is not valid\n");
	}
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

bool is_pair(char ch1, char ch2) {
	if (ch1 == '(' && ch2 == ')') {
		return 1;
	} else if (ch1 == '{' && ch2 == '}') {
		return 1;
	} else if (ch1 == '[' && ch2 == ']') {
		return 1;
	} else {
		return 0;
	}
}

bool validate_braces(char expression[]) {
	int i = 0;
	char ch;

	while (expression[i] != '\0') {
		ch = expression[i];
		if (ch == '(' || ch == '{' || ch == '[') {
			push(ch);
		} else if (ch == ')' || ch == '}' || ch == ']') {
			if (is_empty()) {
				return 0;
			} else if (!is_pair(pop(), ch)) {
				return 0;
			}
		}
		i++;
	}
	return is_empty();
}
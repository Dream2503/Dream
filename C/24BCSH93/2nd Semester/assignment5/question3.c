/*
Name:- Swapnaraj Mohanty
SIC :- 24BCSH93
Sec :- C2

Q. Write a function to evaluate a postfix expression by using stack. Call it in main() to verify whether it is working correctly or not for the following expression.
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#define n 10

int stack[n], top = -1;

void push(int);
int pop();
bool is_full();
bool is_empty();
int postfix_evaluation(char[]);

int main() {
	char expression[20];
	printf("Enter a postfix expression to evaluate: ");
	scanf("%s", expression);
	printf("Result is %d\n", postfix_evaluation(expression));
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

int postfix_evaluation(char expression[]) {
	int i = 0, element1, element2, res;
	char ch;

	while (expression[i] != '\0') {
		ch = expression[i];

		if (isdigit(ch)) {
			element1 = ch - '0';
			push(element1);
		} else {
			element2 = pop();
			element1 = pop();
			
			if (ch == '+') {
				res = element1 + element2;
			} else if (ch == '-') {
				res = element1 - element2;
			} else if (ch == '*') {
				res = element1 * element2;
			} else if (ch == '/') {
				res = element1 / element2;
			} else if (ch == '^') {
				res = pow(element1, element2);
			}
			push(res);
		}
		i++;
	}
	return pop();
}
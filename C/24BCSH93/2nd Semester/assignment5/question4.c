/*
Name:- Swapnaraj Mohanty
SIC :- 24BCSH93
Sec :- C2

Q. Write a function to convert infix expression to postfix expression by using stack. Call it in main() to verify
whether it is working correctly or not for the following expression.
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#define n 10

char stack[n];
int top = -1;

void push(char);
char pop();
bool is_full();
bool is_empty();
int precedence(char);
void infix_to_postfix(char[], char[]);

int main() {
    char infix[30], postfix[30];
    printf("Enter a infix expression to convert into postfix: ");
    scanf("%s", infix);

    infix_to_postfix(infix, postfix);
    printf("Postfix expression is %s\n", postfix);
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

bool is_full() { return top == n - 1; }
bool is_empty() { return top == -1; }

int precedence(char ch) {
    if (ch == '(') {
        return 0;
    } else if (ch == '+' || ch == '-') {
        return 1;
    } else if (ch == '*' || ch == '/') {
        return 2;
    } else if (ch == '^') {
        return 3;
    } else {
        return 4;
    }
}

void infix_to_postfix(char infix[], char postfix[]) {
    int i = 0, k = 0;
    char ch, str;

    while (infix[i] != '\0') {
        ch = infix[i];

        if (isalpha(ch)) {
            postfix[k++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            str = pop();

            while (str != '(') {
                postfix[k++] = str;
                str = pop();
            }
        } else {
            while (!is_empty() && precedence(ch) <= precedence(stack[top])) {
                postfix[k++] = pop();
            }
            push(ch);
        }
        i++;
    }
    while (is_empty() == 0) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
}

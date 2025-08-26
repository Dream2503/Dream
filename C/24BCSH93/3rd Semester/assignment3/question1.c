//  Q1. Implementation of conversion from infix expression to postfix expression.

#include <stdio.h>
#define n 10

char stack[n];
int top = -1;

void push(char);
char pop();
int precedence(char);
void infix_to_postfix(char[], char[]);

int main() {
    char infix[30], postfix[30];
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    infix_to_postfix(infix, postfix);
    printf("The equivalent postfix expression is %s\n", postfix);
    return 0;
}

void push(char ch) {
    if (top == n) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = ch;
    }
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int precedence(char ch) {
    switch (ch) {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;

    default:
        printf("Invalid symbol to return precedence");
        return -1;
    }
}

void infix_to_postfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char ch;
    push('(');

    while (infix[i]) {
        switch (infix[i]) {
        case '(':
            push(infix[i]);
            break;

        case ')':
            ch = pop();

            while (ch != '(') {
                postfix[j++] = ch;
                ch = pop();
            }
            break;

        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while (stack[top] != '(' && precedence(infix[i]) <= precedence(stack[top])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
            break;

        default:
            postfix[j++] = infix[i];
        }
        i++;
    }
    while (stack[top] != '(') {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

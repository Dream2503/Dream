//  Q2. Implementation of evaluation of postfix expression.

#include <math.h>
#include <stdio.h>
#define n 10

int stack[n];
int top = -1;

void push(int);
int pop();
int postfix_evaluation(char[]);

int main() {
    char postfix[30];
    printf("Enter the postfix expression: ");
    scanf("%s", postfix);
    printf("The evaluated postfix expression is %d\n", postfix_evaluation(postfix));
    return 0;
}

void push(int ch) {
    if (top == n) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = ch;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int postfix_evaluation(char postfix[]) {
    int i = 0, element1, element2;

    while (postfix[i]) {
        if (postfix[i] >= '0' && postfix[i] <= '9') {
            push(postfix[i] - '0');
        } else {
            element2 = pop();
            element1 = pop();

            switch (postfix[i]) {
            case '+':
                push(element1 + element2);
                break;

            case '-':
                push(element1 - element2);
                break;

            case '*':
                push(element1 * element2);
                break;

            case '/':
                push(element1 / element2);
                break;

            case '^':
                push(pow(element1, element2));
                break;

            default:
                printf("Invalid operator\n");
                return -1;
            }
        }
        i++;
    }
    return pop();
}

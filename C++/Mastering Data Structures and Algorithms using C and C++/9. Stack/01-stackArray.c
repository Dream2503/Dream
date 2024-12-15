#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Stack {int size, top, *array;} Stack;

Stack *create(int size) {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->size = size;
    stack->top = -1;
    stack->array = (int*)malloc(size*sizeof(int));
}
bool isFull(Stack *stack) {return (stack->top == stack->size - 1);}
void push(Stack *stack, int value) {
    if (isFull(stack)) printf("Stack Overflow\n");
    else stack->array[++stack->top] = value;
}
bool isEmpty(Stack *stack) {return (stack->top == -1);}
void display(Stack *stack) {
    if (isEmpty(stack)) printf("Stack is empty\n");
    else for (int i = 0; i <= stack->top; i++) printf("%d ", stack->array[i]);
}
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->array[stack->top--];
}
int peek(Stack *stack, int pos) {
    int index = stack->top - pos;

    if (index < 0 || index >= stack->size) {
        printf("Index out of range");
        return -1;
    }
    return stack->array[index];
}
int stackTop(Stack *stack) {
    if (isEmpty(stack)) return -1;
    return stack->array[stack->top];
}
bool isParenthesisBalanced(Stack *stack, char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] == '(') push(stack, str[i]);
        else if (str[i] == ')') {
            if (isEmpty(stack)) return false;
            pop(stack);
        } 
    }
    return isEmpty(stack);
}
bool isOpr(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/') return true;
    return false;
}
int pres(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    return 0;
}
char *infixToPostfix(Stack *stack, char *infix) {
    char *postfix = (char*)malloc(strlen(infix)*sizeof(char));
    int i = 0, j = 0;

    while (infix[i]) {
        if (isOpr(infix[i])) {
            if (pres(infix[i]) > pres(stackTop(stack))) push(stack, infix[i++]);
            else postfix[j++] = pop(stack);
        } else postfix[j++] = infix[i++];
    }
    while (!isEmpty(stack)) postfix[j++] = pop(stack);
    postfix[j] = '\0';
    return postfix;
}
int evalPostfix(Stack *stack, char *str) {
    int x1, x2, res;
    for (int i = 0; str[i]; i++) {
        if (isOpr(str[i])) {
            x2 = pop(stack), x1 = pop(stack);

            switch (str[i]) {
                case '+':
                    res = x1 + x2;
                    break;
                case '-':
                    res = x1 - x2;
                    break;
                case '*':
                    res = x1 * x2;
                    break;
                case '/':
                    res = x1 / x2;
                    break;
                default:
                    break;
            }
            push(stack, res);
        } else push(stack, str[i] - '0');
    }
    return pop(stack);
}

int main() {
    char str[] = "3*5+6/2-4";
    Stack *stack = create(strlen(str));
    char *s = infixToPostfix(stack, str);
    display(stack);
    printf("%d", evalPostfix(stack, s));
    return 0;
}

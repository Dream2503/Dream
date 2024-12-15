#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;
typedef struct Stack {Node *top;} Stack;

Stack *create() {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
}
void push(Stack *stack, int value) {
    Node *new = (Node*)malloc(sizeof(Node));
    new->data = value;
    new->next = stack->top;
    stack->top = new;
}
bool isEmpty(Stack *stack) {return stack->top == NULL;}
void display(Stack *stack) {
    if (isEmpty(stack)) printf("Stack is empty\n");
    else {
        Node *current = stack->top;

        while (current) {
            printf("%d ", current->data);
            current = current->next;
        }
    }
}
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    Node *temp = stack->top;
    int value = temp->data;
    stack->top = temp->next;
    free(temp);
    return value;
}
int peek(Stack *stack, int pos) {
    if (pos < 0) {
        printf("Index out of range");
        return -1;
    }
    Node *current = stack->top;
    
    for (int i = 0; i < pos && current; i++) {current = current->next;}
    if (current) return current->data;
    else {
        printf("Index out of range");
        return -1;
    } 
}
int stackTop(Stack *stack) {
    if (isEmpty(stack)) return -1;
    return stack->top->data;
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
bool isOpr(char ch) {return (ch == '+' || ch == '-' || ch == '*' || ch == '/');}
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
    char str[] = "a+b/c-d";
    Stack *stack = create();
    printf("%s", infixToPostfix(stack, str));
    return 0;
}
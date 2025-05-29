/*
Name:- Swapnaraj Mohanty
SIC :- 24BCSH93
Sec :- C2

Q. Write a function to convert postfix expression to infix expression by using stack. Call it in main() to verify
whether it is working correctly or not for the following expression.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define n 10

char *stack[n];
int top = -1;

void push(char *);
char *pop();
bool is_full();
bool is_empty();
char *postfix_to_infix(char[]);

int main() {
    char *infix, postfix[30];
    printf("Enter a postfix expression to convert into infix: ");
    scanf("%s", postfix);

    infix = postfix_to_infix(postfix);
    printf("Infix expression is %s\n", infix);
    free(--infix);
    return 0;
}

void push(char *element) {
    if (is_full()) {
        printf("Stack Overload\n");
    } else {
        stack[++top] = element;
    }
}

char *pop() {
    if (is_empty()) {
        printf("Stack Underflow\n");
    } else {
        return stack[top--];
    }
}
bool is_full() { return top == n - 1; }
bool is_empty() { return top == -1; }

char *postfix_to_infix(char infix[]) {
    int i = 0, j, k;
    char *str, *str1, *str2;

    while (infix[i] != '\0') {
        if (isalpha(infix[i])) {
            str = (char *) malloc(2 * sizeof(char));
            str[0] = infix[i];
            str[1] = '\0';
            push(str);
        } else {
            str2 = pop();
            str1 = pop();
            str = (char *) malloc(n * sizeof(char));

            j = k = 0;
            str[k++] = '(';

            while (str1[j] != '\0') {
                str[k++] = str1[j++];
            }
            str[k++] = infix[i];
            j = 0;

            while (str2[j] != '\0') {
                str[k++] = str2[j++];
            }
            str[k++] = ')';

            str[k] = '\0';
            free(str1);
            free(str2);
            push(str);
        }
        i++;
    }
    if (!is_empty()) {
        str = pop();
        str++;
        i = 0;

        while (str[i] != '\0') {
            i++;
        }
        str[--i] = '\0';
        return str;
    } else {
        printf("Invalid postix expression\n");
    }
}

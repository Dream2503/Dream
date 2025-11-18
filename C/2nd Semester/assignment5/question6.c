/*
Name:- Swapnaraj Mohanty
SIC :- 24BCSH93
Sec :- C2

Q. Write a function to convert a decimal number to binary number by using stack. Test in main().
*/

#include <stdbool.h>
#include <stdio.h>
#define n 30

int stack[n], top = -1;

void push(int);
int pop();
bool is_full();
bool is_empty();
void decimal_to_binary(int, char[]);

int main() {
    int num;
    char res[n];
    printf("Enter a number: ");
    scanf("%d", &num);
    decimal_to_binary(num, res);
    printf("The binary equivalent is %s\n", res);
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

bool is_full() { return top == n - 1; }
bool is_empty() { return top == -1; }

void decimal_to_binary(int num, char res[]) {
    int i = 0;

    while (num != 0) {
        push(num % 2);
        num /= 2;
    }
    while (!is_empty()) {
        res[i++] = (char) (pop() + '0');
    }
    res[i] = '\0';
}

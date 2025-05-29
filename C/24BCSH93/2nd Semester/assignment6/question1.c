/*
Name:- Swapnaraj Mohanty
SIC :- 24BCSH93
Sec :- C2

Q. Write a program to implement a Queue by using array, It should have the following operations(functions):
    (i) void insert(int) to insert an element into the Queue.
    (ii) int delete() to remove an element from the Queue.
    (iii) bool isFull() to check the Queue is full or not.
    (iv) bool isEmpty() to check the Queue is empty or not.
    (v) void display() to display the elements of the Queue.
*/

#include <stdbool.h>
#include <stdio.h>
#define n 3

int queue[n], rear = -1, front = 0;

void insert(int);
int delete();
bool is_full();
bool is_empty();
void display();

int main() {
    insert(10);
    insert(20);
    display();
    insert(30);
    insert(40);
    display();
    delete ();
    delete ();
    display();
    delete ();
    delete ();
    display();
    return 0;
}

void insert(int element) {
    if (is_full()) {
        printf("The Queue is full\n");
    } else {
        queue[++rear] = element;
    }
}

int delete() {
    if (is_empty()) {
        printf("The Queue is empty\n");
    } else {
        return queue[front++];
    }
}

bool is_full() { return rear == n - 1; }
bool is_empty() { return rear == front - 1; }

void display() {
    if (is_empty()) {
        printf("The Queue is empty\n");
    } else {
        int i;

        printf("the Queue elements are: ");
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

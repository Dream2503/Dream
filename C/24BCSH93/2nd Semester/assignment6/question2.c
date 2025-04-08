/*
Name:- Swapnaraj Mohanty
SIC :- 24BCSH93
Sec :- C2

Q. Write a program to implement a Circular Queue by using array, It should have the same operations(functions) defined in Question 1
*/

#include <stdio.h>
#include <stdbool.h>
#define n 5

int circular_queue[n], rear = 0, front = 0;

void insert(int);
int delete();
bool is_full();
bool is_empty();
void display();

int main() {
	insert(10);
	insert(20);
	insert(30);
	insert(40);

	display();

	delete();
	insert(50);
	delete();
	display();

	insert(60);
	delete();
	delete();
	display();
	return 0;
}

void insert(int element) {
	if (rear == n - 1) {
		rear = 0;
	} else {
		rear++;
	}
	if (is_full()) {
		printf("The Queue is full\n");

		if (rear == 0) {
			rear = n - 1;
		} else {
			rear--;
		}
	} else {
		circular_queue[rear] = element;
	}
}

int delete() {
	if (is_empty()) {
		printf("The Queue is empty\n");
	} else {
		if (front == n - 1) {
			front = 0;
		} else {
			front++;
		}
	}
	return circular_queue[front];
}

bool is_full() {
	if (front == rear) {
		return 1;
	} else {
		return 0;
	}
}

bool is_empty() {
	if (rear == front) {
		return 1;
	} else {
		return 0;
	}
}

void display() {
	if (is_empty()) {
		printf("The Queue is empty\n");
	} else {
		int i;

		if (front == n - 1) {
			i = 0;
		} else {
			i = front + 1;
		}
		printf("The Queue elements are: ");
		
		while (i != rear) {
			printf("%d ", circular_queue[i]);

			if (i == n - 1) {
				i = 0;
			} else {
				i++;
			}
		}
		printf("%d\n", circular_queue[rear]);
	}
}
/*
Name:- Swapnaraj Mohanty
SIC :- 24BBCSH93
Sec :- C2

Q. Write a program to implement a Input-Restricted Deque(Double-ended queue) by using array. It should have the following operations (funcitons).
	(i) void insertLeft(int) to insert an element to the Left end of the Queue.
	(ii) int deleteLeft() to remove an element from Left end of the Queue.
	(iii) int deleteRight() to remove an element from Right end of the Queue.
	(iv) bool isFull() to check the Queue is full or not.
	(v) bool isEmpty() to check the Queue is empty or not.
	(vi) void display() to display the elements of the Queue.
*/

#include <stdio.h>
#include <stdbool.h>
#define n 5

int deque[n], left = -1, right = -1;

void insert_left(int);
int delete_left();
int delete_right();
bool is_full();
bool is_empty();
void display();

int main() {
	insert_left(10);
	insert_left(20);
	display();

	insert_left(30);
	insert_left(40);
	insert_left(50);
	display();

	insert_left(60);
	delete_right();
	delete_right();
	delete_left();
	display();

	delete_left();
	delete_right();
	display();
	delete_left();
	return 0;
}

void insert_left(int element) {
	if (is_full()) {
		printf("The Deque is full\n");
		return;
	}
	if (left == -1) {
		left = right = 0;
	} else if (left == 0) {
		left = n - 1;
	} else {
		left--;
	}
	deque[left] = element;
}

int delete_left() {
	if (is_empty()) {
		printf("The Deque is empty\n");
		return -1;
	}
	int res = deque[left];

	if (left == right) {
		left = right = -1;
	} else if (left == n - 1) {
		left = 0;
	} else {
		left++;
	}
	return res;
}

int delete_right() {
	if (is_empty()) {
		printf("The Deque is empty\n");
		return -1;
	}
	int res = deque[right];

	if (right == left) {
		right = left = -1;
	} else if (right == 0) {
		right = n - 1;
	} else {
		right--;
	}
	return res;
}

bool is_full() {
	if (left == 0 && right == n - 1 || left == right + 1) {
		return 1;
	} else {
		return 0;
	}
}

bool is_empty() {
	if (left == -1 && right == -1) {
		return 1;
	} else {
		return 0;
	}
}

void display() {
	if (is_empty()) {
		printf("The Deque is empty\n");
	} else {
		int i = left;
		printf("The Deque elements are: ");
		
		while (i != right) {
			printf("%d ", deque[i]);

			if (i == n - 1) {
				i = 0;
			} else {
				i++;
			}
		}
		printf("%d\n", deque[right]);
	}
}
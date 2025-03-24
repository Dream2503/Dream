/*
Name:- Swapnaraj Mohanty
SIC :- 24BBCSH93
Sec :- C2

Q. Write a menu-driven program by using the function defined in Q2 to perform repeated opeartion on the Queue and display the status of the Queue after every operation until the user enters his choice to exit
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
	int ch, element;
	
	while (1) {
		printf("\n\t\tMenu-Driven program for Circular Queue\n");
		printf("1. Insert an element\n");
		printf("2. Delete an element\n");
		printf("3. Display the queue\n");
		printf("4. To exit the program\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);

		switch (ch) {
			case 1:
				printf("\nEnter an element to insert in the queue: ");
				scanf("%d", &element);
				insert(element);
				display();
				break;

			case 2:
				if (is_empty()) {
					printf("\nThe queue is empty\n");
				} else {
					printf("\n%d was delete from the queue\n", delete());
					display();
				}
				break;

			case 3:
				display();
				break;

			case 4:
				printf("Thank you for using the program\n");
				return 0;

			default:
				printf("Invalid input. Try again...\n");
		}

	}
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
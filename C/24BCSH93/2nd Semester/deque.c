#include <stdio.h>
#include <stdbool.h>
#define n 10

int deque[n], right = -1, left = -1;

void insert_left(int);
void insert_right(int);
int delete_left();
int delete_right();
bool is_full();
bool is_empty();
void display();

int main() {
    printf("Inserting elements from right:\n");
    insert_right(10);
    insert_right(20);
    insert_right(30);
    display();

    printf("\nInserting elements from left:\n");
    insert_left(40);
    insert_left(50);
    display();

    printf("\nDeleting from left: %d\n", delete_left());
    display();

    printf("\nDeleting from right: %d\n", delete_right());
    display();

    printf("\nInserting at right:\n");
    insert_right(60);
    insert_right(70);
    display();

    printf("\nInserting at left:\n");
    insert_left(80);
    insert_left(90);
    display();
    
    return 0;
}

void insert_left(int element) {
    if (is_full()) {
        printf("The deque is full\n");
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

void insert_right(int element) {
    if (is_full()) {
        printf("The deque is full\n");
        return;
    }
    if (right == -1) {
        left = right = 0;
    } else if (right == n - 1) {
        right = 0;
    } else {
        right++;
    }
    deque[right] = element;
}

int delete_left() {
    if (is_empty()) {
        printf("The deque is empty\n");
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
        printf("The deque is empty\n");
        return -1;
    }
    int res = deque[right];

    if (right == left) {
        left = right = -1;
    } else if (right == 0) {
        right = n - 1;
    } else {
        right--;
    }
    return res;
}

bool is_full() {
    if (left == right + 1 || (left == 0 && right == n - 1)) {
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
        printf("The deque is empty\n");
    } else {
        printf("The deque elements are: ");

        if (left == right) {
            printf("%d ", deque[left]);
        } else {
            int i = left;

            while (i != right) {
                printf("%d ", deque[i]);

                if (i == n - 1) {
                    i = 0;
                } else {
                    i++;
                }
            }
            printf("%d ", deque[right]);
        }
    }
}
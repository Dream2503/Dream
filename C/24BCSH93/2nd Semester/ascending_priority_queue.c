#include <stdbool.h>
#include <stdio.h>
#define n 10

typedef struct {
    int value, priority;
} p_type;

int end = -1;
p_type apq[n];

void insert(int, int);
int min_delete();
bool is_full();
bool is_empty();
void display();

int main() {
    insert(10, 2);
    insert(20, 5);
    insert(30, 1);
    insert(40, 4);
    insert(50, 3);
    printf("After inserting elements:\n");
    display();
    printf("Deleted element: %d\n", min_delete());
    printf("Deleted element: %d\n", min_delete());
    printf("After deletion:\n");
    display();

    return 0;
}

void insert(int value, int priority) {
    if (is_full()) {
        printf("The priority queue is full\n");
    } else {
        p_type element = {value, priority};
        int i = end;

        while (i >= 0 && apq[i].priority < element.priority) {
            apq[i + 1] = apq[i];
            i--;
        }
        apq[i + 1] = element;
        end++;
    }
}

int min_delete() {
    if (is_empty()) {
        printf("The priority queue is empty\n");
        return -1;
    } else {
        return apq[end--].value;
    }
}

bool is_full() { return end == n - 1; }
bool is_empty() { return end == -1; }

void display() {
    if (is_empty()) {
        printf("The priority queue is empty\n");
    } else {
        int i;

        printf("The priority queue elements are: ");
        for (i = end; i >= 0; i--) {
            printf("%d ", apq[i].value);
        }
        printf("\n");
    }
}

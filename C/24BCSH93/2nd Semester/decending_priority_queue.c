#include <stdio.h>
#include <stdbool.h>
#define n 10

typedef struct {
    int value, priority;
} p_type;

int end = -1;
p_type dpq[n];

void insert(int, int);
int max_delete();
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

    printf("Deleted element: %d\n", max_delete());
    printf("Deleted element: %d\n", max_delete());

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
        
        while (i >= 0 && dpq[i].priority > element.priority) {
            dpq[i + 1] = dpq[i];
            i--; 
        }
        dpq[i + 1] = element;
        end++;
    }
}

int max_delete() {
    if (is_empty()) {
        printf("The priority queue is empty\n");
        return -1;
    } else {
        return dpq[end--].value;
    }
}

bool is_full() {
    if (end == n - 1) {
        return 1;
    } else {
        return 0;
    }
}

bool is_empty() {
    if (end == -1) {
        return 1;
    } else {
        return 0;
    }
}

void display() {
    if (is_empty()) {
        printf("The priority queue is empty\n");
    } else {
        int i;

        printf("The priority queue elements are: ");
        for (i = end; i >= 0; i--) {
            printf("%d ", dpq[i].value);
        }
        printf("\n");
    }
}

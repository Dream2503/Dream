#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *create(int *array, int size) {
    Node *temp, *last, *head;
    head = (Node*)malloc(sizeof(Node));
    head->data = array[0];
    head->next = NULL;
    last = head;

    for(int i = 1; i < size; i++) {
        temp = (Node*)malloc(sizeof(Node));
        temp->data = array[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
    return head;
}
void Display(Node *list) {
    while (list) {
        printf("%d ", list->data);
        list = list->next;
    }
}
int count (Node *list) {
    int cnt = 0;

    while (list) {
        cnt++;
        list = list->next;
    }
    return cnt;
}
int sum(Node *list) {
    int sum = 0;

    while (list) {
        sum += list->data;
        list = list->next;
    }
    return sum;
}
int max(Node *list) {
    int max = list->data;
    list = list->next;

    while (list) {
        if (list->data > max) max = list->data;
        list = list->next;
    }
    return max;
}
Node *search(Node *list, int value) {
    while (list) {
        if (list->data == value) return list;
        list = list->next;
    }
    return NULL;
}
void insert(Node **list, int index, int value) {
    if (index < 0) {
        printf("Index out of range");
        exit(0);
    }
    Node *ref = *list, *temp = (Node*)malloc(sizeof(Node));
    temp->data = value;

    if (index == 0) {
        temp->next = *list;
        *list = temp;
    }
    for (int i = 1; i < index && ref; i++) ref = ref->next;
    if (!ref) {
        printf("Index out of range");
        exit(0);
    }
    temp->next = ref->next;
    ref->next = temp;
}
void sortedInsert(Node **list, int value) {
    Node *head = *list, *tail, *temp = (Node*)malloc(sizeof(Node));
    temp->data = value;

    if (!*list) (*list) = temp;
    else {
        while (head && head->data < value) {
            tail = head;
            head = head->next;
        }
        if (head == *list) {
            temp->next = *list;
            *list = temp;
        } else {
            tail->next = temp;
            temp->next = head;
        }
    }
}
int delete(Node **list, int index) {
    Node *temp = *list;
    int value, cnt = 0;

    if (index < 0) {
        printf("Index out of range");
        exit(0);
    } else if (!index) {
        value = temp->data;
        *list = (*list)->next;
        free(temp);
        return value;
    } else {
        for (int i = 1; i < index && temp; i++) temp = temp->next;
        if (!temp || !temp->next) {
            printf("Index out of range");
            exit(0);
        }
        Node *next = temp->next;
        value = next->data;
        temp->next = next->next;
        free(next);
        return value;   
    }
}
bool isSorted(Node *list) {
    Node *next = list->next;

    while (next) {
        if (next->data < list->data) return false;
        list = list->next;
        next = list->next;
    }
    return true;
}
void deleteDuplicatedSorted(Node **list) {
    Node *current = *list, *next = current->next;

    while (next) {
        if (current->data == next->data) {
            next = next->next;
            free(current->next);
            current->next = next;
        } else {
            current = next;
            next = next->next;
        }
    }
}
void reverse(Node **list) {
    Node *current = *list, *prev = NULL, *end = NULL;
    while (current) {
        end = prev;
        prev = current;
        current = current->next;
        prev->next = end;
    }
    *list = prev;
}
void concatenate(Node *first, Node *second) {
    while (first->next) first = first->next;
    first->next = second;
}
Node *merge(Node *first, Node *second) {
    Node *third, *last;

    if (first->data < second->data) {
        third = last = first;
        first = first->next;
    } else {
        third = last = second;
        second = second->next;
    }
    while (first && second) {
        if (first->data < second->data) {
            last->next = first;
            last = first;
            first = first->next;
        } else {
            last->next = second;
            last = second;
            second = second->next;
        }
    }
    if (first) last->next = first;
    else last->next = second;
    return third;
}

bool isLoop (Node *list) {
    Node *first = list, *second = list;

    while (second) {
        first = first->next;
        second = second->next;
        if (second) second = second->next;
        else break;
        if (first == second) return true;
    }
    return false;
}
int main() {
    int A[] = {2, 8, 10, 15};
    int B[] = {5, 12, 12, 14};
    Node *head = create(A, 4);
    Node *tail = create(B, 4);
    Node *res = merge(head, tail);
    Display(res);
    return 0;
}
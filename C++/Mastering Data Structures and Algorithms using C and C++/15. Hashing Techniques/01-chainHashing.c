#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

int hash(int key) {return key % 7;}
void insert(Node** hashTable, int value) {
    Node **head = &hashTable[hash(value)], *current = *head, *prev = NULL;

    if (!*head) {
        *head = (Node*)malloc(sizeof(Node));
        (*head)->data = value;
        (*head)->next = NULL;
        return;
    }
    while (current) {
        if (current->data >= value) {
            if (!prev) {
                prev = (Node*)malloc(sizeof(Node));
                prev->data = value;
                prev->next = current;
                *head = prev;
            } else {
                prev->next = (Node*)malloc(sizeof(Node));
                prev = prev->next;
                prev->data = value;
                prev->next = current;
            }
            return;
        }
        prev = current;
        current = current->next;
    }
    prev->next = (Node*)malloc(sizeof(Node));
    prev = prev->next;
    prev->data = value;
    prev->next = NULL;
}
Node **create(int *array, int size) {
    Node **hashTable = (Node**)malloc(7*sizeof(Node*));
    for (int i = 0; i < 7; i++) hashTable[i] = NULL;
    for (int i = 0; i < size; i++ ) insert(hashTable, array[i]);
    return hashTable;
}
bool search(Node **hashTable, int key) {
    int idx = hash(key);
    if (!hashTable[idx]) return false;
    Node *current = hashTable[idx];

    while (current && current->data <= key) {
        if (current->data == key) return true;
        current = current->next;
    }
    return false;
}
void delete(Node **hashTable, int value) {
    int idx = hash(value);
    if (!hashTable[idx]) return;
    Node *prev = hashTable[idx], *current = prev->next;

    if (prev->data == value) {
        hashTable[idx] = current;
        return free(prev);
    }
    while (current && current->data < value) {
        prev = current;
        current = current->next;
    }
    if (!(current && current->data == value)) return;
    prev->next = current->next;
    return free(current);
}

int main() {
    int array[] = {16, 12, 25, 39, 6, 122, 5, 68, 75};
    Node **table = create(array, 9);
    delete(table, 25);
    printf("%d ", search(table, 25));
}
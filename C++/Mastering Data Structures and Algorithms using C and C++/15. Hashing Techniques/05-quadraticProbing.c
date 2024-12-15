#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int hash(int value) {return value % 7;}
int probe(int *hashTable, int size, int key) {
    int idx = hash(key), i = 0;
    while (hashTable[(idx + (i*i)) % size] != 0) i++;
    return (idx + (i*i)) % size;
}
void insert(int *hashTable, int size, int key) {
    size *= 2;
    int idx = hash(key);

    if (hashTable[idx] != 0) idx = probe(hashTable, size, key);
    hashTable[idx] = key;
}
int *create(int *array, int size) {
    int *hashTable = (int*)malloc(2*size*sizeof(int));
    for (int i = 0; i < 2 * size; i++) hashTable[i] = 0;
    for (int i = 0; i < size; i++) insert(hashTable, size, array[i]);
    return hashTable;
}
bool search(int *hashTable, int size, int key) {
    size *= 2;
    int idx = hash(key), i = 0;
    while (i < size && hashTable[(idx + (i*i)) % size] != key) i++;
    return hashTable[(idx + (i*i)) % size] == key;
}

int main() {
    int array[] = {12, 25, 35, 26};
    int *hash = create(array, 4);
    printf("%d", search(hash, 4, 26));
    return 0;
}
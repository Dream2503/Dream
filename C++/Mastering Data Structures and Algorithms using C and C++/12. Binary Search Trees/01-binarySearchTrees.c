#include <stdio.h>
#include <stdlib.h>

typedef struct Tree {    
    struct Tree *lchild, *rchild;
    int data;
} Tree;

void insert(Tree *root, int value) {
    Tree *prev;

    while (root) {
        prev = root;
        if (value < root->data) root = root->lchild;
        else if (value > root->data) root = root->rchild;
        else return;
    }
    if (value < prev->data) {
        root = (Tree*)malloc(sizeof(Tree));
        root->data = value;
        root->lchild = root->rchild = NULL;
        prev->lchild = root;
    } else {
        root = (Tree*)malloc(sizeof(Tree));
        root->data = value;
        root->lchild = root->rchild = NULL;
        prev->rchild = root;
    }
}
Tree *create(int *list, int size) {
    Tree *root = (Tree*)malloc(sizeof(Tree));
    root->data = list[0];
    root->lchild = root->rchild = NULL;
    for (int i = 1; i < size; i++) insert(root, list[i]);
}
Tree *search(Tree *root, int value) {
    while (root) {
        if (value < root->data) root = root->lchild;
        else if (value > root->data) root = root->rchild;
        else return root;
    }
    return root;
}
int height (Tree *root) {
    if (!root) return 0;
    int x = height(root->lchild), y = height(root->rchild);
    if (x > y) return ++x;
    return ++y;
}
Tree *inPre(Tree *root) {
    while (root && root->rchild) root = root->rchild;
    return root;
}
Tree *inSucc(Tree *root) {
    while (root && root->lchild) root = root->lchild;
    return root;
}
Tree *delete(Tree *root, int value) {
    if (!root) return root;

        if (!(root->lchild || root->rchild)) {
            free(root);
            return NULL;
        }
        if (value < root->data) root->lchild = delete(root->lchild, value);
        else if (value > root->data) root->rchild = delete(root->rchild, value);
        else {
            if (height(root->lchild) > height(root->rchild)) {
                Tree *temp = inPre(root->lchild);
                root->data = temp->data;
                root->lchild = delete(root->lchild, value);
            } else {
                Tree *temp = inSucc(root->rchild);
                root->data = temp->data;
                root->rchild = delete(root->rchild, value);
            }
        }
        return root;
}

int main() {return 0;}
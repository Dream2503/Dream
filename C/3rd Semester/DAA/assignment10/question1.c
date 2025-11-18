// Q1. Representation of Undirected Graph in the form of Adjacency Matrix.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int V, E, i, j;
    printf("Enter the no. of vertices: ");
    scanf("%d", &V);
    printf("Enter the no. of edges: ");
    scanf("%d", &E);
    int* edges = (int*)malloc(2 * E * sizeof(int));

    if (!edges) {
        printf("Memory was not allocated\n");
        exit(0);
    }
    for (i = 0; i < E; i++) {
        printf("Enter the %dth edge: ", i + 1);
        scanf("%d%d", &edges[i * 2], &edges[i * 2 + 1]);
    }
    int** matrix = (int**)malloc(V * sizeof(int*));

    if (!matrix) {
        printf("Memory was not allocated\n");
        exit(0);
    }
    for (i = 0; i < V; i++) {
        matrix[i] = (int*)malloc(V * sizeof(int));

        if (!matrix[i]) {
            printf("Memory was not allocated\n");
            exit(0);
        }
        for (j = 0; j < V; j++) {
            matrix[i][j] = 0;
        }
    }
    for (i = 0; i < E; i++) {
        matrix[edges[i * 2]][edges[i * 2 + 1]] = matrix[edges[i * 2 + 1]][edges[i * 2]] = 1;
    }
    printf("\nThe Adjacency Matrix representation of graph is:\n");

    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < V; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(edges);
    return 0;
}

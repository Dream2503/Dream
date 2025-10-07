//  Q1. Implementation of optimal parenthesis of given sequence of matrix using Matric Chain Multiplication and display the intermediate tables.

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int** optimal_matrix_order(int*, int);
void print_optimal_parenthesis(int**, int, int);
void print_matrix(char[], int**, int);

int main() {
    int n, i;
    printf("Enter the no. of matrices: ");
    scanf("%d", &n);
    int* p = (int*)malloc((n + 1) * sizeof(int));

    if (!p) {
        printf("Memory was not allocated\n");
        exit(0);
    }
    printf("Enter the dimensions: ");

    for (i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    int** s = optimal_matrix_order(p, n);
    print_matrix("s-matrix:", s, n);
    printf("\nThe optimal parenthesis: ");
    print_optimal_parenthesis(s, 0, n - 1);
    printf("\n");

    for (i = 0; i < n; i++) {
        free(s[i]);
    }
    free(s);
    free(p);
    return 0;
}

int** optimal_matrix_order(int* p, int n) {
    int **m = (int**)malloc(n * sizeof(int*)), **s = (int**)malloc(n * sizeof(int*)), l, i, j, k, q;

    if (!m || !s) {
        printf("Memory was not allocated\n");
        exit(0);
    }
    for (i = 0; i < n; i++) {
        m[i] = (int*)malloc(n * sizeof(int));
        s[i] = (int*)malloc(n * sizeof(int));

        if (!m[i] || !s[i]) {
            printf("Memory was not allocated\n");
            exit(0);
        }
        for (j = 0; j <= i; j++) {
            m[i][j] = 0;
            s[i][j] = -1;
        }
    }
    for (l = 1; l < n; l++) {
        for (i = 0; i < n - l; i++) {
            j = i + l;
            m[i][j] = INT_MAX;

            for (k = i; k < j; k++) {
                q = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];

                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    print_matrix("m-matrix:", m, n);

    for (i = 0; i < n; i++) {
        free(m[i]);
    }
    free(m);
    return s;
}

void print_optimal_parenthesis(int** s, int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        print_optimal_parenthesis(s, i, s[i][j]);
        print_optimal_parenthesis(s, s[i][j] + 1, j);
        printf(")");
    }
}

void print_matrix(char name[], int** matrix, int size) {
    int i, j;
    printf("\n%s\n", name);

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

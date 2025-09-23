//  Q1. Implementation to find the Longest Common Subsequence (LCS) of two given sequences and display the intermediate tables.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lcs_length(char[], char[], int, int, int**, char**);
void print_lcs(char**, char[], int, int);

int main() {
    char X[20], Y[20], **b;
    printf("Enter the first sequence: ");
    scanf("%s", X);
    printf("Enter the second sequence: ");
    scanf("%s", Y);
    int m = strlen(X), n = strlen(Y), **c = (int**)malloc((m + 1) * sizeof(int*)), i, j;
    b = (char**)malloc(m * sizeof(char*));

    if (!b || !c) {
        printf("Memory was not allocated");
        exit(0);
    }
    for (i = 0; i < m; i++) {
        c[i] = (int*)malloc((n + 1) * sizeof(int));
        b[i] = (char*)malloc(n * sizeof(char));

        if (!b[i] || !c[i]) {
            printf("Memory was not allocated");
            exit(0);
        }
    }
    c[m] = (int*)malloc((n + 1) * sizeof(int));

    if (!c[m]) {
        printf("Memory was not allocated");
        exit(0);
    }
    printf("The length of LCS is: %d\n\n", lcs_length(X, Y, m, n, c, b));
    printf("Cost Matrix after LCS-LENGTH:\n");

    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    printf("\n\nDirection Matrix after LCS-LENGTH:\n");

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%c ", b[i][j]);
        }
        printf("\n");
    }
    printf("\nThe Longest Common Subsequence of %s and %s is: ", X, Y);
    print_lcs(b, X, m - 1, n - 1);
    printf("\n");
    return 0;
}

int lcs_length(char X[], char Y[], int m, int n, int** c, char** b) {
    int i, j;

    for (i = 0; i <= m; i++) {
        c[i][0] = 0;
    }
    for (j = 1; j <= n; j++) {
        c[0][j] = 0;
    }
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i - 1][j - 1] = 'D';
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i - 1][j - 1] = 'U';
            } else {
                c[i][j] = c[i][j - 1];
                b[i - 1][j - 1] = 'L';
            }
        }
    }
    return c[m][n];
}

void print_lcs(char** b, char X[], int i, int j) {
    if (i >= 0 && j >= 0) {
        switch (b[i][j]) {
        case 'D':
            print_lcs(b, X, i - 1, j - 1);
            printf("%c", X[i]);
            break;

        case 'U':
            print_lcs(b, X, i - 1, j);
            break;

        case 'L':
            print_lcs(b, X, i, j - 1);
            break;

        default:
            printf("Invalid direction component\n");
            exit(0);
        }
    }
}

/*
Name:- Swapnaraj Mohanty
SIC :- 24BCSH93
Sec :- C2

Q. Implement graph using adjacent matrix format
*/

#include <stdio.h>
#include <stdbool.h>
#define n 10

void create_graph();
int find_start();
void dfs(int);

char graph[n][n] = {{0}};
bool visited[n] = {false};
int start = -1;

int main() {
    int i, j;
    create_graph();
    start = find_start();

    printf("DFS Traversal: ");
    dfs(start);
    printf("\n");

    return 0;
}

void create_graph() {
    char vertex, adjacent;
    printf("Enter the element to insert into the graph (A-%c): ", n - 1 + 65);
    scanf(" %c", &vertex);
    
    if (vertex != '0') {
        vertex -= 65;
        
        do {
            printf("Enter the element linked to %c: ", vertex + 65);
            scanf(" %c", &adjacent);
            
            if (adjacent != '0') {
                adjacent -= 65;
                graph[vertex][adjacent] = 1;
            }
        } while (adjacent != '0');
        create_graph();
    }
}

int find_start() {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][j]) {
                return i;
            }
        }
    }
    return 0;
}

void dfs(int element) {
    int i;
    visited[element] = true;
    printf("%c ", element + 65);

    for (i = 0; i < n; i++) {
        if (graph[element][i] && !visited[i]) {
            dfs(i);
        }
    }
}
// input - A B C D 0 B G 0 C F 0 D E 0 E F 0 F 0 G F 0 0
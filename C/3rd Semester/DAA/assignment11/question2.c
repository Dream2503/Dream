//  Q2. Implementation of Depth-First-Search Algorithm.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum { WHITE, GREY, BLACK } Color;

typedef struct AdjNode {
    int vertex;
    struct AdjNode* next;
} AdjNode;

typedef struct GraphNode {
    int vertex, start, finish;
    Color color;
    struct GraphNode* parent;
    AdjNode* head;
} GraphNode;

typedef struct {
    GraphNode* nodes;
    int V;
} Graph;

Graph create_graph(int);
void add_edge(Graph, int, int);
void print_graph(Graph);
void delete_graph(Graph);
void DFS(Graph);
void DFS_visit(Graph, GraphNode*, int*);

int main() {
    int V, source, destination;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    Graph graph = create_graph(V);

    for (int i = 0; 1; i++) {
        printf("Enter the %dth edge (-1 to stop): ", i + 1);
        scanf("%d", &source);

        if (source == -1) {
            break;
        }
        scanf("%d", &destination);
        add_edge(graph, source, destination);
        add_edge(graph, destination, source);
    }
    print_graph(graph);
    DFS(graph);
    delete_graph(graph);
    return 0;
}

Graph create_graph(int V) {
    Graph graph = {(GraphNode*)malloc(V * sizeof(GraphNode)), V};

    if (!graph.nodes) {
        printf("Memory was not allocated");
        exit(0);
    }
    for (int i = 0; i < V; i++) {
        graph.nodes[i] = (GraphNode){i, -1, -1, WHITE, NULL, NULL};
    }
    return graph;
}

void add_edge(Graph graph, int source, int destination) {
    AdjNode* node = (AdjNode*)malloc(sizeof(AdjNode));

    if (!node) {
        printf("Memory was not allocated");
        exit(0);
    }
    node->vertex = destination;
    node->next = graph.nodes[source].head;
    graph.nodes[source].head = node;
}

void print_graph(Graph graph) {
    int i;
    AdjNode* current;
    printf("\nGraph Representation:\n");

    for (i = 0; i < graph.V; i++) {
        printf("%d: ", i);
        current = graph.nodes[i].head;

        while (current) {
            printf("-> %d ", current->vertex);
            current = current->next;
        }
        printf("\n");
    }
}

void delete_graph(Graph graph) {
    int i;
    AdjNode* node;

    for (i = 0; i < graph.V; i++) {
        while (graph.nodes[i].head) {
            node = graph.nodes[i].head->next;
            free(graph.nodes[i].head);
            graph.nodes[i].head = node;
        }
    }
    free(graph.nodes);
}

void DFS(Graph graph) {
    int i, time = -1;
    printf("\nDFS Traversal: ");

    for (i = 0; i < graph.V; i++) {
        if (graph.nodes[i].color == WHITE) {
            DFS_visit(graph, &graph.nodes[i], &time);
        }
    }
    printf("\n\nAfter DFS:\n");
    printf("vertex\tcolor\tstart\tfinish\tparent\n");

    for (i = 0; i < graph.V; i++) {
        printf("%d\t", i);

        switch (graph.nodes[i].color) {
        case WHITE:
            printf("WHITE");
            break;

        case GREY:
            printf("GREY");
            break;

        case BLACK:
            printf("BLACK");
            break;
        }
        if (graph.nodes[i].start == -1) {
            printf("\tNIL\t");
        } else {
            printf("\t%d\t", graph.nodes[i].start);
        }
        if (graph.nodes[i].finish == -1) {
            printf("NIL\t");
        } else {
            printf("%d\t", graph.nodes[i].finish);
        }
        if (graph.nodes[i].parent) {
            printf("%d", graph.nodes[i].parent->vertex);
        } else {
            printf("NULL");
        }
        printf("\n");
    }
}

void DFS_visit(Graph graph, GraphNode* u, int* time) {
    GraphNode* v;
    AdjNode* adj = u->head;
    u->start = ++*time;
    u->color = GREY;
    printf("%d ", u->vertex);

    while (adj) {
        v = &graph.nodes[adj->vertex];

        if (v->color == WHITE) {
            v->color = GREY;
            v->parent = u;
            DFS_visit(graph, v, time);
        }
        adj = adj->next;
    }
    u->color = BLACK;
    u->finish = ++*time;
}

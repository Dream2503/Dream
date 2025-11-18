// Q2. Representation of Undirected Graph in the form of Adjacency List.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int V;
    Node** adj;
} Graph;

Node* create_node(int);
Graph create_graph(int);
void add_edge(Graph*, int, int);
void print_graph(Graph);
void delete_graph(Graph);

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
    Graph graph = create_graph(V);

    for (i = 0; i < E; i++) {
        add_edge(&graph, edges[i * 2], edges[i * 2 + 1]);
    }
    print_graph(graph);
    delete_graph(graph);
    free(edges);
    return 0;
}

Node* create_node(int vertex) {
    Node* node = (Node*)malloc(sizeof(Node));

    if (!node) {
        printf("Memory was not allocated\n");
        exit(0);
    }
    node->vertex = vertex;
    node->next = NULL;
    return node;
}

Graph create_graph(int V) {
    int i;
    Graph graph = {V, (Node**)malloc(V * sizeof(Node*))};

    if (!graph.adj) {
        printf("Memory was not allocated\n");
        exit(0);
    }
    for (i = 0; i < V; i++) {
        graph.adj[i] = NULL;
    }
    return graph;
}

void add_edge(Graph* graph, int source, int destination) {
    Node* node = create_node(destination);
    node->next = graph->adj[source];
    graph->adj[source] = node;

    node = create_node(source);
    node->next = graph->adj[destination];
    graph->adj[destination] = node;
}

void print_graph(Graph graph) {
    int i;
    Node* node;
    printf("\nThe Adjacency List representation of graph is:\n");

    for (i = 0; i < graph.V; i++) {
        node = graph.adj[i];
        printf("Adjacency list of vertex %d: ", i);

        while (node) {
            printf("-> %d ", node->vertex);
            node = node->next;
        }
        printf("\n");
    }
}

void delete_graph(Graph graph) {
    int i;
    Node* node;

    for (i = 0; i < graph.V; i++) {
        while (graph.adj[i]) {
            node = graph.adj[i]->next;
            free(graph.adj[i]);
            graph.adj[i] = node;
        }
    }
}

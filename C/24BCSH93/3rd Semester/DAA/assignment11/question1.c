//  Q1. Implementation of Breadth-First-Search on an Undirected Graph with Adjacency List Representation.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum { WHITE, GREY, BLACK } Color;

typedef struct AdjNode {
    int vertex;
    struct AdjNode* next;
} AdjNode;

typedef struct GraphNode {
    int vertex;
    Color color;
    int distance;
    struct GraphNode* parent;
    AdjNode* head;
} GraphNode;

typedef struct {
    int V;
    GraphNode* nodes;
} Graph;

typedef struct ListNode {
    GraphNode* data;
    struct ListNode* next;
} ListNode;

typedef struct {
    ListNode *front, *rear;
} Queue;

Graph create_graph(int);
void add_edge(Graph, int, int);
void print_graph(Graph);
void delete_graph(Graph);
void enqueue(Queue*, GraphNode*);
GraphNode* dequeue(Queue*);
int empty(Queue);
void BFS(Graph, int);

int main() {
    int V, E, source, destination;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);
    Graph graph = create_graph(V);

    for (int i = 0; i < E; i++) {
        printf("Enter the %dth edge: ", i + 1);
        scanf("%d%d", &source, &destination);
        add_edge(graph, source, destination);
        add_edge(graph, destination, source);
    }
    print_graph(graph);
    printf("\nEnter source vertex for BFS: ");
    scanf("%d", &source);
    BFS(graph, source);
    delete_graph(graph);
    return 0;
}

void enqueue(Queue* queue, GraphNode* node) {
    ListNode* new = (ListNode*)malloc(sizeof(ListNode));

    if (!new) {
        printf("Memory was not allocated");
        exit(0);
    }
    new->data = node;
    new->next = NULL;

    if (queue->rear) {
        queue->rear->next = new;
    } else {
        queue->front = new;
    }
    queue->rear = new;
}

GraphNode* dequeue(Queue* queue) {
    if (!queue->front) {
        return NULL;
    }
    ListNode* temp = queue->front;
    GraphNode* data = temp->data;
    queue->front = queue->front->next;

    if (!queue->front) {
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

int empty(Queue queue) { return queue.front == NULL; }

Graph create_graph(int V) {
    Graph graph = {V, (GraphNode*)malloc(V * sizeof(GraphNode))};

    if (!graph.nodes) {
        printf("Memory was not allocated");
        exit(0);
    }
    for (int i = 0; i < V; i++) {
        GraphNode node = {i, WHITE, INT32_MAX, NULL, NULL};
        graph.nodes[i] = node;
    }
    return graph;
}

void add_edge(Graph graph, int source, int destination) {
    AdjNode* node = (AdjNode*)malloc(sizeof(AdjNode));

    if (!node) {
        printf("Memory was not allocated");
        exit(0);
    }
    node->vertex = source;
    node->next = NULL;
    node->next = graph.nodes[destination].head;
    graph.nodes[destination].head = node;
}

void print_graph(Graph graph) {
    printf("\nAdjacency List:\n");

    for (int i = 0; i < graph.V; i++) {
        printf("%d: ", i);
        AdjNode* current = graph.nodes[i].head;

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

void BFS(Graph graph, int source) {
    int i;
    AdjNode* adj;
    GraphNode *node, *u, *v;
    Queue queue = {NULL, NULL};
    graph.nodes[source].color = GREY;
    graph.nodes[source].distance = 0;
    enqueue(&queue, &graph.nodes[source]);
    printf("\nBFS Traversal starting from vertex %d: ", source);

    while (!empty(queue)) {
        u = dequeue(&queue);
        printf("%d ", u->vertex);
        adj = u->head;

        while (adj) {
            v = &graph.nodes[adj->vertex];

            if (v->color == WHITE) {
                v->color = GREY;
                v->distance = u->distance + 1;
                v->parent = u;
                enqueue(&queue, v);
            }
            adj = adj->next;
        }
        u->color = BLACK;
    }
    printf("\n\nAfter BFS:\n");

    for (i = 0; i < graph.V; i++) {
        node = &graph.nodes[i];
        printf("Vertex %d: color=", i);

        if (node->color == WHITE) {
            printf("WHITE");
        } else if (node->color == GREY) {
            printf("GREY");
        } else {
            printf("BLACK");
        }
        printf(", distance=");

        if (node->distance == INT32_MAX) {
            printf("INF");
        } else {
            printf("%d", node->distance);
        }
        printf(", parent=");

        if (node->parent) {
            printf("%d", node->parent->vertex);
        } else {
            printf("NULL");
        }
        printf("\n");
    }
}

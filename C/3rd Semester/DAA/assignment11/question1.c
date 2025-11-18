//  Q1. Implementation of Breadth-First-Search Algorithm.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum { WHITE, GREY, BLACK } Color;

typedef struct AdjNode {
    int vertex;
    struct AdjNode* next;
} AdjNode;

typedef struct GraphNode {
    int vertex, distance;
    Color color;
    struct GraphNode* parent;
    AdjNode* head;
} GraphNode;

typedef struct {
    GraphNode* nodes;
    int V;
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
void push(Queue*, GraphNode*);
void pop(Queue*);
void BFS(Graph, int);

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
    printf("\nEnter source vertex for BFS: ");
    scanf("%d", &source);
    BFS(graph, source);
    delete_graph(graph);
    return 0;
}

void push(Queue* queue, GraphNode* node) {
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

void pop(Queue* queue) {
    if (queue->front) {
        ListNode* temp = queue->front;
        queue->front = queue->front->next;

        if (!queue->front) {
            queue->rear = NULL;
        }
        free(temp);
    }
}

Graph create_graph(int V) {
    Graph graph = {(GraphNode*)malloc(V * sizeof(GraphNode)), V};

    if (!graph.nodes) {
        printf("Memory was not allocated");
        exit(0);
    }
    for (int i = 0; i < V; i++) {
        graph.nodes[i] = (GraphNode){i, -1, WHITE, NULL, NULL};
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

void BFS(Graph graph, int source) {
    int i;
    AdjNode* adj;
    GraphNode *u, *v;
    Queue queue = {NULL, NULL};
    graph.nodes[source].color = GREY;
    graph.nodes[source].distance = 0;
    push(&queue, &graph.nodes[source]);
    printf("\nBFS Traversal starting from vertex %d: ", source);

    while (queue.front) {
        u = queue.front->data;
        pop(&queue);
        printf("%d ", u->vertex);
        adj = u->head;

        while (adj) {
            v = &graph.nodes[adj->vertex];

            if (v->color == WHITE) {
                v->color = GREY;
                v->distance = u->distance + 1;
                v->parent = u;
                push(&queue, v);
            }
            adj = adj->next;
        }
        u->color = BLACK;
    }
    printf("\n\nAfter BFS:\n");
    printf("vertex\tcolor\tdistance\tparent\n");

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
        if (graph.nodes[i].distance == -1) {
            printf("\tINF\t\t");
        } else {
            printf("\t%d\t\t", graph.nodes[i].distance);
        }
        if (graph.nodes[i].parent) {
            printf("%d", graph.nodes[i].parent->vertex);
        } else {
            printf("NULL");
        }
        printf("\n");
    }
}

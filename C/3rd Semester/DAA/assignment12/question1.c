//  Q1. Implement Dijkstra's Single Source Shortest Path Algorithm.

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct AdjNode {
    int vertex, cost;
    struct AdjNode* next;
} AdjNode;

typedef struct GraphNode {
    int vertex, distance;
    struct GraphNode* parent;
    AdjNode* head;
} GraphNode;

typedef struct {
    GraphNode* nodes;
    int V;
} Graph;

typedef struct {
    GraphNode** heap;
    int size;
} PriorityQueue;

Graph create_graph(int);
void add_edge(Graph, int, int, int);
void print_graph(Graph);
void delete_graph(Graph);
int parent(int);
void min_heapify(PriorityQueue*, int);
void push(PriorityQueue*, GraphNode*);
void pop(PriorityQueue*);
void decrease_key(PriorityQueue*, int, int);
void dijkstra(Graph, int);

int main() {
    int V, source, destination, cost;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    Graph graph = create_graph(V);

    for (int i = 0; true; i++) {
        printf("Enter the %dth edge and cost (-1 to stop): ", i + 1);
        scanf("%d", &source);

        if (source == -1) {
            break;
        }
        scanf("%d%d", &destination, &cost);
        add_edge(graph, source, destination, cost);
    }
    print_graph(graph);
    printf("\nEnter source vertex for Dijkstra's Single Source Shortest Path algorithm: ");
    scanf("%d", &source);
    dijkstra(graph, source);
    delete_graph(graph);
    return 0;
}

int parent(int i) { return (i - 1) / 2; }

void min_heapify(PriorityQueue* queue, int i) {
    int left = i * 2 + 1, right = left + 1, min = i;

    if (left < queue->size && queue->heap[left]->distance < queue->heap[min]->distance) {
        min = left;
    }
    if (right < queue->size && queue->heap[right]->distance < queue->heap[min]->distance) {
        min = right;
    }
    if (min != i) {
        GraphNode* temp = queue->heap[i];
        queue->heap[i] = queue->heap[min];
        queue->heap[min] = temp;

        if (min < queue->size / 2) {
            min_heapify(queue, min);
        }
    }
}

void push(PriorityQueue* queue, GraphNode* node) {
    queue->heap[queue->size] = node;
    decrease_key(queue, queue->size++, node->distance);
}

void pop(PriorityQueue* queue) {
    queue->heap[0] = queue->heap[--queue->size];
    min_heapify(queue, 0);
}

void decrease_key(PriorityQueue* queue, int i, int distance) {
    queue->heap[i]->distance = distance;

    while (i > 0 && queue->heap[i]->distance < queue->heap[parent(i)]->distance) {
        GraphNode* temp = queue->heap[i];
        queue->heap[i] = queue->heap[parent(i)];
        queue->heap[parent(i)] = temp;
        i = parent(i);
    }
}

Graph create_graph(int V) {
    Graph graph = {(GraphNode*)malloc(V * sizeof(GraphNode)), V};

    if (!graph.nodes) {
        printf("Memory was not allocated");
        exit(0);
    }
    for (int i = 0; i < V; i++) {
        graph.nodes[i] = (GraphNode){i, INT32_MAX, NULL, NULL};
    }
    return graph;
}

void add_edge(Graph graph, int source, int destination, int cost) {
    AdjNode* node = (AdjNode*)malloc(sizeof(AdjNode));

    if (!node) {
        printf("Memory was not allocated");
        exit(0);
    }
    node->vertex = destination;
    node->cost = cost;
    node->next = graph.nodes[source].head;
    graph.nodes[source].head = node;
}

void print_graph(Graph graph) {
    printf("\nAdjacency List:\n");
    int i;
    AdjNode* current;

    for (i = 0; i < graph.V; i++) {
        printf("%d: ", i);
        current = graph.nodes[i].head;

        while (current) {
            printf("-> {vertex=%d, cost=%d} ", current->vertex, current->cost);
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

void dijkstra(Graph graph, int source) {
    int i;
    AdjNode* adj;
    GraphNode *u, *v;
    PriorityQueue queue = {(GraphNode**)malloc(graph.V * sizeof(GraphNode*)), 0};
    bool* visited = (bool*)malloc(graph.V * sizeof(bool));
    graph.nodes[source].distance = 0;

    for (i = 0; i < graph.V; i++) {
        visited[i] = false;
        push(&queue, &graph.nodes[i]);
    }
    while (queue.size) {
        u = queue.heap[0];
        pop(&queue);
        visited[u->vertex] = true;
        adj = u->head;

        while (adj) {
            v = &graph.nodes[adj->vertex];

            if (!visited[v->vertex] && v->distance > u->distance + adj->cost) {
                for (i = 0; i < graph.V; i++) {
                    if (queue.heap[i]->vertex == v->vertex) {
                        decrease_key(&queue, i, u->distance + adj->cost);
                    }
                }
                v->parent = u;
            }
            adj = adj->next;
        }
    }
    printf("vertex\tdistance\tparent\n");

    for (i = 0; i < graph.V; i++) {
        printf("%d\t", i);

        if (graph.nodes[i].distance == INT32_MAX) {
            printf("INF\t\t");
        } else {
            printf("%d\t\t", graph.nodes[i].distance);
        }
        if (graph.nodes[i].parent) {
            printf("%d", graph.nodes[i].parent->vertex);
        } else {
            printf("NIL");
        }
        printf("\n");
    }
    free(queue.heap);
}

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct AdjNode {
    int vertex;
	int cost;
    struct AdjNode* next;
} AdjNode;
 
typedef struct GraphNode {
    int vertex;
    int distance;
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
void increase_key(PriorityQueue*, int);
void dijkstra(Graph, int);
 
int main() {
    int V, E, source, destination, cost;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);
    Graph graph = create_graph(V);
 
    for (int i = 0; i < E; i++) {
        printf("Enter the %dth edge and cost: ", i + 1);
        scanf("%d%d%d", &source, &destination, &cost);
        add_edge(graph, source, destination, cost);
    }
    print_graph(graph);
    printf("\nEnter source vertex for Dijkstra's Shortest Path algorithm: ");
    scanf("%d", &source);
    dijkstra(graph, source);
	print_graph(graph);
    delete_graph(graph);
    return 0;
}
 
int parent(int i) {
    if (i % 2 == 0) {
        return i / 2 - 1;
    }
    return i / 2;
}

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
    int i = queue->size++;
    queue->heap[i] = node;

    while (i > 0 && queue->heap[i]->distance < queue->heap[parent(i)]->distance) {
        GraphNode* temp = queue->heap[i];
        queue->heap[i] = queue->heap[parent(i)];
        queue->heap[parent(i)] = temp;
        i = parent(i);
    }
}

void pop(PriorityQueue* queue) {
    queue->heap[0] = queue->heap[--queue->size];
    min_heapify(queue, 0);
}

void increase_key(PriorityQueue* queue, int distance) {}
	
Graph create_graph(int V) {
    Graph graph = {(GraphNode*)malloc(V * sizeof(GraphNode)), V};
 
    if (!graph.nodes) {
        printf("Memory was not allocated");
        exit(0);
    }
    for (int i = 0; i < V; i++) {
        GraphNode node = {i, INT32_MAX, NULL, NULL};
        graph.nodes[i] = node;
    }
    return graph;
}
 
void add_edge(Graph graph, int source, int destination, int cost) {
    AdjNode* node = (AdjNode*)malloc(sizeof(AdjNode));
 
    if (!node) {
        printf("Memory was not allocated");
        exit(0);
    }
    node->vertex = source;
	node->cost = cost;
    node->next = graph.nodes[destination].head;
    graph.nodes[destination].head = node;
}
 
void print_graph(Graph graph) {
    printf("\nAdjacency List:\n");
	AdjNode* current;
	GraphNode node;
 
    for (int i = 0; i < graph.V; i++) {
        printf("{%d, %d}: ", i, node.distance);
        current = graph.nodes[i].head;
 
        while (current) {
			node = graph.nodes[current->vertex];
            printf("-> {%d, %d, %d} ", node.vertex, current->cost, node.parent ? node.parent->vertex : -1);
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
    GraphNode *node, *u, *v;
    PriorityQueue queue = {(GraphNode**)malloc(graph.V * sizeof(GraphNode*)), 0};
	bool *visited = (bool*)malloc(graph.V * sizeof(bool));
    graph.nodes[source].distance = 0;
	
	for (i = 0; i < graph.V; i++) {
		visited[i] = false;
		push(&queue, &graph.nodes[i]);
	}
    printf("\nDijkstra's Sigle Source Shortest Path starting from vertex %d: ", source);
 
    while (queue.size) {
		u = queue.heap[0];
        pop(&queue);
		visited[u->vertex] = true;
        adj = u->head;
 
        while (adj) {
            v = &graph.nodes[adj->vertex];
			
			if (!visited[v->vertex] && v->distance > u->distance + adj->cost) {
				v->distance = u->distance + adj->cost;
				v->parent = u;
			}
            adj = adj->next;
        }
    }
}

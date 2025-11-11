#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
5
6
0 1
0 2
1 3
1 4
2 3
3 4
*/


typedef struct GraphNode {
	char color;
	int vertex, distance;
	struct GraphNode *parent, *next;
} GraphNode;

typedef struct Graph {
	int V;
	GraphNode** adj;
} Graph;

typedef struct ListNode {
	GraphNode* data;
	struct ListNode* next;
} ListNode;

typedef struct {
	ListNode *front, *rear;
} Queue;


GraphNode* create_node(int, char, int, GraphNode*);
Graph* create_graph(int);
void add_edge(Graph*, int, int, char, int, GraphNode*);
void print_graph(Graph*);
void enqueue(Queue*, GraphNode*);
GraphNode* dequeue(Queue*);
int empty(Queue*);
void BFS(Graph*, GraphNode*);

int main() {
	int V, E, i, j;
	printf("Enter the no. of vertices: ");
	scanf("%d", &V);
	printf("Enter the no. of edges: ");
	scanf("%d", &E);
	Graph* graph = create_graph(V);
	
	for (i = 0; i < E; i++) {
		int source, destination;
		printf("Enter the %dth edge: ", i + 1);
		scanf("%d%d", &source, &destination);
		add_edge(graph, source, destination, 'W', INT_MAX, NULL);
		add_edge(graph, destination, source, 'W', INT_MAX, NULL);
	}
	print_graph(graph);
	return 0;		
}

GraphNode *create_node(int vertex, char color, int distance, GraphNode* parent) {
	GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
	node->color = color;
	node->vertex = vertex;
	node->distance = distance;
	node->parent = parent;
	node->next = NULL;
	return node;
}

Graph* create_graph(int V) {
	int i;
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->V = V;
	graph->adj = (GraphNode**)malloc(V * sizeof(GraphNode*));
	
	for (i = 0; i < V; i++) {
		graph->adj[i] = NULL;
	}
	return graph;
}

void add_edge(Graph* graph, int source, int destination, char color, int distance, GraphNode* parent) {
	GraphNode *node = create_node(destination, color, distance, parent);
	node->next = graph->adj[source];
	graph->adj[source] = node;
}

void print_graph(Graph* graph) {
	int i;
	GraphNode *node;
	
	for (i = 0; i < graph->V; i++) {
		node = graph->adj[i];
		printf("Adjacency list of vertex %d: ", i);
		
		while (node) {
			printf("-> %d ", node->vertex);
			node = node->next;
		}
		printf("\n");
	}
}

void enqueue(Queue* queue, GraphNode* node) {
	ListNode* new = (ListNode*)malloc(sizeof(ListNode));
	
	if (queue->rear) {
		queue->rear->next = new;
		queue->rear = queue->rear->next;
	} else {
		queue->front = queue->rear = new;
	}
}

GraphNode* dequeue(Queue* queue) {
	if (queue->front) {
		ListNode* node = queue->front;
		queue->front = queue->front->next;
		
		if (!queue->front) {
			queue->rear = NULL;
		}
		GraphNode* data = node->data;
		free(node);
		return data;
	}
	return NULL;
}

int empty(Queue* queue) {
	return queue->front != NULL;
}	

void BFS(Graph* graph, int source) {
	Queue queue;
	graph[source]->color = 'G';
	source->distance = 0;
	enqueue(&queue, source);
	
	while (!empty(&queue)) {
		GraphNode* u = dequeue(&queue);
		
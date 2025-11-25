//  Q2. Implementation Kruskal Minimum Spanning Tree Algorithm.

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct AdjNode {
    int vertex, cost;
    struct AdjNode* next;
} AdjNode;

typedef struct GraphNode {
    int vertex;
    AdjNode* head;
} GraphNode;

typedef struct {
    GraphNode* nodes;
    int V;
} Graph;

typedef struct {
    int* parent;
    int* size;
    int n;
} DSU;

typedef struct {
    int u, v, w;
} Edge;

Graph create_graph(int);
void add_edge(Graph, int, int, int);
void print_graph(Graph);
void delete_graph(Graph);
DSU dsu_create(int);
int dsu_find(DSU, int);
void dsu_union(DSU, int, int);
int comparator(const void*, const void*);
void kruskal_MST(Graph);

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
    kruskal_MST(graph);
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
        graph.nodes[i] = (GraphNode){i, NULL};
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

DSU dsu_create(int n) {
    DSU dsu = {malloc(n * sizeof(int)), malloc(n * sizeof(int)), n};

    if (!dsu.parent || !dsu.size) {
        printf("Memory was not allocated");
        exit(0);
    }
    for (int i = 0; i < n; i++) {
        dsu.parent[i] = i;
        dsu.size[i] = 1;
    }
    return dsu;
}

int dsu_find(DSU dsu, int x) {
    if (dsu.parent[x] != x) {
        dsu.parent[x] = dsu_find(dsu, dsu.parent[x]);
    }
    return dsu.parent[x];
}

void dsu_union(DSU dsu, int lhs, int rhs) {
    lhs = dsu_find(dsu, lhs);
    rhs = dsu_find(dsu, rhs);

    if (lhs != rhs) {
        if (dsu.size[lhs] < dsu.size[rhs]) {
            int temp = lhs;
            lhs = rhs;
            rhs = temp;
        }
        dsu.parent[rhs] = lhs;
        dsu.size[lhs] += dsu.size[rhs];
    }
}

int comparator(const void* lhs, const void* rhs) { return ((Edge*)lhs)->w - ((Edge*)rhs)->w; }

void kruskal_MST(Graph graph) {
    int E = 0, idx = 0, taken = 0;
    AdjNode* adj;
    DSU dsu = dsu_create(graph.V);

    for (int i = 0; i < graph.V; i++) {
        adj = graph.nodes[i].head;

        while (adj) {
            E++;
            adj = adj->next;
        }
    }
    Edge* edges = malloc(E * sizeof(Edge));

    for (int u = 0; u < graph.V; u++) {
        adj = graph.nodes[u].head;

        while (adj) {
            edges[idx++] = (Edge){u, adj->vertex, adj->cost};
            adj = adj->next;
        }
    }
    qsort(edges, E, sizeof(Edge), comparator);
    printf("\nKruskal Minimum Spanning Tree:\n");
    printf("source\tdestination\tcost\n");

    for (int i = 0; i < E && taken < graph.V - 1; i++) {
        if (dsu_find(dsu, edges[i].u) != dsu_find(dsu, edges[i].v)) {
            printf("%d\t\t%d\t%d\n", edges[i].u, edges[i].v, edges[i].w);
            dsu_union(dsu, edges[i].u, edges[i].v);
            taken++;
        }
    }
    free(edges);
    free(dsu.parent);
    free(dsu.size);
}

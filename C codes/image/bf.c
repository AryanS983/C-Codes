#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

void printDistances(int dist[], int V, int src) {
    printf("Shortest distances from vertex %d:\n", src);
    printf("Vertex\tDistance\n");
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            printf("%d\tINF\n", i);
        else
            printf("%d\t%d\n", i, dist[i]);
    }
}

int bellmanFord(struct Graph* graph, int src) {
    int V = graph->V;
    int E = graph->E;
    int* dist = (int*)malloc(V * sizeof(int));
    
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;
    
    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
    
    for (int i = 0; i < E; i++) {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle!\n");
            free(dist);
            return 1;
        }
    }
    
    printDistances(dist, V, src);
    free(dist);
    return 0;
}

void addEdge(struct Graph* graph, int edgeIndex, int src, int dest, int weight) {
    graph->edge[edgeIndex].src = src;
    graph->edge[edgeIndex].dest = dest;
    graph->edge[edgeIndex].weight = weight;
}

int main() {
    int V, E, src;
    
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    
    printf("Enter number of edges: ");
    scanf("%d", &E);
    
    struct Graph* graph = createGraph(V, E);
    
    printf("Enter edges (source destination weight):\n");
    for (int i = 0; i < E; i++) {
        int s, d, w;
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &s, &d, &w);
        addEdge(graph, i, s, d, w);
    }
    
    printf("Enter source vertex: ");
    scanf("%d", &src);
    
    bellmanFord(graph, src);
    
    free(graph->edge);
    free(graph);
    
    return 0;
}
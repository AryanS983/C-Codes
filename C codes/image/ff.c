#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NODES 100 

bool dfs(int graph[MAX_NODES][MAX_NODES], int source, int sink, int parent[], int nodes) {
    bool visited[MAX_NODES];
    memset(visited, 0, sizeof(visited));

    int stack[MAX_NODES], top = -1;
    stack[++top] = source;
    visited[source] = true;
    parent[source] = -1;

    while (top >= 0) {
        int u = stack[top--];
		int v;
        for (v = 0; v < nodes; v++) {
            if (!visited[v] && graph[u][v] > 0) {  
                stack[++top] = v;
                parent[v] = u;
                visited[v] = true;
                if (v == sink) return true;  
            }
        }
    }
    return false;
}


int fordFulkerson(int graph[MAX_NODES][MAX_NODES], int source, int sink, int nodes) {
    int residualGraph[MAX_NODES][MAX_NODES]; 
    int v; 
    memcpy(residualGraph, graph, sizeof(residualGraph));

    int parent[MAX_NODES];
    int maxFlow = 0;

    while (dfs(residualGraph, source, sink, parent, nodes)) {
        int pathFlow = INT_MAX;

        for (v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = (pathFlow < residualGraph[u][v]) ? pathFlow : residualGraph[u][v];
        }

        for (v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow; 
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() {
    int nodes, edges,i;
    int graph[MAX_NODES][MAX_NODES] = {0};

    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &nodes);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &edges);

    printf("Enter the edges in the format (u v capacity):\n");
    for (i = 0; i < edges; i++) {
        int u, v, capacity;
        scanf("%d %d %d", &u, &v, &capacity);
        graph[u][v] = capacity;  
    }

    int source, sink;
    printf("Enter the source node: ");
    scanf("%d", &source);
    printf("Enter the sink node: ");
    scanf("%d", &sink);

    int maxFlow = fordFulkerson(graph, source, sink, nodes);
    printf("The maximum possible flow is: %d\n", maxFlow);

    return 0;
}

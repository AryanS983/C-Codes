#include <stdio.h>
#include <string.h>
#include <limits.h>

#define V 6 

int dfs(int rGraph[V][V], int s, int t, int parent[], int visited[]) {
    visited[s] = 1;
    if (s == t)
        return 1;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && rGraph[s][v] > 0) {
            parent[v] = s;
            if (dfs(rGraph, v, t, parent, visited))
                return 1;
        }
    }
    return 0;
}

int fordFulkerson(int graph[V][V], int s, int t) {
    int u, v;
    int rGraph[V][V]; // Residual graph
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];

    int parent[V]; // To store augmenting path
    int max_flow = 0;

    while (1) {
        int visited[V];
        memset(visited, 0, sizeof(visited));

        if (!dfs(rGraph, s, t, parent, visited))
            break;

    
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            if (rGraph[u][v] < path_flow)
                path_flow = rGraph[u][v];
        }

       
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}






int main() {
    
    int graph[V][V] = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };

    int source = 0, sink = 5;
    printf("The maximum possible flow is %d\n", fordFulkerson(graph, source, sink));
    return 0;
}

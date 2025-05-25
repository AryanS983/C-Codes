#include <stdio.h>
#include <limits.h>

#define MAX_NODES 100  
#define INF INT_MAX  


int minDistance(int dist[], int visited[], int nodes) {
    int min = INF, min_index = -1;
    int v;
    for (v = 0; v < nodes; v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}


void dijkstra(int graph[MAX_NODES][MAX_NODES], int src, int nodes) {
    int dist[MAX_NODES];  
    int visited[MAX_NODES] = {0};  

    
    int i;
    for (i = 0; i < nodes; i++) {
        dist[i] = INF;
    }
    dist[src] = 0;  
    
    int count;

    for (count = 0; count < nodes - 1; count++) {
        int u = minDistance(dist, visited, nodes);  
        if (u == -1) break;  
        visited[u] = 1;

        
        int v;
        for (v = 0; v < nodes; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    
    printf("Node \t Distance from Source %d\n", src);
    
    for (i = 0; i < nodes; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}


int main() {
    int nodes, edges, u, v, weight, src;
    int graph[MAX_NODES][MAX_NODES] = {0};

    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &nodes, &edges);

    printf("Enter the edges (node1 node2 weight):\n");
    int i;
    for (i = 0; i < edges; i++) {
        scanf("%d %d %d", &u, &v, &weight);
        graph[u][v] = weight;
        graph[v][u] = weight; 
    }

    printf("Enter the source node: ");
    scanf("%d", &src);

    dijkstra(graph, src, nodes);

    return 0;
}

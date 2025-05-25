#include <stdio.h>
#include <limits.h>

#define V 5 // Number of vertices
#define INF INT_MAX

// Adjacency matrix representation (edges represent connection strength)
int graph[V][V] = {
    {0, 2, 0, 1, 0},  
    {2, 0, 3, 2, 0},  
    {0, 3, 0, 0, 1},  
    {1, 2, 0, 0, 4},  
    {0, 0, 1, 4, 0}   
};

int minDistance(int dist[], int visited[]) {
    int min = INF, minIndex = -1;
    int v;
    for (v = 0; v < V; v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void findStrongestPath(int start, int target) {
    int dist[V], visited[V], parent[V];
    int i;
    for (i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }
    dist[start] = 0;
	int count;
    for (count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        if (u == -1) break;
        visited[u] = 1;
		int v;
        for (v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
    // {0, 2, 0, 1, 0},  
    // {2, 0, 3, 2, 0},  
    // {0, 3, 0, 0, 1},  
    // {1, 2, 0, 0, 4},  
    // {0, 0, 1, 4, 0}

    if (dist[target] == INF) {
        printf("No connection to Dr. Meera.\n");
        return;
    }

    printf("Strongest introduction path (min weight): %d\nPath: ", dist[target]);
    int path[V], idx = 0, curr = target;
    while (curr != -1) {
        path[idx++] = curr;
        curr = parent[curr];
    }
    for (i = idx - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
    printf("\n");
}

int main() {
    int start, target; // Assume you are node 0, Dr. Meera is node 4
    printf("Enter the Starting node (your node): ");
    scanf("%d", &start);
    printf("Enter the destination node (Dr. Meera's node): ");
    scanf("%d", &target);
    
    printf("The strongest path is : \n");
    findStrongestPath(start, target);
    return 0;
}

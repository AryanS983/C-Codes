#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_V 10  // Maximum number of vertices
#define INF INT_MAX

// Structure to store path information
typedef struct {
    int distance;    // Stores the shortest path weight
    int predecessor; // Stores the intermediate vertex
} PathInfo;

// Function to initialize the path matrix
void initializeMatrix(PathInfo graph[MAX_V][MAX_V], int V) {
    int i, j;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (i == j) {
                graph[i][j].distance = 0;
            } else {
                graph[i][j].distance = INF;
            }
            graph[i][j].predecessor = -1;
        }
    }
}

// Function to print the path between two vertices
void printPath(PathInfo graph[MAX_V][MAX_V], int source, int dest, int V) {
    if (graph[source][dest].distance == INF) {
        printf("No path exists between node %d and %d\n", source, dest);
        return;
    }

    // Array to store the path
    int path[MAX_V];
    int path_length = 0;
    int current;
    int i;
    
    printf("Path from node %d to %d (distance: %d): ", 
           source, dest, graph[source][dest].distance);

    // Start from destination
    current = dest;
    path[path_length++] = dest;
    
    // Traverse predecessors until we reach source
    while (current != source && path_length < V) {
        current = graph[source][current].predecessor;
        if (current == -1) break;  // Check for invalid predecessor
        path[path_length++] = current;
    }

    // Print path in correct order
    for (i = path_length - 1; i >= 0; i--) {
        printf("%d", path[i]);
        if (i > 0) printf(" -> ");
    }
    printf("\n");
}

// Floyd-Warshall Algorithm implementation
void floydWarshall(PathInfo graph[MAX_V][MAX_V], int V) {
    int i, j, k;
    int newDist;

    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                // Skip if there's no path through k
                if (graph[i][k].distance == INF || graph[k][j].distance == INF)
                    continue;

                // Check for integer overflow
                if (graph[i][k].distance > INF - graph[k][j].distance) {
                    continue;
                }

                // Calculate new distance through vertex k
                newDist = graph[i][k].distance + graph[k][j].distance;

                // Update if new path is shorter
                if (newDist < graph[i][j].distance) {
                    graph[i][j].distance = newDist;
                    graph[i][j].predecessor = graph[i][k].predecessor;
                }
            }
        }
    }
}

int main() {
    PathInfo network[MAX_V][MAX_V];
    int V, E;
    int from, to, weight;
    int i, j;
    
    printf("Enter the number of nodes: ");
    scanf("%d", &V);
    
    if (V < 2 || V > MAX_V) {
        printf("Invalid number of nodes! Must be between 2 and %d.\n", MAX_V);
        return 1;
    }
    
    // Initialize the network
    initializeMatrix(network, V);
    
    printf("Enter the number of edges: ");
    scanf("%d", &E);
    
    printf("Enter edges in format: from_node to_node weight\n");
    printf("(Nodes are numbered from 0 to %d)\n", V-1);
    
    for (i = 0; i < E; i++) {
        printf("Edge %d: ", i+1);
        scanf("%d %d %d", &from, &to, &weight);
        
        if (from < 0 || from >= V || to < 0 || to >= V) {
            printf("Invalid node! Please enter valid nodes (0-%d)\n", V-1);
            i--; // Retry this edge
            continue;
        }
        
        if (weight <= 0) {
            printf("Weight must be positive!\n");
            i--; // Retry this edge
            continue;
        }
        
        network[from][to].distance = weight;
        network[from][to].predecessor = to;
    }
    
    printf("\nRunning Floyd-Warshall algorithm...\n");
    
    // Run Floyd-Warshall algorithm
    floydWarshall(network, V);
    
    // Print all shortest paths
    printf("\nShortest paths between all pairs of nodes:\n");
    printf("==========================================\n");
    
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (i != j) {
                printPath(network, i, j, V);
            }
        }
        printf("\n");
    }
    
    return 0;
}
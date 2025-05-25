#include <stdio.h>
#define INF 99999  // Representing infinity

// Number of professionals (nodes)
#define N 4  // Change this value based on the number of professionals

// Function to apply the Floyd-Warshall Algorithm
void floydWarshall(int graph[N][N]) {
    int dist[N][N]; // Matrix to store shortest paths
    int i, j, k;

    // Initialize distance matrix with given graph weights
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Floyd-Warshall Algorithm
    for (k = 0; k < N; k++) {  // Intermediate nodes
        for (i = 0; i < N; i++) {  // Source node
            for (j = 0; j < N; j++) {  // Destination node
                // If going through 'k' gives a shorter path, update
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the final shortest paths
    printf("\nShortest paths between every pair of professionals:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (dist[i][j] == INF)
                printf("%5s ", "INF");
            else
                printf("%5d ", dist[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Graph representation (Adjacency Matrix)
    int graph[N][N] = {
        {0,   3,   INF, 7},
        {8,   0,   2,   INF},
        {5,   INF, 0,   1},
        {2,   INF, INF, 0}
    };

    // Apply Floyd-Warshall Algorithm
    floydWarshall(graph);

    return 0;
}

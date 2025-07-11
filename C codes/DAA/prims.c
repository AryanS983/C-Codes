#include <stdio.h>
#include <limits.h>
#define V 5  // Number of professionals (nodes in the graph)

// Function to find the minimum key vertex
int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, minIndex;
    
    for (int v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v], minIndex = v;
        }
    }
    return minIndex;
}

// Function to print the MST
void printMST(int parent[], int graph[V][V]) {
    printf("Edge \t Weight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t %d\n", parent[i], i, graph[i][parent[i]]);
    }
}

// Function to implement Prim's algorithm
void primMST(int graph[V][V]) {
    int parent[V]; // Stores constructed MST
    int key[V];    // Key values to pick the minimum weight edge
    int mstSet[V]; // To represent vertices included in MST

    // Initialize all keys as infinite and mstSet[] as false
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX, mstSet[i] = 0;
    }

    key[0] = 0;      // Start from the first vertex
    parent[0] = -1;  // First node is always the root of MST

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet); // Pick the minimum key vertex
        mstSet[u] = 1; // Include u in MST

        // Update key and parent index of the adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u, key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

// Driver program
int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    
    primMST(graph);
    
    return 0;
}

#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

#define MAX_V 100

int minKey(int key[], bool mstSet[], int V){
    int min = INT_MAX, min_index;
    int v;
    for (v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(int parent[], int graph[][MAX_V], int V){
    printf("\nMinimum Spanning Tree:\n");
    printf("Edge \tWeight\n");
    int i;
    int cost = 0;
    for (i = 1; i < V; i++){
        printf("%d - %d \t%d \n", parent[i]+1, i+1, graph[parent[i]][i]);
        cost += graph[parent[i]][i];
    }
    printf("Total Cost: %d\n", cost);
}

void primMST(int graph[][MAX_V], int V){
    int parent[MAX_V];
    int key[MAX_V];
    bool mstSet[MAX_V];

    int i;
    for (i = 0; i < V; i++){
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    int count;
    for (count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;
        
        int v;
        for (v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph, V);
}

int main(){
    int V, E;
    int graph[MAX_V][MAX_V];
    
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    
    printf("Enter the number of edges: ");
    scanf("%d", &E);
    
    // Initialize adjacency matrix with 0
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            graph[i][j] = 0;
        }
    }
    
    printf("Enter edges in format (source destination weight):\n");
    printf("Note: Vertices should be numbered from 1 to %d\n", V);
    
    for(int i = 0; i < E; i++){
        int src, dest, weight;
        printf("Edge %d: ", i+1);
        scanf("%d %d %d", &src, &dest, &weight);
        
        // Convert to 0-based indexing
        src--; dest--;
        
        // Add edge to adjacency matrix (undirected graph)
        graph[src][dest] = weight;
        graph[dest][src] = weight;
    }
    
    printf("\nAdjacency Matrix created:\n");
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }
    
    primMST(graph, V);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX]; // Adjacency matrix
int visited[MAX];    // Visited array
int vertices;

// BFS implementation
void BFS(int startVertex) {
    int queue[MAX], front = 0, rear = 0;

    for (int i = 0; i < vertices; i++)
        visited[i] = 0;

    queue[rear++] = startVertex;
    visited[startVertex] = 1;

    printf("BFS Traversal: ");
    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < vertices; i++) {
            if (graph[currentVertex][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// DFS implementation
void DFSUtil(int vertex) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    for (int i = 0; i < vertices; i++) {
        if (graph[vertex][i] && !visited[i])
            DFSUtil(i);
    }
}

void DFS(int startVertex) {
    for (int i = 0; i < vertices; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    DFSUtil(startVertex);
    printf("\n");
}

int main() {
    int edges, src, dest, startVertex;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &vertices, &edges);

    // Initialize adjacency matrix
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            graph[i][j] = 0;

    printf("Enter edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        graph[src][dest] = 1;
        graph[dest][src] = 1; // Remove this for a directed graph
    }

    printf("Enter starting vertex for BFS and DFS: ");
    scanf("%d", &startVertex);

    BFS(startVertex);
    DFS(startVertex);

    return 0;
}


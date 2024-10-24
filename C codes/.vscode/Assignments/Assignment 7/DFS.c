#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the adjacency list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Structure for an adjacency list
typedef struct List {
    Node* head;
} List;

// Structure for a graph
typedef struct Graph {
    int V;          // Number of vertices
    List* adjacency; // Array of adjacency lists
} Graph;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with 'V' vertices
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->adjacency = (List*)malloc(V * sizeof(List));
    
    for (int i = 0; i < V; i++) {
        graph->adjacency[i].head = NULL;
    }
    
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjacency[src].head;
    graph->adjacency[src].head = newNode;
}

// Depth-First Search
void DFSUtil(Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    Node* currentNode = graph->adjacency[vertex].head;
    while (currentNode != NULL) {
        int adjacentVertex = currentNode->data;
        if (!visited[adjacentVertex]) {
            DFSUtil(graph, adjacentVertex, visited);
        }
        currentNode = currentNode->next;
    }
}

// DFS traversal starting from a given vertex
void DFS(Graph* graph, int startVertex) {
    int* visited = (int*)malloc(graph->V * sizeof(int));
    
    for (int i = 0; i < graph->V; i++) {
        visited[i] = 0;
    }

    printf("DFS starting from vertex %d: ", startVertex);
    DFSUtil(graph, startVertex, visited);
    printf("\n");

    free(visited);
}

int main() {
    int V = 6;
    Graph* graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);

    DFS(graph, 0);

    return 0;
}
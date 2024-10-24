#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent a queue for BFS
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to enqueue a node to the queue
void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = createNode(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

// Function to dequeue a node from the queue
int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        return -1; // Queue is empty
    }
    int data = queue->front->data;
    struct Node* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    return data;
}

// Function to perform BFS on a graph
void BFS(int** graph, int vertices, int start) {
    int visited[vertices];
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }
    struct Queue* queue = createQueue();
    
    visited[start] = 1;
    printf("BFS starting from vertex %d: ", start);
    printf("%d ", start);
    enqueue(queue, start);
    
    while (queue->front != NULL) {
        int currentVertex = dequeue(queue);
        for (int i = 0; i < vertices; i++) {
            if (graph[currentVertex][i] && !visited[i]) {
                visited[i] = 1;
                printf("%d ", i);
                enqueue(queue, i);
            }
        }
    }
    printf("\n");
}

int main() {
    int vertices, start;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    
    int** graph = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph[i] = (int*)malloc(vertices * sizeof(int));
    }
    
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    printf("Enter the starting vertex: ");
    scanf("%d", &start);
    
    BFS(graph, vertices, start);
    
    return 0;
}

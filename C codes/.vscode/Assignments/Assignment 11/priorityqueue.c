#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the Priority Queue
struct PQNode {
    int data;       // Data associated with the node
    int priority;   // Priority of the node
};

// Structure to represent the Priority Queue
struct PriorityQueue {
    struct PQNode* array; // Array of nodes
    int capacity;         // Maximum number of elements in the Priority Queue
    int size;            // Current number of elements in the Priority Queue
};

// Function to create a new Priority Queue
struct PriorityQueue* createPriorityQueue(int capacity) {
    struct PriorityQueue* pq = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    pq->capacity = capacity;
    pq->size = 0;
    pq->array = (struct PQNode*)malloc(capacity * sizeof(struct PQNode));
    return pq;
}

// Function to swap two Priority Queue nodes
void swap(struct PQNode* a, struct PQNode* b) {
    struct PQNode temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain the Min-Heap property after enqueue
void heapifyUp(struct PriorityQueue* pq, int idx) {
    int parent = (idx - 1) / 2;
    while (idx > 0 && pq->array[idx].priority < pq->array[parent].priority) {
        swap(&pq->array[idx], &pq->array[parent]);
        idx = parent;
        parent = (idx - 1) / 2;
    }
}

// Function to enqueue a node into the Priority Queue
void enqueue(struct PriorityQueue* pq, int data, int priority) {
    if (pq->size >= pq->capacity) {
        printf("Priority Queue is full. Cannot enqueue.\n");
        return;
    }

    struct PQNode newNode;
    newNode.data = data;
    newNode.priority = priority;

    int idx = pq->size;
    pq->array[idx] = newNode;
    pq->size++;

    heapifyUp(pq, idx);
}

// Function to maintain the Min-Heap property after dequeue
void heapifyDown(struct PriorityQueue* pq, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < pq->size && pq->array[left].priority < pq->array[smallest].priority) {
        smallest = left;
    }
    if (right < pq->size && pq->array[right].priority < pq->array[smallest].priority) {
        smallest = right;
    }

    if (smallest != idx) {
        swap(&pq->array[idx], &pq->array[smallest]);
        heapifyDown(pq, smallest);
    }
}

// Function to dequeue the node with the highest priority
struct PQNode dequeue(struct PriorityQueue* pq) {
    if (pq->size <= 0) {
        struct PQNode emptyNode = {-1, -1}; // Empty node to indicate an empty Priority Queue
        return emptyNode;
    }

    struct PQNode root = pq->array[0];
    pq->array[0] = pq->array[pq->size - 1];
    pq->size--;

    heapifyDown(pq, 0);

    return root;
}

int main() {
    struct PriorityQueue* pq = createPriorityQueue(10);

    // Enqueue elements with their priorities
    enqueue(pq, 5, 3);
    enqueue(pq, 9, 1);
    enqueue(pq, 7, 2);
    enqueue(pq, 2, 4);

    printf("Dequeue order:\n");

    // Dequeue elements in order of priority
    while (pq->size > 0) {
        struct PQNode node = dequeue(pq);
        if (node.priority != -1) {
            printf("Data: %d, Priority: %d\n", node.data, node.priority);
        }
    }

    return 0;
}

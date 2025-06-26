#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for Union-Find
struct Subset {
    int parent, rank;
};

// Function to find the subset of an element (uses path compression)
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Function to perform union of two sets (uses union by rank)
void Union(struct Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);
    
    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

// Merge function for Merge Sort
void merge(struct Edge edges[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    struct Edge L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = edges[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = edges[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].weight <= R[j].weight)
            edges[k++] = L[i++];
        else
            edges[k++] = R[j++];
    }
    while (i < n1)
        edges[k++] = L[i++];
    while (j < n2)
        edges[k++] = R[j++];
}

// Merge Sort function
void mergeSort(struct Edge edges[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(edges, left, mid);
        mergeSort(edges, mid + 1, right);
        merge(edges, left, mid, right);
    }
}

// Kruskal's Algorithm
void KruskalMST(struct Edge edges[], int V, int E) {
    mergeSort(edges, 0, E - 1); // Sort edges by weight
    
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    
    struct Edge result[V - 1]; // Store MST edges
    int e = 0, i = 0;
    
    while (e < V - 1 && i < E) {
        struct Edge nextEdge = edges[i++];
        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);
        
        if (x != y) {
            result[e++] = nextEdge;
            Union(subsets, x, y);
        }
    }
    
    printf("Edges in the Minimum Spanning Tree:\n");
    for (int j = 0; j < e; j++)
        printf("%d -- %d == %d\n", result[j].src, result[j].dest, result[j].weight);
    
    free(subsets);
}

// Driver function
int main() {
    int V, E;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V, &E);
    
    struct Edge* edges = (struct Edge*)malloc(E * sizeof(struct Edge));
    
    printf("Enter the edges (source destination weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }
    
    KruskalMST(edges, V, E);
    
    free(edges);
    return 0;
}


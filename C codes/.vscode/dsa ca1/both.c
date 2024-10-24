#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSortWithSentinel(int arr[], int n) {
    for (int i = 2; i < n; i++) {
        int j = i - 1;
        int key = arr[i];
        arr[0] = key;  // Set sentinel
        while (key < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void insertionSortWithoutSentinel(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int key = arr[i];
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main() {
    const int arraySize = 10000;
    int arr1[arraySize];
    int arr2[arraySize];

    // Seed the random number generator
    srand(time(NULL));

    // Initialize the arrays with random integers
    for (int i = 0; i < arraySize; i++) {
        arr1[i] = arr2[i] = rand();
    }

    clock_t start_time, end_time;
    double cpu_time_used;

    // Insertion sort with sentinel
    start_time = clock();
    insertionSortWithSentinel(arr1, arraySize);
    end_time = clock();
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time taken with sentinel: %f seconds\n", cpu_time_used);

    // Insertion sort without sentinel
    start_time = clock();
    insertionSortWithoutSentinel(arr2, arraySize);
    end_time = clock();
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time taken without sentinel: %f seconds\n", cpu_time_used);

    return 0;
}

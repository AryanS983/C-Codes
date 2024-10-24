#include <stdio.h>

// Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // Element found, return its index
        }
    }
    return -1; // Element not found
}

// Binary Search (Assumes the input array is sorted)
int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid; // Element found, return its index
        }
        if (arr[mid] < key) {
            left = mid + 1; // Look in the right half
        } else {
            right = mid - 1; // Look in the left half
        }
    }
    return -1; // Element not found
}

// Interpolation Search (Assumes the input array is sorted)
int interpolationSearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right && key >= arr[left] && key <= arr[right]) {
        // Estimate the position of the key using interpolation formula
        int pos = left + ((double)(right - left) / (arr[right] - arr[left])) * (key - arr[left]);

        if (arr[pos] == key) {
            return pos; // Element found, return its index
        }

        if (arr[pos] < key) {
            left = pos + 1; // Look in the right half
        } else {
            right = pos - 1; // Look in the left half
        }
    }
    return -1; // Element not found
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 12;

    printf("Linear Search:\n");
    int linearResult = linearSearch(arr, n, key);
    if (linearResult != -1) {
        printf("Element %d found at index %d\n", key, linearResult);
    } else {
        printf("Element %d not found\n", key);
    }

    printf("\nBinary Search:\n");
    int binaryResult = binarySearch(arr, n, key);
    if (binaryResult != -1) {
        printf("Element %d found at index %d\n", key, binaryResult);
    } else {
        printf("Element %d not found\n", key);
    }

    printf("\nInterpolation Search:\n");
    int interpolationResult = interpolationSearch(arr, n, key);
    if (interpolationResult != -1) {
        printf("Element %d found at index %d\n", key, interpolationResult);
    } else {
        printf("Element %d not found\n", key);
    }

    return 0;
}

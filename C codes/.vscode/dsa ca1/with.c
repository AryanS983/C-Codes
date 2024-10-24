#include <stdio.h>

void insertionSortWithSentinel(int arr[], int n) {
    int i, j;

    // Find the maximum value in the array
    int max_val = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    // Create a temporary array with space for an extra element
    int tempArray[n + 1];
    for (i = 0; i < n; i++) {
        tempArray[i] = arr[i];
    }
    tempArray[n] = max_val;  // Set sentinel value

    // Perform insertion sort
    for (i = 2; i <= n; i++) {
        int temp = tempArray[i];
        j = i - 1;

        // Move elements of tempArray[0..i-1], that are greater than temp, to one position ahead of their current position
        while (temp < tempArray[j]) {
            tempArray[j + 1] = tempArray[j];
            j--;
        }
        tempArray[j + 1] = temp;
    }

    // Copy back the sorted elements to the original array
    for (i = 0; i < n; i++) {
        arr[i] = tempArray[i];
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSortWithSentinel(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

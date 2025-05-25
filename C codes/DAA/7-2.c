#include <stdio.h>

struct Result {
    int max;
    int min;
};

struct Result findMinMax(int arr[], int low, int high) {
    struct Result res, left, right;
    
    // If there's only one element
    if (low == high) {
        res.max = res.min = arr[low];
        return res;
    }

    // If there are two elements
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            res.max = arr[low];
            res.min = arr[high];
        } else {
            res.max = arr[high];
            res.min = arr[low];
        }
        return res;
    }

    // More than two elements
    int mid = (low + high) / 2;
    left = findMinMax(arr, low, mid);
    right = findMinMax(arr, mid + 1, high);

    // Compare results of both halves
    res.max = (left.max > right.max) ? left.max : right.max;
    res.min = (left.min < right.min) ? left.min : right.min;

    return res;
}

int main() {
    int arr[] = {23, 11, 54, 2, 87, 5, 33};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Result ans = findMinMax(arr, 0, n - 1);

    printf("Minimum element: %d\n", ans.min);
    printf("Maximum element: %d\n", ans.max);

    return 0;
}

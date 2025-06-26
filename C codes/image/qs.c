#include <stdio.h>
#include <stdlib.h>

int partition(int *arr, int low, int high) {
	int pivot = arr[high];
	int i = low - 1, j, temp;

	for (j = low; j < high; j++) {
		if (arr[j] < pivot) {
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;
	return (i + 1);
}

void quickSort(int *arr, int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void printArray(int *arr, int size) {
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main() {
	int n, i;
	printf("Enter number of elements: ");
	scanf("%d", &n);

	int *arr = (int *)malloc(n * sizeof(int));
	if (arr == NULL) {
		printf("Memory allocation failed!\n");
		return 1;
	}

	printf("Enter %d elements: ", n);
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	printf("Original array: ");
	printArray(arr, n);

	quickSort(arr, 0, n - 1);

	printf("Sorted array in Ascending order: ");
	printArray(arr, n);

	free(arr);

	return 0;
}

#include<stdio.h>

#define N 10

typedef struct {
	int id;
	int start;
	int finish;
	} Job;

void merge(Job arr[], int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	Job L[n1], R[n2];

	for (i = 0; i < n1; i++) L[i] = arr[l + i];
	for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

	i = 0; j = 0; k = l;
	while (i < n1 && j < n2) {
		if (L[i].finish <= R[j].finish)
			arr[k++] = L[i++];
		else
			arr[k++] = R[j++];
		}
	while (i < n1) arr[k++] = L[i++];
	while (j < n2) arr[k++] = R[j++];
	}

void mergeSort(Job arr[], int l, int r) {
	if (l < r) {
	int m = (l + r) / 2;
	mergeSort(arr, l, m);
	mergeSort(arr, m + 1, r);
	merge(arr, l, m, r);
	}
}

void activitySelection(Job jobs[], int n) {
	int i;
	mergeSort(jobs, 0, n - 1); 

	printf("Selected Jobs: %d ", jobs[0].id);
	int last_finish = jobs[0].finish;

	for (i = 1; i < n; i++) {
		if (jobs[i].start >= last_finish) {
			printf("%d ", jobs[i].id);
			last_finish = jobs[i].finish;
		}
}
		printf("\n");
		}

int main() {
	int i;
	int s[N] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	int f[N] = {5, 7, 8, 10, 11, 12, 13, 14, 15, 16};

	Job jobs[N];
	for (i = 0; i < N; i++) {
		jobs[i].id = i + 1;
		jobs[i].start = s[i];
		jobs[i].finish = f[i];
	}

	activitySelection(jobs, N);
	return 0;
}

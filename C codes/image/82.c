#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Job {
	char id;
	int deadline;
	int profit;
	} Job;

int compare(const void* a, const void* b) {
	return ((Job*)b)->profit - ((Job*)a)->profit;
}

void scheduleJobs(Job jobs[], int n) {
	int i, j;
	qsort(jobs, n, sizeof(Job), compare);
	int maxDeadline = 0;
	for (i = 0; i < n; i++)
		if (jobs[i].deadline > maxDeadline)
		maxDeadline = jobs[i].deadline;

	char result[MAX]; 
	int slot[MAX] = {0}; 
	int totalProfit = 0;
	for (i = 0; i < n; i++) {
		for (j = jobs[i].deadline - 1; j >= 0; j--) {
			if (slot[j] == 0) {
				slot[j] = 1;
				result[j] = jobs[i].id;
				totalProfit += jobs[i].profit;
				break;
			}
		}
	}
	printf("Selected Jobs: ");
	for (i = 0; i < maxDeadline; i++)
		if (slot[i]) printf("%c ", result[i]);

	printf("\nTotal Profit: %d\n", totalProfit);
	}
	
int main() {
	Job jobs[] = {
	{'A', 2, 100},
	{'B', 1, 19},
	{'C', 2, 27},
	{'D', 1, 25},
	{'E', 3, 15}
	};
	int n = sizeof(jobs) / sizeof(jobs[0]);

	scheduleJobs(jobs, n);

return 0;
}

#include <stdio.h>

#define N 10

int main() {
    int jobs[N]   = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int start[N]  = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int finish[N] = {5, 7, 8, 10, 11, 12, 13, 14, 15, 16};

    printf("Selected Jobs (maximum number of mutually compatible jobs):\n");

    // Always select the first job
    int i = 0;
    printf("Job %d (Start: %d, Finish: %d)\n", jobs[i], start[i], finish[i]);

    // Last selected job's finish time
    int lastFinishTime = finish[i];

    // Iterate through the rest of the jobs
    for (int j = 1; j < N; j++) {
        if (start[j] >= lastFinishTime) {
            printf("Job %d (Start: %d, Finish: %d)\n", jobs[j], start[j], finish[j]);
            lastFinishTime = finish[j];
        }
    }

    return 0;
}

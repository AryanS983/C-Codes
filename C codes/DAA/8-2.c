#include <stdio.h>

int main() {
    // Jobs: A, B, C, D, E
    char jobs[] = {'A', 'B', 'C', 'D', 'E'};
    int deadline[] = {2, 1, 2, 1, 3};
    int profit[] = {100, 19, 27, 25, 15};
    int n = 5;

    // Step 1: Sort jobs by profit (descending) using simple bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (profit[j] < profit[j + 1]) {
                // swap profit
                int tempP = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = tempP;

                // swap deadline
                int tempD = deadline[j];
                deadline[j] = deadline[j + 1];
                deadline[j + 1] = tempD;

                // swap job
                char tempJ = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = tempJ;
            }
        }
    }

    // Step 2: Create a slot array to keep track of scheduled days
    int slot[3] = {0, 0, 0};   // since max deadline is 3
    char result[3];           // to store job ids for each day
    int totalProfit = 0;

    // Step 3: Try to assign each job to the latest possible free day
    for (int i = 0; i < n; i++) {
        for (int j = deadline[i] - 1; j >= 0; j--) {
            if (slot[j] == 0) {
                slot[j] = 1;
                result[j] = jobs[i];
                totalProfit += profit[i];
                break;
            }
        }
    }

    // Step 4: Print selected jobs and total profit
    printf("Job Order Selected: ");
    for (int i = 0; i < 3; i++) {
        if (slot[i] == 1)
            printf("%c ", result[i]);
    }

    printf("\nTotal Profit: %d\n", totalProfit);

    return 0;
}

#include <stdio.h>
#include <limits.h>

int MatrixChainMultiplication(int p[], int n) {
    int dp[n][n];

    // Fill the diagonal with 0s (cost of multiplying one matrix is 0)
    for (int i = 1; i < n; i++) {
        dp[i][i] = 0;
    }

    // chainLen is the length of matrix chain
    for (int chainLen = 2; chainLen < n; chainLen++) {
        for (int i = 1; i < n - chainLen + 1; i++) {
            int j = i + chainLen - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[1][n - 1]; // final answer
}

int main() {
    int p[] = {5, 10, 3, 12, 5, 50, 6};
    int n = sizeof(p) / sizeof(p[0]);

    int minCost = MatrixChainMultiplication(p, n);
    printf("Minimum number of multiplications = %d\n", minCost);

    return 0;
}

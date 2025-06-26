#include <stdio.h>
#include <limits.h>

void printOptimalParens(int s[100][100], int i, int j);

int main() {
    int dims[100];
    int n, i, j, k, L, q;

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    printf("Enter the %d dimensions (as array of length %d):\n", n, n + 1);
    for (i = 0; i < n + 1; i++) {
        scanf("%d", &dims[i]);
    }

    int dp[100][100];
    int s[100][100];

    for (i = 0; i < n; i++) {
        dp[i][i] = 0;
    }

    for (L = 2; L <= n; L++) {
        for (i = 0; i < n - L + 1; i++) {
            j = i + L - 1;
            dp[i][j] = INT_MAX;

            for (k = i; k < j; k++) {
                q = dp[i][k] + dp[k + 1][j] + dims[i] * dims[k + 1] * dims[j + 1];
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("\nMatrix dimensions:\n");
    for (i = 0; i < n; i++) {
        printf("A%d: %d x %d\n", i + 1, dims[i], dims[i + 1]);
    }

    printf("\nMinimum number of scalar multiplications: %d\n", dp[0][n - 1]);

    printf("Optimal Parenthesization: ");
    printOptimalParens(s, 0, n - 1);
    printf("\n");

    printf("\nDP Table (Minimum scalar multiplications for each subproblem):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j >= i) {
                printf("%7d", dp[i][j]);
            } else {
                printf("       ");
            }
        }
        printf("\n");
    }

    return 0;
}

void printOptimalParens(int s[100][100], int i, int j) {
    if (i == j) {
        printf("A%d", i + 1);
    } else {
        printf("(");
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        printf(")");
    }
}


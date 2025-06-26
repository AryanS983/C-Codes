#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int count = 0;

bool isSafe(int row, int col, int n, int* diag1, int* diag2, int* cols) {
    if (cols[col]) return false;
    if (diag1[row + col]) return false;
    if (diag2[row - col + n - 1]) return false;
    return true;
}

void printSolution(int* board, int n) {
    count++;
    printf("Solution: %d\n", count);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j) {
                printf("Q ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void solveNQUtil(int row, int n, int* board, int* diag1, int* diag2, int* cols) {
    if (row == n) {
        printSolution(board, n);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, n, diag1, diag2, cols)) {
            board[row] = col;
            diag1[row + col] = diag2[row - col + n - 1] = cols[col] = true;

            solveNQUtil(row + 1, n, board, diag1, diag2, cols);

            diag1[row + col] = diag2[row - col + n - 1] = cols[col] = false; // Backtrack
        }
    }
}

void solveNQ(int n) {
    int* board = (int*)malloc(n * sizeof(int));
    int* diag1 = (int*)calloc(2 * n - 1, sizeof(int));
    int* diag2 = (int*)calloc(2 * n - 1, sizeof(int));
    int* cols = (int*)calloc(n, sizeof(int));

    solveNQUtil(0, n, board, diag1, diag2, cols);

    free(board);
    free(diag1);
    free(diag2);
    free(cols);
}

int main() {
    int n;
    printf("Enter the value of N: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("N must be greater than 0\n");
        return 1;
    }

    solveNQ(n);
    printf("Total count: %d\n", count);
    return 0;
}

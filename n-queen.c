#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int **board;
int N;

bool isSafe(int row, int col) {
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (int i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQ(int col) {
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1;
            if (solveNQ(col + 1))
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}

void printSolution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}

int main() {
    printf("Enter the number of queens (N): ");
    scanf("%d", &N);

    // Dynamic memory allocation
    board = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++)
        board[i] = (int *)calloc(N, sizeof(int));

    if (!solveNQ(0)) {
        printf("Solution does not exist\n");
    } else {
        printf("One of the possible solutions:\n");
        printSolution();
    }

    // Free memory
    for (int i = 0; i < N; i++)
        free(board[i]);
    free(board);

    return 0;
}


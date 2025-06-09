#include <stdio.h>
#include <stdlib.h>

#define MAX 20  // Max board size

int board[MAX][MAX];
int positions[MAX]; // Store column position for each row
int N;

int isSafe(int row, int col) {
    int i, j;

    // Check column
    for (i = 0; i < row; i++)
        if (board[i][col])
            return 0;

    // Check upper left diagonal
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    // Check upper right diagonal
    for (i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return 0;

    return 1;
}

int placeQueens(int row) {
    if (row == N)
        return 1;

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;
            positions[row] = col + 1; // 1-based position

            if (placeQueens(row + 1))
                return 1;

            board[row][col] = 0;
            positions[row] = 0;
        }
    }

    return 0;
}

void printBoard() {
    printf("\nSolution Board:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%c ", board[i][j] ? 'Q' : '.');
        printf("\n");
    }
}

int main() {
    printf("Enter the number of queens (N): ");
    if (scanf("%d", &N) != 1 || N <= 0 || N > MAX) {
        printf("Please enter a valid positive integer (1-%d).\n", MAX);
        return 1;
    }

    // Initialize board and position array
    for (int i = 0; i < N; i++) {
        positions[i] = 0;
        for (int j = 0; j < N; j++)
            board[i][j] = 0;
    }

    if (placeQueens(0)) {
        printBoard();
        printf("\nColumn positions of queens per row:\n");
        for (int i = 0; i < N; i++)
            printf("%d ", positions[i]);
        printf("\n");
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}
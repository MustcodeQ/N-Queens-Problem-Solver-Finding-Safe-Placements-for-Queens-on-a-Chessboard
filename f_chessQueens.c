#include <stdio.h>

#define N 8

// Function to check if it's safe to place a queen at position (row, col)
int isSafe(int row, int col, int board[N][N]) {
    // Check if there is a queen in the same column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return 0;
        }
    }

    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return 0;
        }
    }

    // Check upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return 0;
        }
    }

    return 1;
}

// Recursive function to solve the N-queens problem
int solveNQueens(int row, int board[N][N]) {
    if (row == N) {
        return 1; // Base case: all queens are placed
    }

    int count = 0;

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col, board)) {
            board[row][col] = 1; // Place queen
            count += solveNQueens(row + 1, board); // Recur for next row
            board[row][col] = 0; // Backtrack
        }
    }

    return count;
}

// Function to print the chessboard with queens placed
void printChessboard(int board[N][N]) {
    printf("  +------------------------+\n");
    for (int i = 0; i < N; i++) {
        printf("%d | ", i + 1);
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1) {
                printf("Q ");
            } else if (board[i][j] == -1) {
                printf("* ");
            } else {
                printf(". ");
            }
        }
        printf("|\n");
    }
    printf("  +------------------------+\n");
    printf("    a b c d e f g h\n");
}

int main() {
    // Initialize the chessboard
    int board[N][N] = {0};

    // Example input (replace '.' with 0 and '*' with 1)
    int reserved[N][N] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };

    // Set reserved squares
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (reserved[i][j] == 1) {
                board[i][j] = -1; // Reserved square
            }
        }
    }

    // Call the recursive function to solve the problem
    int count = solveNQueens(0, board);

    // Print the number of valid placements
    printf("Number of ways to place 8 queens: %d\n", count);

    // Print the chessboard with queens placed
    printChessboard(board);

    return 0;
}

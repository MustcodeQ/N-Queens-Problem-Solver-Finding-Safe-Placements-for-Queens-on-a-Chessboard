# N-Queens Problem Solver

The N-Queens Problem Solver is a C program that efficiently solves the classic N-Queens problem. In this problem, you have to place N queens on an N×N chessboard in such a way that no two queens threaten each other. That is, no two queens share the same row, column, or diagonal.

## Features

- **Efficient Solution**: The program uses a recursive backtracking algorithm to find all possible solutions to the N-Queens problem.
- **Customizable Input**: You can customize the size of the chessboard and specify reserved squares where queens cannot be placed.
- **Detailed Output**: The program provides detailed output, including the number of valid placements and a visual representation of the chessboard with queens placed.
- **Reserved Squares**: You can mark certain squares on the chessboard as reserved, preventing queens from being placed on those squares.
- 
## Usage

1. **Compilation**: Compile the source code using a C compiler such as GCC.
2. **Execution**: Run the compiled executable.
3. **Customization**: Modify the `N` macro to change the size of the chessboard, and adjust the `reserved` array to specify reserved squares.
4. **Output**: The program will print the number of valid placements for N queens and a visual representation of the chessboard with queens placed.

## Example

Here's an example of customizing the reserved squares:

#-#-#[c]
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

/*
Problem Statement: Sudoku Solver

The Sudoku Solver problem requires solving a partially filled 9x9 Sudoku grid. 
The goal is to fill the empty cells such that:
1. Each row contains the digits 1-9 without repetition.
2. Each column contains the digits 1-9 without repetition.
3. Each of the 9 sub-grids (3x3) contains the digits 1-9 without repetition.

Write a program to solve the given Sudoku puzzle and print the completed grid.

Example:
Input:
A partially filled 9x9 grid with some cells empty (represented as 0).

Output:
A fully solved 9x9 grid that satisfies the Sudoku rules.

Note:
- The input grid will have a valid solution.
- The output should be a single valid solution.
*/

#include<iostream>
#include<vector>
using namespace std;

// Function to print the Sudoku board
void printSudoku(vector<vector<int>> sudoku) {
    int n = sudoku.size();
    // Loop through each cell of the board to print the Sudoku
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            cout << sudoku[i][j] << " ";  // Print each value with space
        }
        cout << endl;  // Move to the next line after printing a row
    }
}

// Function to check if it is safe to place a digit in a given position
bool isSafe(const vector<vector<int>>& sudoku, int row , int col , int dig) {
    int n = sudoku.size();

    // Check the column for the same digit
    for (int i = 0 ; i < n ; i++) {
        if (sudoku[i][col] == dig) return false;  // If digit already exists in column, return false
    }

    // Check the row for the same digit
    for (int i = 0 ; i < n ; i++) {
        if (sudoku[row][i] == dig) return false;  // If digit already exists in row, return false
    }

    // Check the 3x3 grid that the current cell belongs to
    int stRow = (row / 3) * 3;  // Starting row index of the 3x3 grid
    int stCol = (col / 3) * 3;  // Starting column index of the 3x3 grid

    // Loop through the 3x3 grid and check if the digit already exists
    for (int i = stRow ; i < stRow + 3 ; i++) {
        for (int j = stCol ; j < stCol + 3 ; j++) {
            if (sudoku[i][j] == dig) return false;  // If digit exists in the 3x3 grid, return false
        }
    }

    return true;  // If no conflict, the digit is safe to place
}

// Function to solve the Sudoku board using backtracking
bool sudokuSolver(vector<vector<int>>& sudoku, int row, int col) {
    int n = sudoku.size();

    // If we have processed all rows, the Sudoku is solved
    if (row == n) {
        printSudoku(sudoku);  // Print the solved Sudoku
        return true;  // Sudoku is solved
    }

    // Move to the next cell
    int nextRow = row;
    int nextCol = col + 1;  // Move to the next column
    if (nextCol == n) {  // If we're at the end of the row, move to the next row
        nextRow = row + 1;
        nextCol = 0;  // Start at the first column of the next row
    }

    // If the current cell already has a number, skip it and move to the next one
    if (sudoku[row][col] != 0) {
        return sudokuSolver(sudoku, nextRow, nextCol);  // Recursively call for the next cell
    }
    
    // Try placing digits 1-9 in the empty cell and check if they are safe
    for (int dig = 1 ; dig <= 9 ; dig++) {
        if (isSafe(sudoku, row, col, dig)) {
            sudoku[row][col] = dig;  // Place the digit in the current cell

            // Recursively call to solve the rest of the board
            if (sudokuSolver(sudoku, nextRow, nextCol)) {
                return true;  // If the board is solved, return true
            }

            sudoku[row][col] = 0;  // Backtrack: Reset the cell to 0
        }
    }

    return false;  // If no valid digit can be placed, return false (backtrack further)
}

int main() {
    // 9x9 partially filled Sudoku grid
    vector<vector<int>> sudoku = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    // Start solving the Sudoku from the top-left corner (0,0)
    sudokuSolver(sudoku, 0, 0);

    return 0;
}
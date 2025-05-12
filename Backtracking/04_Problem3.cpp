/*
Problem Statement: N-Queens Problem

The N-Queens problem is to place N chess queens on an N×N chessboard so that no two queens threaten each other. 
This means:
1. No two queens can be in the same row.
2. No two queens can be in the same column.
3. No two queens can be on the same diagonal.

Your task is to write a program to find all possible solutions to the N-Queens problem for a given value of N.

Example:
Input: N = 4
Output: 
Solution 1:
. Q . .
. . . Q
Q . . .
. . Q .

Solution 2:
. . Q .
Q . . .
. . . Q
. Q . .

Note:
- Represent the chessboard as a 2D grid where 'Q' represents a queen and '.' represents an empty space.
- The output can be in any order.
*/
#include<iostream>
#include<vector>
using namespace std;

// This function prints the current board configuration where queens are placed
void printBoard(vector<vector<char>> board){
    int n = board.size();
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "----------------\n"; // to separate different valid configurations
}

/*
    isSafe checks whether we can place a queen at board[row][col] safely.
    Since we're placing one queen per row (from top to bottom), we only need to check:
    - Left side of the current row (horizontal left)
    - Top side of the current column (vertical up)
    - Upper left diagonal
    - Upper right diagonal
*/
bool isSafe(const vector<vector<char>>& board, int row, int col){
    int n = board.size();

    // Check left side in the current row
    for (int j = 0 ; j < col ; j++){
       if (board[row][j] == 'Q') return false;
    }

    // Check upward in the current column
    for (int i = 0 ; i < row ; i++){
        if(board[i][col] == 'Q') return false;
    }

    // Check upper-left diagonal
    for (int r = row , c = col ; r >= 0 && c >= 0 ; r-- , c--){
        if (board[r][c] == 'Q') return false;
    }

    // Check upper-right diagonal
    for (int r = row , c = col ; r >= 0 && c < n ; r-- , c++){
        if (board[r][c] == 'Q') return false;
    }

    // If no queen attacks the position, it's safe
    return true;
}

/*
    NQueens is a recursive function that tries to place queens row by row.

    rows -> current row we are trying to place a queen in.
    board -> current state of the board with queens placed so far.
*/
void NQueens(int rows, vector<vector<char>> &board){
    int n = board.size();

    // Base case: all queens are placed successfully
    if (rows == n){
        printBoard(board); // Print the valid board configuration
        return;
    }

    // Try placing a queen in every column of the current row
    for (int j = 0 ; j < n ; j++){
        if(isSafe(board,rows,j)){
            // Place the queen at (rows, j)
            board[rows][j] = 'Q';

            // Recur for the next row
            NQueens(rows+1,board);

            // Backtrack: remove the queen from (rows, j)
            board[rows][j] = '.';
        }
    }
}

/*
    main() function initializes the board and calls NQueens.
    The board is a 2D grid of size n x n, filled with '.' representing empty cells.
*/
int main(){
    int n = 10; // Change n for different board sizes (like 8 for 8-Queens)

    // Step 1: Create an n x n board filled with '.'
    vector<vector<char>> board(n, vector<char>(n, '.'));

    // Step 2: Start placing queens from the first row
    NQueens(0,board);

    return 0;
}
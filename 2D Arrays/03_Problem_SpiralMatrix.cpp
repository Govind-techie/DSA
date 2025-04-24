/*
SPIRAL MATRIX PROBLEM

Problem Statement:
Given a 2D matrix (rows x cols), print all elements in **spiral order**.
The spiral order starts from the top-left corner and moves in a 
right → down → left → up pattern, repeating until all elements are printed.

Example:
Input:
1  2  3
4  5  6
7  8  9

Output:
1 2 3 6 9 8 7 4 5
*/

#include <iostream>
using namespace std;

// Function to print the matrix in spiral order
void spiralMatrix(int arr[][100], int n, int m) {

    // Initial boundaries for rows and columns
    int stRow = 0;
    int stCol = 0;
    int enRow = n-1;
    int enCol = m-1;

    // Loop runs as long as start row <= end row and start col <= end col
    while (stRow <= enRow && stCol <= enCol){

        // TOP: Traverse from left to right on the top row
        for (int i = stCol ; i <= enCol ; i++){
            cout << arr[stRow][i] << " ";
        }
        stRow++; // Move top boundary down

        // RIGHT: Traverse from top to bottom on the rightmost column
        for (int i = stRow ; i <= enRow ; i++){
            cout << arr[i][enCol] << " ";
        }
        enCol--; // Move right boundary left

        // BOTTOM: Traverse from right to left on the bottom row
        if (stRow <= enRow) {
            for (int i = enCol ; i >= stCol ; i--){
                cout << arr[enRow][i] << " ";
            }
            enRow--; // Move bottom boundary up
        }

        // LEFT: Traverse from bottom to top on the leftmost column
        if (stCol <= enCol) {
            for (int i = enRow ; i >= stRow ; i--){
                cout << arr[i][stCol] << " ";
            }
            stCol++; // Move left boundary right
        }

    }
    cout << endl;
    
}

int main(){

    int n;
    int m;
    cout << "Enter no. of rows : ";
    cin >> n;
    cout << "Enter no. of columns : ";
    cin >> m;

    int arr[100][100]; // Slight change to allow function compatibility

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "Enter element at position [" << i << "][" << j << "]: ";
            cin >> arr[i][j]; 
        }
    }

    // Call the function with same data
    spiralMatrix(arr, n, m);

    return 0;
}
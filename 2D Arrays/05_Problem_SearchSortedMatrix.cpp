/*
Problem: Search in a Row and Column-wise Sorted 2D Matrix

You are given an m x n integer matrix where each row is sorted in ascending order from left to right,
and each column is sorted in ascending order from top to bottom.
Write a function that returns the row and column index of a given target value if it exists in the matrix.
If the target is not found, return {-1, -1}.

Example:
Input:
matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]
target = 5

Output:
{1, 1} // since matrix[1][1] == 5
*/

#include<iostream>
using namespace std; 

// Function for Binary Search in a sorted 2D matrix (row-wise sorted)
void binarySearch2D(int arr[100][100], int n, int m, int target) {
    int stRow = 0;       // Start from the first row
    int enRow = n-1;     // End at the last row
    int tarRowIdx = -1;  // To store the row index of the target if found
    int tarColIdx = -1;  // To store the column index of the target if found
    
    // Binary Search on sorted 2D array matrix: O(nlogm)
    // Outer loop goes row by row
    while (stRow <= enRow){ 
        int stCol = 0;     // Start column for current row
        int enCol = m-1;   // End column for current row

        // Binary search within the current row
        while(stCol <= enCol){ 
            int mid = (stCol + enCol)/2; // Mid index of the current row

            // If target is found at current position
            if (arr[stRow][mid] == target){
                tarRowIdx = stRow;  // Store the row index
                tarColIdx = mid;    // Store the column index
                break;              // Exit inner loop
            }
    
            // If element is greater than target, move left
            if (arr[stRow][mid] > target){
                enCol = mid-1;
            }else{ // If element is smaller, move right
                stCol = mid+1;
            }
        }

        // If target was found, exit the outer loop
        if (tarRowIdx != -1) {
            break;  // Exit the outer loop if target is found
        }

        stRow++; // Move to next row if target not found in current row
    }

    // Print the result based on whether target was found or not
    if (tarRowIdx != -1) {
        cout << "Target Index = " << tarRowIdx << "," << tarColIdx << endl;
    } else {
        cout << "Target not found" << endl;
    }
}

// Function for Staircase Search in a sorted 2D matrix
void staircaseSearch2D(int arr[100][100], int n, int m, int target) {
    // STAIRCASE SEARCH (Optimised): O(n+m)
    int row = n-1; // Start from the last row
    int col = 0;   // Start from the first column
    int stairRow = -1; // Variable to store target row index (if found)
    int stairCol = -1; // Variable to store target column index (if found)
    while (row >= 0 && col < m){ // Loop until we go out of the matrix bounds
        int st = arr[row][col]; // Current element at [row][col]

        if (st == target){ // If current element is equal to target
            stairRow = row; // Store the row index
            stairCol = col; // Store the column index
            break; // Exit the loop as target is found
        }

        if (st > target){ // If current element is greater than target
            row--; // Move up (go to previous row)
        }else{ // If current element is less than target
            col++; // Move right (go to next column)
        }
    }

    cout << "Target Index : " << stairRow << "," << stairCol << endl;
}

int main(){
    int n, m;
    int target;
    cout << "Enter no. of rows : ";
    cin >> n;
    cout << "Enter no. of columns : ";
    cin >> m;
    
    int arr[100][100];
    
    // Input all elements from user
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "Enter element at position [" << i << "][" << j << "]: ";
            cin >> arr[i][j]; 
        }
    }
    
    cout << "Enter Target value : ";
    cin >> target;

    binarySearch2D(arr, n, m, target);
    staircaseSearch2D(arr, n, m, target);

    return 0;
}

/*
Approach: 

Matrix:
[ 1   2   3 ]  (Target = 6) Output : 1,2
[ 4   5   6 ]
[ 7   8   9 ]


Logic:
1. As it is a sorted 2D array i can perform binary search for each row and columns.
*/

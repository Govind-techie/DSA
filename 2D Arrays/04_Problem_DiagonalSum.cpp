/*
Problem Statement: Diagonal Sum of a Matrix

Given a square matrix (n x n), calculate the sum of both:
1. Primary diagonal (from top-left to bottom-right)
2. Secondary diagonal (from top-right to bottom-left)

Note: If the matrix has a center element (when n is odd),
count it only once in the total sum.

Example:

Input:
n = 3
Matrix:
1 2 3
4 5 6
7 8 9

Output:
25

Explanation:
Primary diagonal = 1 + 5 + 9 = 15
Secondary diagonal = 3 + 5 + 7 = 15
Center element 5 is common in both, counted twice
So, total = 15 + 15 - 5 = 25
*/

#include <iostream>
using namespace std;

// Function to calculate the sum of diagonals
int diagonalSum(int arr[100][100], int n, int m) {

    int stRow = 0;
    int stCol = 0;
    int enRow = n - 1;
    int enCol = m - 1;
    int sum = 0;

    // Calculate mid positions to subtract the center value if matrix is odd x odd
    int midRow = (stRow + enRow) / 2;
    int midCol = (stCol + enCol) / 2;

    // Primary diagonal: from top-left to bottom-right
    // i.e., arr[0][0], arr[1][1], arr[2][2], ...
    while (stRow <= enRow) {
        sum += arr[stRow][stCol];
        stRow++;
        stCol++;
    }

    // Secondary diagonal: from bottom-right to top-left
    // i.e., arr[n-1][m-1], arr[n-2][m-2], ..., arr[0][0]
    while (enRow >= 0) {
        sum += arr[enRow][enCol];
        enRow--;
        enCol--;
    }

    // If the matrix is odd x odd, center element is counted twice
    // Subtract it once to avoid duplication
    if (n % 2 != 0) {
        int midVal = arr[midRow][midCol];
        sum -= midVal;
    }

    return sum;
}

int main() {
    int n, m;
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

    // Call function and print the diagonal sum
    cout << "Diagonal Sum = " << diagonalSum(arr, n, m) << endl;
    
    // ALTERNATE METHOD: Optimised O(n)
    int sum = 0;
    for (int i = 0 ; i < n ; i++){
        sum += arr[i][i]; // Primary Diagonal Sum
        if (i != n-i-1){
            sum += arr[i][n-i-1]; // Secondary Diagonal Sum
        }
    }

    cout << "Sum = " << sum << endl;

    return 0;
}

/*
APPROACH:

Matrix:
[ 1   2   3 ]
[ 4   5   6 ]
[ 7   8   9 ]

Primary Diagonal:      1 → 5 → 9  (Top-left to bottom-right) (stCol++,stRow--)
Secondary Diagonal:    3 → 5 → 7  (Top-right to bottom-left) (enCol--,enRow--)
*/
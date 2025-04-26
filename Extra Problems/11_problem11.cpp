/*
  ❖ Problem 3: Write a Program to Find the Transpose of a Matrix

  ➤ Description:
    The transpose of a matrix is the process of swapping the rows and columns.
    Given a matrix, your task is to compute and print its transpose.

    For a matrix with dimensions n x m, the transpose will be an m x n matrix.
    The element at position (i, j) in the original matrix will be at position (j, i) in the transposed matrix.

  ➤ Example:
    Input:
        Matrix:
        a11 a12 a13
        a21 a22 a23
    
    Output (Transposed Matrix):
        a11 a21
        a12 a22
        a13 a23
*/

#include <iostream>
using namespace std;

int main(){
    int mat[2][3] = {
            {1, 3, 5},
            {2, 4, 6}
    };

    int n = 2;
    int m = 3;

    int mat2[m][n];

    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++){
            mat2[j][i] = mat[i][j];
        }
    }

    // Printing transpose matrix

    for (int i = 0 ; i < m ; i++){
        for (int j = 0 ; j < n ; j++){
            cout << mat2[i][j] << " ";
        } cout << endl;
    }
    
    return 0;
}


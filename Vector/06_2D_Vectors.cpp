/*
2D Vector:

A 2D vector is essentially a vector of vectors.
In simpler terms, it’s like a grid or a table with rows and columns, where each row is a 1D vector.

-> Think of it like a matrix or a table where each cell has a value.

A 2D vector allows you to store data in a tabular format. You can represent things like grids, matrices, or even a table of values in a more flexible and dynamic way. The rows and columns can be resized as needed during runtime.

In C++, 2D vectors are declared as:
- `vector<vector<data_type>> matrix;`  // Here `data_type` can be `int`, `float`, etc.

How It Works:
- **Each element of a 2D vector is a 1D vector (row)**. So, `matrix[i]` is a 1D vector (row) with a size of `cols`.
- You can dynamically add or remove rows and columns, making 2D vectors more flexible than static arrays.

*/

#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> vec1; // 1D vector
    vector<vector<int>> matrix; // 2D vector

    // NOTE: In case of 2D vector (matrix), each row of the matrix is an individual 1D vector with the size of cols of the matrix.
    
    // Example: Initialize a 2D vector with specific values
    matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};  // A 3x3 matrix

    // Printing the 2D vector (matrix)
    cout << "The 2D vector (matrix) is:" << endl;
    for (int i = 0; i < matrix.size(); i++) {  // Looping through rows
        for (int j = 0; j < matrix[i].size(); j++) {  // Looping through columns (matrix[i].size() represent size of each 1D vector (rows of 2D vectors))
            cout << matrix[i][j] << " ";  // Accessing each element by its row and column
        }
        cout << endl;  // Moving to the next line after each row
    }

    // Example of dynamically adding rows
    matrix.push_back({10, 11, 12});  // Adding a new row

    // Printing the updated 2D vector (matrix)
    cout << "Updated 2D vector (matrix) after adding a row:" << endl;
    for (int i = 0; i < matrix.size(); i++) {  // Looping through rows
        for (int j = 0; j < matrix[i].size(); j++) {  // Looping through columns
            cout << matrix[i][j] << " ";  // Accessing each element by its row and column
        }
        cout << endl;  // Moving to the next line after each row
    }

    // NOTE: In a 2D vector, each row can have a different number of columns (i.e., it can have a jagged structure), 
    // but this is not possible with a 2D array. In a 2D array, all rows must have the same number of columns.
    

    /*
    Example:
    In a 2D vector, one row could have 3 columns, while another could have only 2. 
    This provides flexibility in storing data with irregular row sizes.

    For instance, we can have:
    - Row 1: {1, 2, 3}
    - Row 2: {4, 5}
    - Row 3: {6, 7, 8, 9}

    But in a 2D array, every row must have the same number of columns (for example, all rows must have 3 columns).
    */

        // Declaring a 2D vector with different number of columns in each row
        vector<vector<int>> matrix2 = {{1, 2, 3}, {4, 5}, {6, 7, 8, 9}};
    
        // Printing the 2D vector (matrix) with different columns for each row
        cout << "The 2D vector (matrix) with different number of columns in each row is:" << endl;
        for (int i = 0; i < matrix2.size(); i++) {  // Looping through rows
            for (int j = 0; j < matrix2[i].size(); j++) {  // Looping through columns
                cout << matrix2[i][j] << " ";  // Accessing each element by its row and column
            }
            cout << endl;  // Moving to the next line after each row
        }

    /*
    Difference Between 2D Vectors and 2D Arrays:

    1. 2D Vectors:
    - A 2D vector is a vector of vectors, where each row is a 1D vector (row) with a varying number of columns.
    - The number of columns can be different for each row (i.e., jagged structure).
    - Memory: The rows (1D vectors) are dynamically allocated, and each row can have a different size.
    - Flexibility: You can dynamically add or remove rows or change the number of columns for each row during runtime.
    - Access: You access elements using two indices, like matrix[row][column].

    2. 2D Arrays:
    - A 2D array is a fixed-size, rectangular array where every row has the same number of columns.
    - The size of the array must be specified at compile-time (in most cases).
    - Memory: Memory for all elements is allocated at once, and the size is fixed.
    - Fixed Structure: You cannot change the number of rows or columns dynamically. The number of columns in each row must always be the same.
    - Access: Elements are accessed using two indices, just like in 2D vectors, but the size of the array is fixed.
    */

    
    return 0;
}
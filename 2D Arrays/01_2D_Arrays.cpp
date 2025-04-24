/*
2D ARRAYS : A 2D array is a collection of elements arranged in rows and columns — like a table or a matrix.

Each element can be accessed using two indices: 
    ➤ One for the row 
    ➤ One for the column

Declaration Syntax:
data_type array_name[rows][columns];

*/

#include <iostream>
using namespace std;

int main() {
    // 2D Array with 2 rows and 3 columns
    int studentMarks[2][3] = {
        {100, 98, 78}, 
        {70,  89, 96}
    };

    /*
    Representation of 2D Arrays:
    ➤ Outer braces: {{...}, {...}} → represent rows.
    ➤ Inner braces: {...} → represent one row.
    ➤ Number of elements inside each row → number of columns.

    So here:
    Row 0 → 100  98  78
    Row 1 → 70   89  96
    */

    // Accessing values using row and column index:

    cout << studentMarks[1][1] << endl;
    // Accesses value at row 1, column 1 → Output: 89

    /*
    NOTE:
    In C++, index starts from 0.
    ➤ First row → index 0
    ➤ First column → index 0
    */

    // INPUT & OUTPUT in 2D Arrays: 

        int rows,cols;
        
        cout << "Enter no. of rows : ";
        cin >> rows;
        cout << "Enter no. of columns : ";
        cin >> cols;
    
        // Declare a 2D array of size 2x3
        int arr[rows][cols];

        // NOTE : In this case we are dynamically sizing and creating array and all elements are stored in array during runtime.
        // Taking input from the user for each element of the 2D array
        // Outer loop → iterates over each row
        for (int i = 0; i < rows; i++) {
            // Inner loop → iterates over each column in the current row
            for (int j = 0; j < cols; j++) {
                // Prompt the user to enter the value at position [i][j]
                cout << "Enter element at position [" << i << "][" << j << "]: ";
                cin >> arr[i][j]; // Store the input in the 2D array
            }
        }

        cout << "\nThe 2D array (matrix) is:" << endl;

        // Outer loop → for each row
        for (int i = 0; i < rows; i++) {
            // Inner loop → for each column in the current row
            for (int j = 0; j < cols; j++) {
                cout << arr[i][j] << " "; // Print the current element with space
            }
            cout << endl; // After printing one full row, move to the next line
        }


    return 0;
}
/*
2D ARRAYS IN MEMORY (C++ Style)

A 2D array is stored in memory as a single continuous block of memory.

In C++, 2D arrays are stored in Row-Major Order:
➤ All elements of Row 0 are stored first
➤ Then all elements of Row 1, and so on...

SYNTAX:
int arr[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};

Visual representation (like matrix):
    Row 0 → 1  2  3
    Row 1 → 4  5  6

ROW-MAJOR MEMORY LAYOUT (C++ default):
Stored in memory as:
    [1][2][3][4][5][6]
Indexes:
    arr[0][0], arr[0][1], arr[0][2], arr[1][0], arr[1][1], arr[1][2]

COLUMN-MAJOR:
Stored in memory as:
    [1][4][2][5][3][6]
Indexes:
    arr[0][0], arr[1][0], arr[0][1], arr[1][1], arr[0][2], arr[1][2]

In C++, arrays are always stored in **row-major order**.

*/

#include <iostream>
using namespace std;

int main() {
    int arr[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    // Printing each element's memory address (row-wise)
    cout << "Memory addresses in Row-Major Order (C++):\n\n";

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "&arr[" << i << "][" << j << "] = " << &arr[i][j] << endl;
        }
    }

    return 0;
}

/*
HOW 2D ARRAYS ARE STORED:

Even though we write it like a matrix with rows and columns,
in memory, it's actually a flat line — a continuous block of integers.

That’s why we can access arr[i][j] using pointer notation:
    ➤ *(*(arr + i) + j)

This becomes helpful when working with:
➤ Dynamic arrays
➤ Functions that accept 2D arrays as parameters
➤ Memory optimization
*/
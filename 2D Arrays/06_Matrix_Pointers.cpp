/*
MATRIX POINTER: A matrix pointer is a pointer used to access elements of a 2D array (matrix) in memory. 
Since a 2D array is stored as a group of 1D arrays (rows), a matrix pointer typically points to the first row, and you can 
use it to navigate through rows and columns using pointer arithmetic.

NOTE: The name of a 2D array acts as a pointer to its first row (i.e., arr == &arr[0]).
*/


#include<iostream>
using namespace std;

// We must specify the number of columns in function parameters because it defines 
// how many elements each row contains. This allows the row pointer to correctly navigate through memory.

void func(int arr[][4] , int n , int m){ 
    // 'arr' is a pointer to the first row of the 2D array with 4 columns.
    return;
}

void func2(int (*ptr)[4] , int n , int m){ 
    // 'ptr' is a pointer to an array of 4 integers (i.e., a row of the 2D array).
    return;
}

// Both functions have the same meaning but use different syntax.

int main(){
    int arr[4][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };

    cout << arr << endl; // Points the entire first row.
    cout << arr + 1 << endl; // Points the entire second row.
    cout << *arr << endl; // Points to the first element of the first row (arr[0][0]) and prints its address.

    cout << *(*arr) << endl; // (OUTPUT = 1)
    cout << *(*arr+1) << endl; // (OUTPUT = 1)

    
    /*
    Understanding 2D array pointers and dereferencing:
    
    'arr' is the name of the array and acts as a pointer to the first row (arr[0])
    Its type is: int (*)[3] → meaning: pointer to an array of 3 integers
    
    '*arr' gives us the first row, i.e., arr[0]
    Since arr[0] is an array of 3 integers, '*arr' is int[3]
    But in expressions, arrays decay into pointers, so '*arr' becomes pointer to arr[0][0]
    
    '*(*arr)' means: dereference the pointer to the first row → then dereference again to get the first element
    So, '*(*arr)' gives us arr[0][0], which is 1
    
    Summary:
    arr        → address of the first row (arr[0])
    *arr       → first row itself (arr[0]), which decays to pointer to arr[0][0]
    *(*arr)    → value at arr[0][0], which is the first element of the matrix
    */
   
   /*
   MATRIX POINTER IN FUNCTIONS:
   To pass a 2D array to a function, you can use one of the following formats:
   
   1. Fixed Column Size (Recommended):
   void func(int arr[][4], int rows); // Column size must be specified
   
   2. Using Pointer to Array:
   void func(int (*arr)[4], int rows); // Pointer to an array of 4 integers
   
   3. Fully Dynamic using Double Pointers (for heap-allocated 2D arrays):
   void func(int** arr, int rows, int cols); // Less common for static arrays
   
   NOTE: Only the first row address is passed to the function (i.e., &arr[0]),
   so inside the function, pointer arithmetic helps navigate through the matrix. 
   */
  
  
    /*
    arr[i][j] = *((*arr + i) + j)

    To access a specific value in a 2D array using pointers, we can use this pointer expression.

    Explanation:
    - (*arr + i) → moves 'i' rows down from the starting row (arr[0]), giving us a pointer to the ith row.
    - ((*arr + i) + j) → moves 'j' columns forward in the ith row.
    - *((*arr + i) + j) → dereferences the address to get the value at arr[i][j].
    */

    return 0;
}
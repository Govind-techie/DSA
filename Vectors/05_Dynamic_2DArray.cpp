/*
DYNAMIC 2D ARRAY:
-> A dynamic 2D array is a two-dimensional array whose size is determined at runtime, rather than at compile time. This allows for more flexible memory management, where the dimensions of the array can be adjusted based on user input or other factors while the program is running.

NOTE: In C++, dynamic 2D arrays are typically created using pointers and the new keyword. Each row is dynamically allocated, and each row can be resized independently.
*/

#include<iostream>
using namespace std;

int main() {
    int rows, cols;

    // Step 1: Taking input for number of rows and columns for the dynamic 2D array
    cout << "Enter number of rows: ";
    cin >> rows;  // Input for rows
    cout << "Enter number of columns: ";
    cin >> cols;  // Input for columns

    // Step 2: Dynamically allocate memory for the 2D array
    // We allocate memory for an array of pointers (each pointer representing a row)
    int** arr = new int*[rows];  // This creates an array of pointers of size 'rows'

    // Step 3: Dynamically allocate memory for each row
    // Each pointer in the array points to a dynamically allocated array (a row of columns)
    for(int i = 0; i < rows; i++) {
        arr[i] = new int[cols];  // Dynamically allocate memory for each row with 'cols' columns
    }

    // Step 4: Taking user input to populate the 2D array
    cout << "Enter the values for the 2D array:" << endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << "Enter value for element [" << i << "][" << j << "]: ";
            cin >> arr[i][j];  // Taking input for each element
        }
    }

    // Step 5: Printing the 2D array
    cout << "The 2D array is:" << endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";  // Print each element of the array
        }
        cout << endl;  // New line after each row
    }

    // Step 6: Freeing dynamically allocated memory
    // After we are done with the 2D array, we need to free the allocated memory to avoid memory leaks.
    for(int i = 0; i < rows; i++) {
        delete[] arr[i];  // Free each dynamically allocated row (1D array)
    }
    delete[] arr;  // Free the array of pointers (the entire 2D array)

    return 0;
}

/*
Memory Management in Dynamic 2D Array:

1. Memory Allocation for Rows (1D Arrays):
   - The statement `new int*[rows]` creates an array of pointers in memory, where each pointer (`arr[i]`) will eventually point to a 1D array (i.e., a row).
   - Process:
     - Step 1: `new int*[rows]` allocates a block of memory to hold `rows` number of pointers.
     - This block is essentially an array of `rows` pointers (`arr[0]`, `arr[1]`, ..., `arr[rows-1]`).
     - Memory Structure: Initially, these pointers don't point to anything yet; they are just placeholders for future 1D arrays (rows).

   Visualization:
   arr (array of pointers) -> [Pointer to row 1, Pointer to row 2, Pointer to row 3, ..., Pointer to row N]

2. Memory Allocation for Each Row (1D Array):
   - After creating the array of pointers, the next step is to dynamically allocate memory for each row (each `arr[i]`) as a separate 1D array of integers.
   - The statement `arr[i] = new int[cols]` dynamically allocates a 1D array of `cols` integers for each row (`arr[i]`).
     - For each row, memory is reserved for `cols` integers, and the pointer `arr[i]` is set to point to the first element of this 1D array.
     - Memory Structure: Each pointer in `arr` will point to the start of its corresponding row, which is a contiguous block of memory holding `cols` elements.
   
   Visualization:
   arr[0] -> [ 1, 2, 3 ]  (Row 1, with 3 columns)
   arr[1] -> [ 4, 5, 6 ]  (Row 2, with 3 columns)
   arr[2] -> [ 7, 8, 9 ]  (Row 3, with 3 columns)

   So, now we have:
   - `arr[0]` points to the first row, `arr[1]` points to the second row, and so on.
   - Each row (`arr[i]`) is a 1D array with `cols` elements.

3. Accessing Elements:
   - To access any element in the 2D array, we use pointer arithmetic or array indexing like `arr[i][j]`, where:
     - `i` refers to the row index (pointer in `arr`).
     - `j` refers to the column index in the 1D array (i.e., the row).
   - Memory Access:
     - `arr[i]` is a pointer to a 1D array (the row). When you use `arr[i][j]`, you're accessing the `j`-th element in that row (the 1D array).
     - So, `arr[i][j]` is essentially `*(arr[i] + j)`, which means we dereference the `i`-th row and then access the `j`-th element in that row.
   
   Example:
   - To access the value at the 2nd row and 3rd column (let's assume `rows=3` and `cols=3`):
     ```cpp
     arr[1][2]; // This will give us the element in the second row and third column
     ```
     - In memory, this accesses the `arr[1]` (which points to the second row) and then the `arr[1][2]` (the third element in that row).

   Visualization of memory access:
   arr[0] -> [1, 2, 3]
   arr[1] -> [4, 5, 6]
   arr[2] -> [7, 8, 9]
   
   arr[1][2] -> 6  (Accessing the element in the 2nd row, 3rd column)

4. Memory Deallocation:
   - Memory Deallocation for Rows:
     - When we're done using the array, we free the dynamically allocated memory for each row.
     - The rows are 1D arrays that were created with `new int[cols]`, so we use `delete[] arr[i]` to free the memory of each row.
     - Freeing each row:
       ```cpp
       delete[] arr[i];  // Frees memory for each row (1D array)
       ```
   - Memory Deallocation for the Array of Pointers:
     - Finally, after all rows are deleted, we also need to free the array of pointers (`arr` itself), which holds the addresses of each row.
     - We free it with:
       ```cpp
       delete[] arr;  // Frees the memory for the array of pointers
       ```

   Memory Structure after deallocation:
   - All memory previously allocated to the rows and the array of pointers is now released.
   - No memory is left in the heap (unless you forget to deallocate, leading to a memory leak).

### Summary of Memory Layout and Access:

1. Step 1: Allocate Memory for Rows (Pointers):
   - `new int*[rows]` creates an array of `rows` pointers.
   
2. Step 2: Allocate Memory for Each Row (1D Arrays):
   - Each pointer `arr[i]` points to a dynamically allocated array of `cols` integers.
   
3. Step 3: Accessing Elements:
   - `arr[i][j]` accesses the `j`-th element in the `i`-th row (1D array).
   
4. Step 4: Deallocating Memory:
   - Use `delete[]` to free memory for each row (`arr[i]`), and then free the array of pointers (`arr`).

### Memory Leak:
- A memory leak occurs when memory is allocated dynamically (using `new`) but is not deallocated (using `delete[]`).
- If we forget to free memory after using it, the program will continue consuming memory without releasing it, leading to inefficient memory usage and potentially causing the program to crash.

*/
/*
Array Pointer: A pointer to an array is a pointer that stores the memory address of the first element of the array.

NOTE: It behaves like a constant pointer because the address it points to (i.e., the start of the array) cannot be changed directly.
*/

#include <iostream>
using namespace std;

int main() {
    // Example 1: Normal Pointer.
    int x = 10;
    int *ptr = &x; // ptr points to the memory address of variable x

    int y = 25;
    ptr = &y; // Now ptr points to the memory address of y instead of x

    // Explanation:
    // This shows that normal pointers can be reassigned to point to different variables.
    // So, the pointer is not constant — we can change the address it stores.

    cout << *ptr << endl; // Output: 25 (because ptr now points to y)

    // Array Pointer : Array pointer are constant pointer variable whose value can't be reassigned to point to different variables.
  
    // Example 2: Array Pointer (constant pointer).
    int arr[5] = {1, 2, 3, 4, 5};

    cout << arr << endl; // Outputs the address of arr[0] — shows that 'arr' is a pointer to the first element

    // arr = &x; //  Error: expression must be a modifiable lvalue

    /*
    Explanation:
    - The array name 'arr' behaves like a constant pointer.
    - It always points to the 0th index of the array.
    - You cannot change its value to point somewhere else.
    */
    return 0;
}
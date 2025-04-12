// An array is a collection of elements, typically of the same data type, stored in contiguous memory locations.
// It allows multiple values to be stored under a single variable name, with each value accessible using an index.

// Properties of Arrays:

// 1. Store elements of the same data type.
// 2. Contiguous memory allocation (all elements stored together in a continuous memory block).
// 3. Linear data structure (elements arranged in a sequence).

// How to Create an Array: You must mention the size and data type of the array.
// Example: int marks[5];  // '5' represents the size (number of elements) in the array.

// How to Initialize an Array with Values: Place the values inside curly braces {}.
// Example: int marks[5] = {99, 100, 86, 78, 95};

// Note: An array can store fewer elements than its defined size, but cannot store more than its size.

// Note: If the size is not mentioned, it will automatically be set based on the number of values provided.
// Example: int price[] = {20, 45, 60};  // Size is automatically set to 3.

// Accessing Array Elements: Use the index (starts from 0 to size-1).
// Example: marks[3] accesses the fourth element.

// Modifying Array Elements: You can assign a new value using its index.
// Example: marks[2] = 98;

// Caution: Accessing an index outside the array's size will lead to undefined behavior (may cause an error or garbage value).

#include<iostream>
using namespace std;

int main() {

    int marks[5] = {99, 100, 86, 78, 95};

    int price[] = {20, 45, 60};  // Array size is auto-detected as 3

    cout << marks[3] << endl;  // Access and print the element at index 3 (fourth element)

    cout << marks[2] << endl;  // Print original value at index 2

    marks[2] = 98;             // Change the value at index 2

    cout << marks[2] << endl;  // Print updated value at index 2

    // To find the size (number of elements) in the array:
    cout << sizeof(price) / sizeof(int) << endl;

    return 0;
}
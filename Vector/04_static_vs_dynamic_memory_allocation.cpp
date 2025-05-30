/*
Static Memory Allocation : Static memory allocation is the process of allocating fixed memory at compile time, before the program runs.
Dynamic Memory Allocation : Dynamic memory allocation is the process of allocating memory at runtime, as needed by the program.

Note : Static memory is allocated in stack memory whereas Dynamic memory is allocated in heap memory.

*/
#include<iostream>
#include<vector>
using namespace std;

int main(){
    // Static memory allocation: Memory is fixed and allocated at compile time
    int arr[5]; // Array of size 5. Memory for this array is allocated when the program is compiled.

    // Dynamic memory allocation: Memory is allocated at runtime as elements are added
    vector<int> vec; // Vector is initially empty. Memory will be allocated as elements are added during execution.
    
    vec.push_back(10);  // Adds 10 to the vector. If there is not enough memory, it will be resized.
    vec.push_back(20);  // Adds 20 to the vector.

    // Note: When we add a new element, if the current capacity is not enough, the vector automatically resizes (usually by doubling its size).
    // Properties of vector:
    // 1. size: The number of elements currently stored in a vector is called its size.
    // 2. capacity: The maximum number of elements a vector can hold without resizing it dynamically in memory is called its capacity.

    // Creating another vector and adding elements
    vector<int> vec_2;
    vec_2.push_back(1);  // Adds 1 to the vector
    vec_2.push_back(2);  // Adds 2 to the vector
    vec_2.push_back(3);  // Adds 3 to the vector

    // Displaying the size (number of elements) of the vector
    cout << vec_2.size() << endl;  // Size of the vector: number of elements (size = 3)

    // Displaying the capacity (maximum number of elements it can hold before resizing)
    cout << vec_2.capacity() << endl;  // Capacity of the vector: maximum elements it can store (capacity = 4)

    return 0;
}
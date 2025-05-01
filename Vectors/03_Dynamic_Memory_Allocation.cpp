/*
Dynamic Memory Allocation in C++

Dynamic memory allocation allows you to create memory during the runtime of the program.
Unlike Stack memory, which is automatically managed, Heap memory needs to be manually managed.
You must explicitly free memory created using 'new' using 'delete' to avoid memory leaks.

Key Concepts:
- 'new' keyword creates memory dynamically (in Heap).
- 'delete' keyword frees the dynamically allocated memory.
*/

#include<iostream>
using namespace std;

// Stack memory (automatically managed)
void funStack() {
    int a = 5; // 'a' is allocated in stack memory
} // When funStack() ends, 'a' is automatically deleted from stack.

// Heap memory (must be deleted manually)
void funHeap() {
    int *p = new int(5); // Dynamically allocating memory in Heap.
    // The memory is not automatically freed when the function ends. 
} // 'p' will be destroyed, but the memory created by 'new' is not automatically freed. 
  // This can cause memory leak if not deleted manually.

// Function to demonstrate memory leak
void memoryLeakExample() {
    int* p = new int(10); // Dynamically allocating memory in Heap.
    cout << "Memory allocated at: " << p << " with value: " << *p << endl;

    // Note: We are not calling 'delete p;' to free the allocated memory, causing a memory leak.
    // The allocated memory is not freed even after the function ends.
}

int main() {
    // Example 1: Allocating single variable in Heap memory
    int *p = new int;  // Creates memory for 1 integer in Heap.
    *p = 5;            // Storing value 5 in the dynamically allocated memory.
    cout << *p << endl; // Printing the value 5.

    delete p; // Free the memory allocated by 'new' (very important to avoid memory leak!)

    // Example 2: Allocating an array dynamically
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int *arr = new int[size]; // Dynamically creating an array of given size.

    // Taking input for the array
    for (int i = 0; i < size; i++) {
        cin >> arr[i];  // Storing values in dynamic array.
    }
    
    // Printing the array
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";  // Printing array values.
    }
    cout << endl;
    
    delete[] arr; // Freeing (Deleting) the entire dynamic array using 'delete[]'.

    // Demonstrating Memory Leak Example
    memoryLeakExample(); // This will create a memory leak as 'delete' is not called for 'p' and that memory is not accessible.

    return 0;
}

/*
Important Notes:
- When you use 'new' to create memory, it is allocated in the Heap (not stack).
- Memory in the Heap is NOT automatically freed when the function or program ends, unlike stack memory.
- If we forget to free dynamically allocated memory using 'delete' or 'delete[]', it leads to memory leak. 
- Memory leaks happen when memory is allocated but not deallocated, causing the program to use up more memory over time.

Stack Memory vs Heap Memory:
- Stack Memory: Automatically managed. Variables are created and destroyed when the function enters and exits. No need to delete them manually.
- Heap Memory: Requires manual management. You must explicitly free the memory using 'delete' or 'delete[]' to avoid memory leaks.

Memory Leak:
- A memory leak occurs when the program allocates memory dynamically (using 'new' or 'new[]') but forgets to deallocate it (using 'delete' or 'delete[]').
- If memory is leaked, it can consume more and more memory during the program's execution, which may eventually lead to crashes or slowdowns, especially in long-running programs.
- Always make sure to free the memory once you no longer need it to prevent memory leaks and to keep the program efficient.
*/
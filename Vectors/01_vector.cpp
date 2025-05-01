// Vector: A vector is like a dynamic array that can grow or shrink automatically as we add or remove elements.
// It is more flexible and easier to use than fixed-size arrays.

// Difference between array and vector: Arrays have a fixed size, but vectors can change their size at runtime.

// STL (Standard Template Library): STL is a powerful library in C++ that provides ready-made classes and functions
// for data structures (like vectors, lists, maps) and algorithms (like sorting and searching).

// Note: Vectors are part of the STL. To use vectors, we need to include their header file.

#include<iostream>
#include<vector> // This header file contains the code for the vector data structure (STL container).
using namespace std;

int main(){
    vector<int>vec; // Creates an empty vector of integers. (Size is 0)
    vector<int>vec_1 = {1,2,3}; // Creates a vector with 3 elements: 1, 2, and 3.
    cout<<vec_1.size()<<endl; // Prints the number of elements in vec_1 (which is 3).

    vector<int>vec_2(3,1); // Creates a vector of size 3, with all elements initialized to 1.
    cout<<vec_2.size()<<endl; // Prints the number of elements in vec_2 (which is 3).

    // Printing the elements of vec_2 one by one.
    cout<<vec_2[0]<<endl; // Prints the first element (1)
    cout<<vec_2[1]<<endl; // Prints the second element (1)
    cout<<vec_2[2]<<endl; // Prints the third element (1)

    // Note: When we give size and a value while creating a vector, it fills every position with that value.

    // For-each loop: A for-each loop automatically goes through every element of a vector.
    // The loop variable (like i) stores the value at each position, not the index.

    for(int i : vec_1){ // i stores the value of each element during the loop.
        cout<<i<<endl; // Prints each value of vec_1 (1, 2, 3)
    }

    // Note: In a for-each loop, the type of loop variable should match the type of elements in the vector.

    // Example:

    vector<char>vec_3 = {'a','b','c'}; // Creates a vector of characters.

    for(char i : vec_3){ // Looping through vec_3. i is of type char, same as elements of vec_3.
        cout<<i<<endl; // Prints each character in vec_3 (a, b, c)
    }

    return 0;

}

/*
Vector Implementation in Memory:

1. Memory Allocation:
   - A vector in C++ is implemented using dynamic memory allocation. 
   - When a vector is created, memory is allocated to store the elements. The memory is allocated on the heap (not the stack), allowing the vector to grow or shrink in size dynamically.
   - Initially, a vector has a size of 0, but it has a capacity (the amount of memory allocated for the elements). The capacity is typically greater than or equal to the size.

2. Growth and Resizing:
   - When elements are added to a vector, if the vector exceeds its current capacity, the vector automatically resizes.
   - The vector usually doubles its capacity when it runs out of space. This helps to minimize the overhead of resizing too frequently.
   - The resizing process involves allocating new memory with a larger size and copying the existing elements to the new memory location.

3. Accessing Elements:
   - The elements in a vector are stored contiguously in memory, just like an array.
   - This means you can access elements using index notation (`vec[i]`), where `i` is the index of the element in the vector.

4. Efficient Memory Management:
   - The vector uses a dynamic array internally. It will request a larger block of memory when resizing, and when the vector shrinks, it may reduce the allocated memory, but this is usually not immediate.
   - This results in amortized constant time for most operations like `push_back`, making vectors more efficient than arrays when elements are frequently added.

5. Deallocation:
   - When a vector goes out of scope, the memory allocated for the elements is automatically freed. 
   - However, if elements are removed from the vector using `pop_back()`, the memory used for those elements is freed, but the vector’s capacity remains the same unless the vector is explicitly resized (e.g., using `shrink_to_fit()`).

6. Advantages of Vectors:
   - Automatic resizing: Unlike arrays, vectors do not require you to specify the size at compile time.
   - Efficient memory usage: Vectors can grow or shrink efficiently as the number of elements changes.
   - Random access: Like arrays, vectors provide constant-time access to elements through the index.
*/


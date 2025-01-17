// Vector : A vector is a dynamic array that can automatically resize itself to accommodate elements, offering flexibility and ease of use
// compared to fixed-size arrays.

// Difference between array and vector : Arrays have a fixed size, while vectors can dynamically resize to accommodate more elements during runtime.

// STL (Standard Template Library) : The Standard Template Library (STL) is a powerful library in C++ that provides reusable, generic
// classes and functions for data structures (like vectors, lists, and maps) and algorithms (like sorting and searching).

// Note : Vectors header file and its implementation is stored in (STL) and to use vector data structure we have to include its header file.

#include<iostream>
#include <vector> // This header file is part of the STL and contains the implementation details of the vector data structure. (STL container)
using namespace std;

int main(){
    vector<int>vec; // Size of this vector is 0. (Intialization of vector)
    vector<int>vec_1 = {1,2,3}; // Size of this vector is 3. (Intialization of vector with some data).
    cout<<vec_1.size()<<endl; // It gives the size of vector.

    vector<int>vec_2(3,1); // In this vector, we intialize it with size 3 with value 1 at every index.
    cout<<vec_2.size()<<endl;

    // Here, the value at every index is same.
    cout<<vec_2[0]<<endl;
    cout<<vec_2[1]<<endl;
    cout<<vec_2[2]<<endl;

    // Note: When a vector is initialized with a size and a value, it stores the specified value at every index of the vector.

    // For each loop : A for-each loop iterates over each element in a vector, and the iterator (such as i) stores the value at that index,
    // rather than the index itself.

    for(int i : vec_1){ // Here, we use for each loop where iterator as i which stores value of vector rather than its index.
        cout<<i<<endl; // It prints the value of vector at each index of iteration.
    }

    // Note: In a for-each loop, the iterator’s datatype should be the same as the type of elements stored in the vector that being iterated over.
    
    // Eg :

    vector<char>vec_3 = {'a','b','c'};

    for(char i : vec_3){ // Here, iterator type is char which is same as the vector type.
        cout<<i<<endl; // It prints the character fo vector at each index of iteration.
    }



    return 0;
}
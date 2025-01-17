// Vector Functions : Vector functions are predefined methods in the C++ vector class that allow you to manipulate and interact with vectors.

// Types of vector functions:
// 1. size()       - Returns the number of elements in the vector.
// 2. push_back()  - Adds an element to the end of the vector.
// 3. pop_back()   - Removes the last index element from the vector.
// 4. front()      - Returns the first index element of the vector.
// 5. back()       - Returns the last index element of the vector.
// 6. at()         - Accesses the element at a specific index with bounds checking.

#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>vec = {1,2,3,4,5};

    // size() 
    cout<<vec.size()<<endl; // Returns vector size.

    // push_back()
    vec.push_back(6); // It will add an element at the end of vector.
    cout<<vec[5]<<endl;

    // pop_back()
    vec.pop_back(); // Removes the element present at last index of vector.

    // front()
    cout<<vec.front()<<endl; // Returns first index element in a vector.

    // back()
    cout<<vec.back()<<endl; // Return last index element in a vector

    // at()
    cout<<vec.at(1)<<endl; // Returns value of a specified index in a vector.

    // Note : vec[1] provides faster access without bounds checking, while vec.at(1) offers safer access with bounds checking and throws an
    // exception if the index is out of range.

    // Eg :

    cout<<vec[6]<<endl; // This will return 0 or no error as it does not check the range with respect to size of vector.
    cout<<vec.at(6)<<endl; // This will throw an error because it check whether the specified range is within vector size which gives a safer access.
    

    return 0;
}
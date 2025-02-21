/*

Vector : In C++ STL, a vector is a dynamic array that can grow and shrink in size automatically. It provides fast random access, efficient
insertion and deletion at the end, and is implemented as a dynamic contiguous memory structure. It is part of the <vector> header.

Commonly Used Vector Functions in C++
	•	size() → Returns the number of elements in the vector.
	•	capacity() → Returns the total allocated storage before reallocation.
	•	push_back(val) → Adds an element val at the end of the vector.
	•	pop_back() → Removes the last element of the vector.
	•	emplace_back(val) → Constructs and adds an element val at the end, more efficient than push_back().
	•	at(index) → Returns the element at index with bounds checking (throws error if out of range).
	•	operator[] (v[index]) → Returns the element at index without bounds checking.
	•	front() → Returns the first element of the vector.
	•	back() → Returns the last element of the vector.
	•	erase(pos) → Removes the element at the given position pos.
	•	erase(start, end) → Removes elements in the range [start, end).
	•	insert(pos, val) → Inserts val at the given position pos.
	•	clear() → Removes all elements from the vector.
	•	empty() → Returns true if the vector is empty, otherwise false.


*/


#include <iostream>
#include <vector> // Including the vector header from the Standard Template Library (STL)
using namespace std;

int main() {

    // Types of intialization in vectors : 

    vector<int> vec; // Declaring an empty vector of integers type.
    vector<int> vec1 = {1,2,3,4,5}; // Declaring and initializing a vector with predefined values.
    vector<int> vec2(3,10); // Declaring a vector of size 3, where each element is initialized to 10.
    vector<int> vec3(vec1); // Declaring a vector by copying all elements from an existing vector (vec1).


    // Vector Functions : 

    vec.push_back(1); // Added 1 at ending position of vector.
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    vec.pop_back(); // Delete the element at last index.
    
    cout << vec.size() << endl; // Returns the total elements stored in a vector.

    cout << vec.capacity() << endl; // Returns the total no. of elements that can be stored in a vector.

    
    // Note: The capacity of a vector increases exponentially, usually doubling each time it runs out of space (e.g., 1 → 2 → 4 → 8 → 16…).
    
    cout << "Value at index 2 : " << vec[2] << " or " << vec.at(2) << endl;

    /*
    Note : vec.at(index) provides bounds checking and throws an exception if out of range, while vec[index] does not check bounds and may 
    cause undefined behavior.
    */

    cout << "Front Value : " << vec.front() << endl; // Returns starting value of vector.
    cout << "Back Value : " << vec.back() << endl; // Returns ending value of vector. 

    
    
    
    // In a vector to print the elements stored in the vector we used for each loop.
    
    for (int elements : vec){
        cout << elements << " ";
    }
    
    cout << endl;
    
    // Erase Function : 

    cout << "Original vector: ";
    for (int val : vec1) {
        cout << val << " ";
    }
    cout << endl;

    // Erasing the element at index 2 (30 will be removed)
    vec1.erase(vec1.begin() + 2);

    cout << "After erasing element at index 2: ";
    for (int val : vec1) {
        cout << val << " ";
    }
    cout << endl;

    // Erasing a range of elements (removing 20 and 40)
    vec1.erase(vec1.begin(), vec1.begin() + 2); // The erase function removes elements within a given range by iterating through the vector and deleting them within a given range.
    cout << "After erasing first two elements: ";
    for (int val : vec1) {
        cout << val << " ";
    }
    cout << endl;

    // Note : The erase function in C++ takes an iterator as its parameter
    // Note : Erase Function changes the size of vector but does not affect it capacity which remains same.


    // Insert Function :

    cout << "Original vector: ";
    for (int val : vec2) {
        cout << val << " ";
    }
    cout << endl;

    // Inserting a single element 40 at index 3
    vec2.insert(vec2.begin() + 3, 40);

    cout << "After inserting 40 at index 3: ";
    for (int val : vec2) {
        cout << val << " ";
    }
    cout << endl;

    // Inserting multiple copies of 5 at index 2
    vec2.insert(vec2.begin() + 2, 2, 5); // Inserts two 5s at index 2

    cout << "After inserting two 5s at index 2: ";
    for (int val : vec2) {
        cout << val << " ";
    }
    cout << endl;

    // Inserting elements from another vector
    vec2.insert(vec2.end(), vec1.begin(), vec1.end());

    cout << "After inserting element {4,5} at the end from other vector : ";
    for (int val : vec2) {
        cout << val << " ";
    }
    cout << endl;

    // Clear : 

    vec1.clear(); // Delete all the element stored in a vector. (It affect the size of vector but not its capacity)

    cout << "Size of vec1 : " << vec1.size() << endl; // Returns 0 as all element stored in vec1 is cleared or deleted using clear function.

    // Empty : 

    cout << "Is vec1 is empty : " << vec1.empty() << endl; // Returns a boolean value either true (1) or false (0).

    /*
    Iterators: Iterators are like pointers that help move through elements in a container (like vectors or lists). You can use them to access
    elements (*) and move forward (++).
    */

    // Vector Iterators : 

    vector<int> vec4 = {1, 2, 3, 4, 5};

    cout << "vec.begin() : " << *(vec4.begin()) << endl; // Dereferencing the iterator pointing to the first element (index 0) of the vector.  
    cout << "vec.end() : " << *(vec4.end()) << endl; // vec.end() points one position ahead of the last element, so dereferencing it leads to undefined behavior.

    // Initialization of vector iterators :

    vector<int>::iterator itr1;

    // Forward Loop using iterators
    for (itr1 = vec4.begin() ; itr1 != vec4.end() ; itr1++){
        cout << *(itr1) << " "; // The iterator (itr) does not directly store a value. Instead, it points to the memory location of an element, so we need to dereference it (*itr) to access the actual value.
    }
    cout << endl;

    // Reverse Iterators : 

    cout << "vec.rbegin() : " << *(vec4.rbegin()) << endl; // Dereferencing the reverse iterator pointing to the last element of the vector. 
    cout << "vec.rend() : "  << *(vec4.rend()) << endl; // vec.rend() points one position before the first element, so dereferencing it leads to undefined behavior.

    // Initialization of reverse iterators :

    vector<int>::reverse_iterator itr2;

    // Backward Loop using reverse iterators
    for (itr2 = vec4.rbegin() ; itr2 != vec4.rend() ; itr2++){ // Note : Reverse iterators work backward internally, so itr2++ moves to the previous element, while itr2-- would move forward, which is incorrect.
        cout << *(itr2) << " ";
    } cout << endl;


    // Auto Keyword :  The auto keyword simplifies iterator declarations by automatically deducing the correct type, making code cleaner and more readable.

    vector<int> vec5 = {1, 2, 3, 4, 5};

    // Using auto with an iterator
    for (auto itr = vec5.begin(); itr != vec5.end(); ++itr) { 
        cout << *itr << " "; // Dereferencing iterator to access value
    }
    return 0;
}

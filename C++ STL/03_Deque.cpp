/*
Deque (Double-Ended Queue): 
In STL, deque (double-ended queue) is a sequence container that allows fast insertions and deletions from both the front and back, 
unlike vectors, which only allow efficient operations at the end. It provides dynamic resizing by allocating memory in chunks and 
supports random access like vectors.
*/

#include <iostream>
#include <deque>
using namespace std;

int main() {
    // Initialization of a deque

    deque<int> d; // Initializing an empty deque.
    deque<int> d1 = {1, 2, 3, 4, 5};

    d.push_back(1);  // Insert an element at the end of deque.
    d.push_back(2);
    d.push_front(3); // Insert an element at the front of deque.
    d.push_front(5);

    d.pop_back();  // Delete the last element of deque.
    d.pop_front(); // Delete the first element of deque.

    for (int val : d) {
        cout << val << " ";
    }
    cout << endl;

    // Difference Between List and Deque:
    // A list does not support direct random access (O(n)) since its elements are not stored in contiguous memory,
    // while a deque allows fast random access (O(1)) like a vector.

    // Random access in deque (Allowed)
    cout << "Deque element at index 2: " << d1[2] << endl; // Output: 3

    // Random access in list (Not Allowed)
    // cout << "List element at index 2: " << l[2] << endl; // Error: Lists do not support direct access.

    return 0;
}
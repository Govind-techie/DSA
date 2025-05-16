/*
Notes on C++ STL list:

1. Purpose:
   - The `list` in C++ STL is a doubly linked list implementation.
   - Allows efficient insertion and deletion from both ends and at any position.

2. Header File:
   - #include <list>

3. Key Features:
   - Doubly linked: Each node points to both the next and previous node.
   - Dynamic size: Grows and shrinks as needed.
   - Fast insertions/deletions: O(1) time at the beginning, end, or with an iterator.
   - Slower random access: No direct access by index (unlike vector or array).

4. Common Functions:
   - push_front(val): Insert at the beginning.
   - push_back(val): Insert at the end.
   - pop_front(): Remove from the beginning.
   - pop_back(): Remove from the end.
   - insert(iterator, val): Insert at a specific position.
   - erase(iterator): Remove at a specific position.
   - size(): Returns the number of elements.
   - empty(): Checks if the list is empty.
   - clear(): Removes all elements.
   - front(): Access first element.
   - back(): Access last element.

5. Example Usage:
   #include <list>
   using namespace std;
   list<int> myList;
   myList.push_back(10);
   myList.push_front(5);
   myList.pop_back();

6. When to use:
   - When you need frequent insertions/deletions in the middle of the sequence.
   - When random access is not required.
*/


/*
    Iterators in C++ STL list

    1. What is an Iterator?
    - Object used to access/traverse elements in containers

    2. Declaring an Iterator:
    list<int>::iterator it;

    3. Begin and End:
    - ll.begin() → points to first element
    - ll.end()   → points just past the last element

    4. Traversing a list using iterator:
    for (auto it = ll.begin(); it != ll.end(); ++it)
        cout << *it << " ";

    5. Range-based loop (C++11+):
    for (int val : ll)
        cout << val << " ";

    NOTE: Iterators in C++ are objects that allow you to traverse through the elements of a
    container (like arrays, vectors, lists, etc.) in a sequential manner.
*/

#include<iostream>
#include<list>
#include<iterator>
using namespace std;

// Function to print the linked list
void printList(list<int> ll){
    list<int>::iterator itr;

    // Traverse the list using iterator
    for (itr = ll.begin(); itr != ll.end(); itr++){
        cout << (*itr) << "->";
    }
    cout << "NULL" << endl;
}

int main(){
    list<int> ll; // Declare a doubly linked list of integers

    ll.push_front(2); // Insert 2 at the beginning
    ll.push_front(1); // Insert 1 at the beginning

    ll.push_back(3); // Insert 3 at the end
    ll.push_back(4); // Insert 4 at the end

    list<int>::iterator itr; // Declare an iterator for the list

    printList(ll); // Print the current list
    
    cout << "size = " << ll.size() << endl; // Print size of the list
    
    cout << "head = " << ll.front() << endl; // Print first element
    cout << "tail = " << ll.back() << endl;  // Print last element
    
    ll.pop_front(); // Remove first element
    ll.pop_back();  // Remove last element
    
    printList(ll); // Print the current list
    return 0;
}
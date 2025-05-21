/*

Queue STL in C++ - Simple Notes

1. What is Queue STL?
   - The C++ Standard Template Library (STL) provides a built-in queue container.
   - It follows the First In First Out (FIFO) principle.

2. Header File:
   - #include <queue>

3. Basic Operations:
   - push(x): Adds element x to the back of the queue.
   - pop(): Removes the front element.
   - front(): Returns the front element.
   - back(): Returns the last element.
   - empty(): Checks if the queue is empty.
   - size(): Returns the number of elements.
*/

#include <iostream>
#include <queue> // Include queue header

using namespace std;

int main() {
    queue<int> q; // Create a queue of integers

    // Insert elements into the queue
    q.push(10); // Queue: 10
    q.push(20); // Queue: 10 20
    q.push(30); // Queue: 10 20 30

    // Access the front and back elements
    cout << "Front element: " << q.front() << endl; // Output: 10
    cout << "Back element: " << q.back() << endl;   // Output: 30

    // Remove the front element
    q.pop(); // Removes 10, Queue: 20 30

    // Check if queue is empty
    if(q.empty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }

    // Print size of the queue
    cout << "Queue size: " << q.size() << endl; // Output: 2

    return 0;
}

/*
5. Notes:
   - Queue STL does not allow direct access to elements (no operator[]).
   - Only front and back elements can be accessed.
   - Useful for BFS, scheduling, and other FIFO tasks.
   - All operations are O(1) (amortized constant time)
*/
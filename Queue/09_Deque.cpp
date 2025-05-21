/*
Deque (Double-Ended Queue) - Simple Notes

1. Definition:
   - A Deque (Double-Ended Queue) is a linear data structure that allows insertion and deletion of elements from both ends (front and rear).

2. Operations:
   - push_front(x): Insert element x at the front.
   - push_back(x): Insert element x at the rear.
   - pop_front(): Remove element from the front.
   - pop_back(): Remove element from the rear.
   - front(): Access the front element.
   - back(): Access the rear element.
   - empty(): Check if the deque is empty.
   - size(): Get the number of elements.

3. Applications:
   - Implementing both stacks and queues.
   - Sliding window problems.
   - Palindrome checking.
   - Undo operations in editors.

4. Implementation:
   - Can be implemented using arrays or linked lists.
   - C++ STL provides <deque> container with all standard operations.

5. Time Complexity:
   - All insertion and deletion operations at both ends are O(1).
*/

#include<iostream>
#include<deque>
using namespace std;

int main() {
    deque<int> dq;

    // Insertion
    dq.push_back(10);   // Inserts 10 at the back -> [10]
    dq.push_front(20);  // Inserts 20 at the front -> [20, 10]

    // Accessing
    cout << "Front: " << dq.front() << endl;   // 20
    cout << "Back: " << dq.back() << endl;     // 10

    // Removal
    dq.pop_front();     // Removes front -> [10]
    dq.pop_back();      // Removes back -> []

    // Size check
    dq.push_back(5);
    dq.push_back(15);
    cout << "Size: " << dq.size() << endl;     // 2

    // Random access like array
    cout << "First element: " << dq[0] << endl;  // 5
    cout << "Second element: " << dq.at(1) << endl;  // 15

    // Clear all elements
    dq.clear();

    // Check if empty
    if (dq.empty()) cout << "Deque is empty!" << endl;

    return 0;
}
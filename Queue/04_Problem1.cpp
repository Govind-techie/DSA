/*
Problem Statement: Implement a Queue using Two Stacks

Description:
- Design a class to implement a queue using two stacks.
- The queue should support the following operations:
    1. push(x): Insert element x at the end of the queue.
    2. pop(): Remove the element from the front of the queue.
    3. front(): Return the front element of the queue.
    4. empty(): Return true if the queue is empty, otherwise false.

Constraints:
- Use only standard stack operations (push, pop, top, empty).
- Do not use any STL queue or deque.

Example:
Input:

push(1)
push(2)
front() // returns 1
pop()
front() // returns 2
empty() // returns false

Output:
1
2
false
*/

#include<iostream>
#include<stack>
using namespace std;

// Implementing a Queue using two Stacks (s1 and s2)
class Queue {
    stack<int> s1; // Main stack where front of queue is always on top
    stack<int> s2; // Helper stack used during push operation

public:

    // Function to insert an element into the queue
    void push(int val) {
        // Step 1: Move all elements from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Step 2: Push the new element onto s1
        s1.push(val);

        // Step 3: Move everything back from s2 to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }

        // Now, the front of the queue is at the top of s1
    }

    // Function to remove the front element of the queue
    void pop() {
        // Since front is on top of s1, just pop
        if (!s1.empty())
            s1.pop();
    }

    // Function to get the front element of the queue
    int front() {
        // Return the top element of s1 which is front of queue
        if (!s1.empty()){
            return s1.top();
        }
        return -1; // Return -1 if queue is empty (edge case)
    }
};

int main() {
    Queue q;

    // Insert elements
    q.push(1);
    q.push(2);
    q.push(3); // Queue is now: 1 (front), 2, 3

    q.pop();   // Removes 1

    // Should print 2 (new front)
    cout << "Front : " << q.front() << endl;

    return 0;
}
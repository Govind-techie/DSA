/*
Problem Statement: Implement a Stack using Two Queues

Description:
- Design a class to implement a stack using two queues.
- The stack should support the following operations:
    1. push(x): Insert element x onto the stack.
    2. pop(): Remove the element on top of the stack.
    3. top(): Return the top element of the stack.
    4. empty(): Return true if the stack is empty, otherwise false.

Constraints:
- Use only standard queue operations (push, pop, front, empty).
- Do not use any STL stack or deque.

Example:
Input:
    push(1)
    push(2)
    top()    // returns 2
    pop()
    top()    // returns 1
    empty()  // returns false

Output:
    2
    1
    false
*/

#include <iostream>
#include <queue>
using namespace std;

// Template Stack using two queues (Pop => O(n))
template <typename T>
class Stack { 
    queue<T> q1; // Main queue
    queue<T> q2; // Helper queue

public:
    // Push element on top of the stack - cheap
    void push(T val) {
        q1.push(val);
    }

    // Remove the element on top of the stack - costly
    void pop() {
        if (empty()) {
            cout << "Stack is EMPTY\n";
            return;
        }
        // Move all elements except the last from q1 to q2
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        // Pop the last element from q1 (top of stack)
        q1.pop();

        // Swap q1 and q2 to restore the main queue
        swap(q1, q2);
    }

    // Return the top element of the stack - costly operation similar to pop but without removing
    T top() {
        if (empty()) {
            cout << "Stack is EMPTY\n";
            return T();
        }

        // Move all except last element to q2
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        // Last element is top of stack
        T topElement = q1.front();

        // Push it to q2 (since we only peeked)
        q2.push(topElement);
        q1.pop();

        // Swap q1 and q2 back
        swap(q1, q2);

        return topElement;
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    Stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl; // 30

    st.pop(); // removes 30

    cout << "Top after pop: " << st.top() << endl; // 20

    cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << endl; // No

    return 0;
}
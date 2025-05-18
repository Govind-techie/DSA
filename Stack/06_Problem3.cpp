/*
Problem: Reverse a Stack

Given a stack of integers, reverse the stack using only standard stack operations.

Example:
Input:  Stack = [3, 2, 1] (top = 1)
Output: Stack = [1, 2, 3] (top = 3)

Constraints:
- You can only use standard stack operations: push, pop, top, and isEmpty.
- Do not use any additional data structures (like arrays or queues).
- The order of elements in the stack should be completely reversed.
*/

#include <iostream>
#include <stack>
using namespace std;

// Step 1: Push an element at the bottom of the stack
// This uses recursion to reach bottom and insert the element
void pushAtBottom(stack<int>& st, int val) { // Time Complexity -> O(n)
    if (st.empty()) {
        st.push(val);  // base case: insert when stack is empty
        return;
    }

    int temp = st.top();  // store top element
    st.pop();             // remove it
    pushAtBottom(st, val); // recursive call to go deeper
    st.push(temp);        // push stored element back after val is inserted
}

// Step 2: Reverse the stack using recursion and pushAtBottom()
// Recursively pop all elements, then insert them back in reverse
void reverseStack(stack<int>& st) { // Time Complexity -> O(n)
    if (st.empty()) return;  // base case

    int temp = st.top();
    st.pop();
    reverseStack(st);       // reverse smaller stack
    pushAtBottom(st, temp); // insert current element at bottom
}

int main() {
    stack<int> st;

    // Pushing elements in stack
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);  // Stack: 4(top), 3, 2, 1(bottom)

    // Reverse the stack
    reverseStack(st);  // Stack becomes: 1(top), 2, 3, 4(bottom)

    // Print reversed stack
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
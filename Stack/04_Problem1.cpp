/*
Problem: Push Element to Bottom of Stack

Given a stack of integers and an integer value X, write a function to insert X at the bottom of the stack.

Example:
Input: Stack = [3, 2, 1] (top = 1), X = 5
Output: Stack = [5, 3, 2, 1] (top = 1)

Note:
- You can only use standard stack operations: push, pop, top, and isEmpty.
- Do not use any additional data structures (like arrays or queues).
- The order of the other elements must remain unchanged.
*/

#include<iostream>
#include<stack>
using namespace std;

// Function to insert an element at the bottom of the stack
void pushToBottom(stack<int>& st, int val) { // Time Complexity -> O(n)
    if (st.empty()){
        st.push(val); // push at top = push at bottom
        return;
    }
    int temp = st.top();
    st.pop();
    pushToBottom(st,val);
    st.push(temp);
}

// NOTE: In C++, STL containers are passed by value to functions by default.
// This means a copy of the container is made, and changes inside the function 
// won't affect the original container.
// To modify the original container, pass it by reference using '&'.

int main() {
    stack<int> st;

    // Pushing some initial elements into the stack
    st.push(1);
    st.push(2);
    st.push(3); // Stack from top to bottom: 3, 2, 1

    int val = 0; // Value to insert at the bottom
    pushToBottom(st, val); // After insertion: Stack should be 3, 2, 1, 0

    // Display the stack after pushToBottom
    cout << "Stack after pushing " << val << " to the bottom:" << endl;
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
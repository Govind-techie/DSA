/*
Stack STL (Standard Template Library)

The C++ STL provides a built-in stack container adapter in the <stack> header.

Key Features:
- Implements stack using underlying containers (deque by default, or vector/list).
- Follows LIFO (Last In, First Out) principle.
- Provides all basic stack operations with efficient time complexity.

Syntax:
#include <stack>
stack<int> s; // Creates a stack of integers

Common Functions:
- push(x): Adds element x to the top of the stack.
- pop(): Removes the top element.
- top(): Returns the top element (does not remove).
- empty(): Returns true if the stack is empty.
- size(): Returns the number of elements in the stack.

Example:
stack<int> s;
s.push(10);
s.push(20);
cout << s.top(); // Outputs 20
s.pop();
cout << s.top(); // Outputs 10

Notes:
- STL stack does not allow direct access to elements other than the top.
- Underlying container can be changed (e.g., stack<int, vector<int>> s;).
- STL stack is safe, efficient, and widely used for most stack use-cases.
*/

#include<iostream>
#include<stack> // Include the stack STL
using namespace std;

int main() {
    // Stack Declaration
    stack<int> s; // Creates a stack to store integers

    // Push Operation: Adds elements to the top of the stack
    s.push(10);
    s.push(20);
    s.push(30); // Stack now: 30 (top), 20, 10

    // Top Operation: Returns the element at the top without removing it
    cout << "Top element: " << s.top() << endl; // Output: 30

    // Pop Operation: Removes the top element
    s.pop(); // Removes 30
    cout << "Top after pop: " << s.top() << endl; // Output: 20

    // Check if the stack is empty
    if (s.empty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is NOT empty" << endl;
    }

    // Size of the stack
    cout << "Size of stack: " << s.size() << endl; // Output: 2

    // Displaying and clearing the stack
    cout << "Stack elements (from top to bottom): ";
    while (!s.empty()) {
        cout << s.top() << " "; // Access the top element
        s.pop();                // Remove the top element
    }
    cout << endl;

    return 0;
}
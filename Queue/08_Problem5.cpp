/*
Problem Statement: Reverse a Queue

Description:
- Given a queue, reverse the order of its elements using standard queue operations.
- You may use a stack as an auxiliary data structure.

Input:
- A queue containing N elements.

Output:
- The same queue with its elements in reversed order.

Example:
Input:  1 2 3 4 5
Output: 5 4 3 2 1
*/

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

// Function to reverse the elements of a queue
queue<int> reverse(queue<int>& q){
    stack<int> s; // Stack to hold elements temporarily (LIFO)

    while (!q.empty()){ // Transfer all elements from queue to stack
        s.push(q.front()); // Push front element of queue into stack
        q.pop(); // Remove front element from queue
    }

    while (!s.empty()){ // Transfer all elements back from stack to queue
        q.push(s.top()); // Push top element of stack into queue
        s.pop(); // Remove top element from stack
    }

    return q; // Queue is now reversed
}

int main() {
    queue<int> q;

    q.push(1); // Push elements into the queue
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    reverse(q); // Reverse the queue using stack

    while (!q.empty()) {
        cout << q.front() << " "; // Print front element
        q.pop(); // Remove printed element
    }
    cout << endl;

    return 0;
}
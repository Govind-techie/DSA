/*
Stack Using Deque -> (IMPLEMENTATION)

1. A deque (double-ended queue) allows insertion and deletion at both ends.

2. To implement a stack using a deque:
   - Use push_back(x) to push (add at top).
   - Use pop_back() to pop (remove from top).
   - back() gives the top element.
   - empty() checks if the stack is empty.

3. All operations are O(1) using STL deque.

4. This approach is efficient and easy with C++ STL <deque>.
*/

#include<iostream>
#include<deque>
using namespace std;

template<class T>
class Stack {
    deque<T>dq; // Using deque to implement stack

public:
    void push(T val){ // Push element to the top of stack
        dq.push_back(val);
    }

    void pop(){ // Remove top element from stack
        if (empty()){ // Check if stack is empty before popping
            cout << "Stack is EMPTY\n";
            return;
        }
        dq.pop_back();
    }

    T top(){ // Get the top element of the stack
        if (empty()){ // Handle empty case
            cout << "Stack is EMPTY\n";
            return T(); // Return default value of type T
        }
        return dq.back(); // Return last pushed element
    }

    bool empty(){ // Check if stack is empty
        return dq.empty();
    }
};

int main() {
    Stack<int> s; // Create a stack of integers

    s.push(10); // Push elements
    s.push(20);
    s.push(30);

    while (!s.empty()) { // Keep popping until stack becomes empty
        cout << s.top() << " "; // Print top element
        s.pop(); // Remove top element
    }

    cout << endl; // Print newline after all elements are popped

    return 0;
}
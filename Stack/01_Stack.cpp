/*
Stack Data Sturcture

A Stack is a linear data structure that follows the Last In, First Out (LIFO) principle.

Key Concepts:
- LIFO (Last In, First Out): The last element added (pushed) to the stack is the first one to be removed (popped).
- Only one end is used for both insertion (push) and deletion (pop), called the "top" of the stack.

Basic Operations:
1. Push: Add an element to the top of the stack.
2. Pop: Remove the element from the top of the stack.
3. Peek/Top: View the element at the top without removing it.
4. isEmpty: Check if the stack is empty.
5. isFull: (For fixed-size stacks) Check if the stack is full.

Representation:
- Can be implemented using arrays or linked lists.
- In arrays, the stack has a fixed size.
- In linked lists, the stack can grow dynamically.

Visualization:
[Bottom] 1 2 3 4 5 [Top]
Push(6) → [Bottom] 1 2 3 4 5 6 [Top]
Pop()   → [Bottom] 1 2 3 4 5 [Top]

Use Cases:
- Function call/return (call stack)
- Undo/Redo operations in editors
- Expression evaluation (postfix, prefix)
- Syntax parsing (compilers)
- Backtracking algorithms (maze, recursion)

Notes:
- Only the top element is accessible at any time.
- Stacks are simple but powerful for managing order and history.
- Overflow: Trying to push when the stack is full (in array implementation).
- Underflow: Trying to pop when the stack is empty.

Implementation:
1. Array-based Stack
   - Fixed size, fast access.
   - Simple to implement.
2. Linked List-based Stack
   - Dynamic size, no overflow unless memory is full.
   - Slightly more complex, but flexible.

Stack in STL:
- C++ STL provides a stack container in <stack> header.
- Syntax: stack<int> s;
- Functions: push(), pop(), top(), empty(), size()
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;



// Stack Implementation using Template Class and Vector

// Template class allows defining generic stack that works with any data type (int, float, string, etc.)
template<class dt> // 'dt' is a placeholder for any data type the user specifies
class Stack {
   public:
      vector<dt>stack; // Using vector to dynamically manage stack elements
      int top = 0;     // Top keeps track of current stack size (index of the top element + 1)

      // Push function to insert an element at the top of the stack
      void push(dt val){
         stack.push_back(val); // Add element to end of vector
         top++;                // Increase top index
      }

      // Pop function to remove the top element from the stack
      void pop(){
         if (isEmpty()){ // Check if the stack is already empty
            cout << "Stack is empty" << endl;
            return;
         }
         top--;            // Decrease top index
         stack.pop_back(); // Remove last element from vector
      }
      
      // Function to return the element at the top of the stack without removing it
      dt topIdx(){
         top = stack.size() - 1; // Update top to current top index (safe in case top was desynced)
         return stack[top];      // Return top element
      }

      // Function to check if the stack is empty
      bool isEmpty(){
         return stack.size() == 0; // Returns true if vector is empty, otherwise false
      }
};


// NOTE: A template class in C++ allows us to write generic code that works with any data type.
// When implementing a stack, using a template class avoids writing separate code for int, float, string, etc.
// Vector is used here for dynamic memory management (no need to define stack size in advance)

int main(){
   Stack<string>s; // Creating a stack of strings using our template stack class

   // Pushing elements onto the stack
   s.push("Relearn");
   s.push("Unlearn");
   s.push("Learn");

   // Displaying stack elements in LIFO order (Last In First Out)
   while (!s.isEmpty()){
      cout << s.topIdx() << " "; // Print top element
      s.pop();                   // Remove top element
   } 
   cout << endl;
   return 0;
}
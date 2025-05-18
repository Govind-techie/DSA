/*
Stack Implementation

A Stack can be implemented in two main ways:

1. Array-based Stack
   - Uses a fixed-size array to store elements.
   - Fast access and simple logic.
   - Limitation: Maximum size is fixed at creation (can cause overflow).

2. Linked List-based Stack
   - Uses a linked list where each node represents a stack element.
   - Dynamic size: Grows and shrinks as needed (no fixed limit except system memory).
   - No overflow unless memory is full.
   - Each node contains:
     • Data: The value stored.
     • Pointer: Link to the next node (the one below in the stack).

Key Points:
- In both implementations, all stack operations (push, pop, top/peek, isEmpty) are O(1) time.
- Only the "top" element is accessible for push/pop/peek.
- Array-based stacks are simple and fast, but not flexible in size.
- Linked list-based stacks are flexible, but use extra memory for pointers.

Visualization (Linked List Stack):
[Top] -> [Node3] -> [Node2] -> [Node1] -> NULL

Push: Add a new node at the head (top).
Pop: Remove the node at the head (top).

When to use which?
- Use array-based stack when maximum size is known and memory is not a concern.
- Use linked list-based stack for dynamic size and frequent insertions/removals.

STL Note:
- C++ STL stack is usually implemented using deque or vector (not linked list).
*/

#include<iostream>
using namespace std;

// ------------------------------
// Stack Implementation using Linked List with Template Class
// ------------------------------

// Node class template for Linked List
template<class dt>
class Node {
    public:
        dt data;       // Data of generic type
        Node* next;    // Pointer to the next node

        // Constructor to initialize node
        Node(dt val){
            data = val;
            next = NULL;
        }
};

// Stack class template using Linked List
template<class dt>
class Stack {
    Node<dt>* head; // Pointer to the top node of the stack (linked list head)

    public:
        // Constructor to initialize empty stack
        Stack (){
            head = NULL;
        }

        // PUSH operation: Inserts element at the top of the stack
        // Time complexity: O(1)
        void push(dt val){
            Node<dt>* newNode = new Node<dt>(val); // Create new node
            newNode->next = head; // Point new node to current head
            head = newNode;       // Update head to new node (top of stack)
        }

        // POP operation: Removes top element of the stack
        // Time complexity: O(1)
        void pop(){
            if (head == NULL) return; // Safety check (optional)
            Node<dt>* temp = head;    // Store current head
            head = head->next;        // Move head to next node
            temp->next = NULL;        // Break the link for safety
            delete temp;              // Free memory
        }


        // TOP operation: Returns top element without removing it
        dt top(){
            return head->data; // Return data at head (top)
        }

        // isEmpty operation: Checks if the stack is empty
        bool isEmpty(){
            return head == NULL;
        }

};

int main(){
   Stack<int> s; // Creating a stack of integers using the template class

   // Pushing elements onto the stack
   s.push(3);
   s.push(2);
   s.push(1);  // Stack now: 1 (top), 2, 3

   // Displaying stack elements in LIFO order (Last In First Out)
   while (!s.isEmpty()){
      cout << s.top() << " "; // Print top element
      s.pop();                // Remove top element
   } 
   cout << endl;

   return 0;
}
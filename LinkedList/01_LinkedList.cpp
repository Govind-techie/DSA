/*
Linked List

A Linked List is a data structure where elements (called nodes) are connected one after another using pointers.

Each node has two parts:
1. Data: The value stored in the node.
2. Pointer: A link to the next node in the list.

NOTE:
- The first node is called the head.
- The last node points to NULL, meaning the end of the list.
- Unlike arrays, linked lists don’t need memory in a single block. So they are flexible in size.
- Insertion and deletion are easy and fast, but accessing elements is slower because we have to move one by one.
- Types of Linked Lists:
  → Singly Linked List: One direction (next pointer only).
  → Doubly Linked List: Two directions (next and previous pointers).
- Used in:
  → Stacks and Queues
  → Graphs (adjacency list)
  → When dynamic memory allocation is needed

  */
 
 /*
Representation:
[1] -> [2] -> [3] -> [4] -> NULL
 
([]) => node
(->) => pointer to the next node

KEY NOTES:
    1.	Linked List nodes are not stored in contiguous memory like arrays. Each node can be anywhere in memory and is connected using pointers.
    2.	Each node stores 2 parts:
        • Data: The actual value stored (like a number or character).
        • Pointer: The address of the next node, used to link the list.
 
    Important:
    The last node of a linked list stores NULL in its pointer part, which means it does not point to any other node. This indicates the end of the list.
 
    Head Pointer:
    The head pointer points to the first node of the linked list. It is used to access or traverse the entire list.

    Tail Pointer:
    The tail pointer stores the address of the last node in the linked list.It helps in accessing the end of the list quickly, especially useful for insertions at the end.

    Node Access in Linked List:
    Unlike arrays, we cannot directly access elements in a linked list.
    To get a node’s data, we must start from the head pointer and traverse node by node until we reach the desired position.
*/

/*
LinkedList Implementation:

1. STL (Standard Template Library)
   - Uses built-in 'list' container from <list> header.
   - Easy to use, with ready-made functions like push_back(), pop_front(), etc.
   - Syntax: list<int> myList;

2. Classes
   - Custom implementation using user-defined Node and LinkedList classes.
   - Gives full control over how nodes are created, linked, and managed.
   - Good for learning and understanding internal working of linked lists.
*/

// Class Implementation Of LinkedList:

class Node {
    // Node is a user-defined data type that stores two things:
    int data;       // 1. The value/data stored in the node
    Node* next;     // 2. A pointer that stores the address of the next node

public:
    Node(int val) {     // Constructor to initialize the node with a value
        data = val;     // Store the given value in the data part
        next = nullptr; // Initially, next points to NULL (no next node yet)
    }
};

class List { // List represents the LinkedList made of multiple Node objects
    Node* head; // Head pointer points to the first node of the linked list
    Node* tail; // Tail pointer points to the last node of the linked list

public:
    List() {         // Constructor initializes an empty linked list
        head = nullptr; // Initially, no node exists, so head is NULL
        tail = nullptr; // Tail is also NULL as list is empty
    }
};

#include<iostream>
using namespace std;

int main(){
    List linkedList();
    return 0;
}
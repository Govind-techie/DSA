/*
Notes on Doubly Linked List:

1. Definition:
   - A doubly linked list is a type of linked list in which each node contains three parts:
     - Data: The value stored in the node.
     - Next pointer: Points to the next node in the list.
     - Previous pointer: Points to the previous node in the list.

2. Features:
   - Allows traversal in both forward and backward directions.
   - More flexible than singly linked lists for certain operations (like deletion).
   - Each node requires extra memory for the previous pointer.

3. Basic Operations:
   - Insertion: Can be done at the beginning, end, or any position.
   - Deletion: Can be done from the beginning, end, or any position.
   - Traversal: Can move forward (using next) or backward (using prev).

4. Use Cases:
   - Implementing undo/redo functionality.
   - Browser history navigation.
   - Complex data structures like Fibonacci heaps.

5. Drawbacks:
   - Uses more memory due to the extra pointer.
   - Slightly more complex to implement than singly linked lists.

6. Example Node Structure:
   class Node {
   public:
       int data;
       Node* next;
       Node* prev;
       Node(int val) {
           data = val;
           next = nullptr;
           prev = nullptr;
       }
   };
*/

#include<iostream>
using namespace std;

// Node structure for a doubly linked list
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

// Doubly Linked List implementation
class DoublyList {
public:
    Node* head;
    Node* tail;

    DoublyList() {
        head = tail = NULL;
    }

    // Insert node at front of list
    void push_front(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode; // first node
        } else {
            newNode->next = head;  // newNode points to current head
            head->prev = newNode;  // current head points back to newNode
            head = newNode;        // head moves to newNode
        }
    }

    // Insert node at end of list
    void push_back(int val) {
        Node* newNode = new Node(val);

        if (tail == NULL) {
            head = tail = newNode; // first node
        } else {
            tail->next = newNode;  // current tail points to newNode
            newNode->prev = tail;  // newNode points back to current tail
            tail = newNode;        // tail moves to newNode
        }
    }

    // Remove node from front
    void pop_front() {
        if (head == NULL) return;

        Node* temp = head;
        head = head->next;

        if (head != NULL) {
            head->prev = NULL;     // remove backward link
        } else {
            tail = NULL;           // list became empty
        }

        delete temp;
    }

    // Remove node from end
    void pop_back() {
        if (tail == NULL) return;

        Node* temp = tail;
        tail = tail->prev;

        if (tail != NULL) {
            tail->next = NULL;     // remove forward link
        } else {
            head = NULL;           // list became empty
        }

        delete temp;
    }

    // Print the list from head to tail
    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " <=> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    DoublyList dbll;

    dbll.push_front(4);
    dbll.push_front(3);
    dbll.push_front(2);
    dbll.push_front(1);
    dbll.printList();  // 1 <=> 2 <=> 3 <=> 4 <=> NULL

    dbll.pop_front();  // removes 1
    dbll.printList();  // 2 <=> 3 <=> 4 <=> NULL

    dbll.push_back(5);
    dbll.push_back(6);
    dbll.printList();  // 2 <=> 3 <=> 4 <=> 5 <=> 6 <=> NULL

    dbll.pop_back();   // removes 6
    dbll.printList();  // 2 <=> 3 <=> 4 <=> 5 <=> NULL

    return 0;
}
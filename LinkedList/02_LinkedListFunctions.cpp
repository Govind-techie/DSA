/*
Common Linked List Functions:

1. push_front(value):
   - Adds a new node with the given value at the beginning of the list.
   - Updates the head pointer.

2. push_back(value):
   - Adds a new node with the given value at the end of the list.
   - Updates the tail pointer.

3. insert(value, position):
   - Inserts a node with the given value at a specific position (0-based index).
   - Maintains the link structure.

4. pop_front():
   - Removes the first node of the list.
   - Updates the head pointer.

5. pop_back():
   - Removes the last node of the list.
   - Updates the tail pointer.
*/

#include <iostream>
using namespace std;

// Represents a single node in the linked list
class Node {
public:
    int data;     // Value stored in the node
    Node* next;   // Pointer to the next node

    // Constructor to initialize node with a value
    Node(int val) {
        data = val;
        next = NULL;
    }

    // Destructor: deletes the rest of the linked list recursively
    ~Node() {
        if (next != NULL) {
            delete next;
            next = NULL;
        }
    }
};

// Singly linked list class
class List {
    Node* head; // Points to the first node
    Node* tail; // Points to the last node

public:
    // Constructor: Initializes an empty list
    List() {
        head = NULL;
        tail = NULL;
    }

    // Destructor: Starts recursive deletion from head
    ~List() {
        if (head != NULL) {
            delete head;
            head = NULL;
        }
    }

    // Adds a node at the front of the list
    void push_front(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode; // First node case
        } else {
            newNode->next = head;  // Link new node to existing head
            head = newNode;        // Update head to the new node
        }
    }

    // Adds a node at the end of the list
    void push_back(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode; // First node case
        } else {
            tail->next = newNode;  // Link current tail to new node
            tail = newNode;        // Update tail
        }
    }

    // Inserts a node at a specific position (0-based index)
    void insert(int val, int pos) {
        // If inserting at the front
        if (pos == 0) {
            push_front(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;

        // Traverse to the (pos-1)th node
        for (int i = 0; i < pos - 1; i++) {
            if (temp == NULL) {
                cout << "Position is invalid" << endl;
                return;
            }
            temp = temp->next;
        }

        // Insert the new node in between
        newNode->next = temp->next;
        temp->next = newNode;

        // Update tail if inserted at the end
        if (newNode->next == NULL) {
            tail = newNode;
        }
    }

    // Prints the entire list
    void printList() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

    // Removes the first node from the list
    void pop_front() {
        if (head == NULL) {
            cout << "Linked list is empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        temp->next = NULL; // Break the link to avoid recursive deletion
        delete temp;

        // If list becomes empty
        if (head == NULL) {
            tail = NULL;
        }
    }

    // Removes the last node from the list
    void pop_back() {
        if (head == NULL) {
            cout << "Linked list is empty\n";
            return;
        }

        // If only one node is present
        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }

        Node* temp = head;

        // Traverse to second-last node
        while (temp->next != tail) {
            temp = temp->next;
        }

        delete tail;     // Delete last node
        temp->next = NULL;
        tail = temp;     // Update tail
    }
};

int main() {
    List ll;

    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printList();  // Output: 1->2->3->NULL

    ll.push_back(4);
    ll.push_back(5);
    ll.insert(100, 2); // Insert at position 2
    ll.pop_front();    // Remove first node
    ll.printList();    // Output: 2->100->3->4->5->NULL

    ll.pop_back();     // Remove last node
    ll.printList();    // Output: 2->100->3->4->NULL

    return 0;
}
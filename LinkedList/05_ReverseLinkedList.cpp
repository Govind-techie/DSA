/*
Reversing a Linked List:

1. Purpose:
   - To reverse the order of nodes in a linked list.
   - The head of the list becomes the tail, and the tail becomes the head.

2. Steps:
   - Initialize three pointers:
     - prev to NULL (to keep track of the previous node).
     - current to the head (to traverse the list).
     - next to NULL (to temporarily store the next node).
   - Traverse the list:
     - Store the next node in next (i.e., next = current->next).
     - Reverse the link of the current node (i.e., current->next = prev).
     - Move prev to the current node and current to the next node.
   - After the loop, set the head to prev (the new head of the reversed list).

3. Complexity:
   - Time Complexity: O(n), where n is the number of nodes in the linked list.
   - Space Complexity: O(1), as no extra space is used.
*/

#include <iostream>
using namespace std;

// Node class representing a single node in the linked list
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// LinkedList class with basic insertion function
class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    // Insert a new node at the end of the list
    void insert(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // Print the linked list
    void printList() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

    void reverse(){
        Node* curr = head;
        Node* prev = NULL;

        while(curr != NULL){
            Node* next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        head = prev;
    }
};

int main() {
    LinkedList ll;

    // Creating a linked list: 10 -> 20 -> 30 -> 40 -> NULL
    ll.insert(10);
    ll.insert(20);
    ll.insert(30);
    ll.insert(40);

    cout << "Original Linked List: ";
    ll.printList();

    
    ll.reverse();

    cout << "Reversed Linked List: ";
    ll.printList();

    return 0;
}
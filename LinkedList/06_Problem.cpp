/*
Problem: Find and Remove the Nth Node from the End of a Linked List

1. Purpose:
   - To locate the nth node from the end of the linked list.
   - Remove this node from the list while maintaining the structure of the list.

2. Steps:
   - Use the two-pointer technique:
     - Initialize two pointers, `fast` and `slow`, both pointing to the head of the list.
     - Move the `fast` pointer n steps ahead.
     - Then, move both `fast` and `slow` pointers one step at a time until `fast` reaches the end of the list.
   - The `slow` pointer will now point to the node just before the nth node from the end.
   - Adjust the links to remove the nth node from the list.

3. Edge Cases:
   - If the list is empty, return without any operation.
   - If n is greater than the length of the list, handle it gracefully.
   - If the nth node from the end is the head, update the head pointer.

4. Complexity:
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

    int size(){
        Node* temp = head;
        int size = 0;
        while (temp != NULL){
            temp = temp->next;
            size++;
        }
        return size;
    }

    void removeNthFromEnd(int n) {
        Node* prev = head;
        int sz = size();
        for (int i = 1 ; i < (sz-n) ; i++){
            prev = prev->next;
        }
        prev->next = prev->next->next;
    }
};

int main() {
    LinkedList ll;

    // Creating a linked list: 10 -> 20 -> 30 -> 40 -> 50 -> NULL
    ll.insert(10);
    ll.insert(20);
    ll.insert(30);
    ll.insert(40);
    ll.insert(50);

    cout << "Original Linked List: ";
    ll.printList();

    int n = 2;  // Remove the 2nd node from the end (should remove 40)

    ll.removeNthFromEnd(n);

    cout << "Linked List after removing " << n << "th node from the end: ";
    ll.printList();

    return 0;
}
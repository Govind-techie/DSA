/*
Iterative Search in a Linked List:

1. Purpose:
   - To find whether a given key exists in the linked list.
   - Traverse the list node by node and compare each node's data with the key.

2. Steps:
   - Start from the head of the linked list.
   - Traverse the list using a loop until the end (i.e., until the current node is NULL).
   - At each node:
     - Check if the node's data matches the key.
     - If a match is found, return true (or the position of the key).
   - If the loop ends without finding the key, return false (or indicate that the key is not present).

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

    int search(int key){
        Node* temp = head;
        int idx = 0;
        while(temp != NULL){
            if (temp->data == key){
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }

};

int main() {
    LinkedList ll;

    // Creating a linked list: 10 -> 20 -> 30 -> 40 -> NULL
    ll.insert(10);
    ll.insert(20);
    ll.insert(30);
    ll.insert(40);

    ll.printList();

    int key = 30;
    int idx = ll.search(key);
    
    if (idx != -1) {
        cout << key << " found in the list at index : " << idx << endl;
    } else {
        cout << key << " not found in the list" << endl;
    }

    return 0;
}
/*
Recursive Search in a Linked List:

1. Purpose:
   - To find whether a given key exists in the linked list using recursion.
   - Recursively traverse the list and compare each node's data with the key.

2. Steps:
   - Base Case:
     - If the current node is NULL, the key is not present in the list. Return false.
     - If the current node's data matches the key, return true (or the position of the key).
   - Recursive Case:
     - Call the function recursively for the next node in the list.

3. Complexity:
   - Time Complexity: O(n), where n is the number of nodes in the linked list.
   - Space Complexity: O(n), due to the recursive call stack.
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

    int helper(Node* temp, int key){
        if (temp == NULL){
            return -1;
        }

        if (temp->data == key){
            return 0;
        }

        int idx = helper(temp->next,key);

        if (idx == -1){
            return -1;
        }

        return idx+1;
   }
    int search(int key){
        return helper(head,key);
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

    int index = ll.search(key);

    if (index != -1) {
        cout << key << " found at index " << index << " in the list." << endl;
    } else {
        cout << key << " not found in the list." << endl;
    }

    return 0;
}
/*
Problem: Detect Cycle (Loop) in a Linked List

1. Purpose:
   - To determine whether a linked list contains a cycle (loop).
   - A cycle exists if any node in the list points back to a previous node, causing an infinite loop.

2. Approach:
   - Use Floyd’s Cycle Detection Algorithm (Tortoise and Hare Algorithm):
     - Initialize two pointers, slow and fast, both at the head of the list.
     - Move slow by one step and fast by two steps in each iteration.
     - If there is a cycle, the fast pointer will eventually meet the slow pointer.
     - If fast reaches the end (NULL), there is no cycle.

3. Complexity:
   - Time Complexity: O(n), where n is the number of nodes in the linked list.
   - Space Complexity: O(1), as no extra space is used.

4. Algorithm: Fast and slow pointer.
*/

#include <iostream>
using namespace std;

// Node definition
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// LinkedList class
class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    // Insert a new node at the end
    void insert(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next)
            temp = temp->next;

        temp->next = newNode;
    }

    // Create a loop at position (0-based index)
    void createLoop(int position) {
        if (position < 0) return;

        Node* loopNode = head;
        for (int i = 0; i < position && loopNode; i++)
            loopNode = loopNode->next;

        Node* temp = head;
        while (temp->next)
            temp = temp->next;

        temp->next = loopNode;
    }

    // Detect loop in the linked list
    bool detectLoop() {
        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL){
            slow = slow->next; // +1
            fast = fast->next->next; // +2
            if(slow == fast){
                return true;
                break;
            }
        }

        return false;
    }
};

int main() {
    LinkedList list;

    // Insert elements
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.insert(50);

    // Create a loop (50 -> 30)
    list.createLoop(2);

    // Detect loop
    if (list.detectLoop()) {
        cout << "Loop detected!" << endl;
    } else {
        cout << "No loop found." << endl;
    }

    return 0;
}
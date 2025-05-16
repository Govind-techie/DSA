/*
Problem: Remove Cycle (Loop) in a Linked List

1. Purpose:
   - To remove a cycle (loop) from a linked list, if it exists.
   - After removal, the linked list should become linear (no cycles).

2. Approach:
   - First, detect if a cycle exists using Floyd’s Cycle Detection Algorithm (Tortoise and Hare).
   - If a cycle is found:
     - Move one pointer to the head and keep the other at the meeting point.
     - Move both pointers one step at a time; the point where they meet is the start of the cycle.
     - Traverse to the node just before the start of the cycle and set its next pointer to NULL to break the loop.

3. Complexity:
   - Time Complexity: O(n), where n is the number of nodes in the linked list.
   - Space Complexity: O(1), as no extra space is used.
*/

#include <iostream>
using namespace std;

// Node class
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

    // Insert node at the end
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

    // Create a loop at a specific position (0-based index)
    void createLoop(int position) {
        if (position < 0) return;

        Node* loopNode = head;
        for (int i = 0; i < position && loopNode; i++) {
            loopNode = loopNode->next;
        }

        Node* temp = head;
        while (temp->next)
            temp = temp->next;

        temp->next = loopNode;
    }

// Function to remove loop (if exists)
void removeLoop() {
    Node* slow = head;
    Node* fast = head;
    bool isCycle = false;

    // Step 1: Detect loop using Floyd's cycle detection algorithm
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {  // Loop detected
            isCycle = true;
            break;
        }
    }

    // If no loop is found, just return
    if (!isCycle) return;

    // Step 2: Reset one pointer to head
    slow = head;

    // Special case: When the loop starts from the head itself (tail connects to head)
    if (slow == fast) {
        // Move fast till it reaches the node just before slow (i.e., last node of the loop)
        while (fast->next != slow) {
            fast = fast->next;
        }
        // Break the loop
        fast->next = NULL;
    } else {
        // General case: Loop starts somewhere in the middle

        // We need to find the node before the starting point of the loop
        Node* prev = fast; // will track the node just before the meeting point

        // Move both pointers one step at a time
        while (slow != fast) {
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }

        // Now fast and slow are at the starting point of the loop
        // prev is the last node inside the loop
        // Break the loop
        prev->next = NULL;
    }
}

    // Function to print the list (will not work if loop exists)
    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// Main function
int main() {
    LinkedList list;

    // Insert elements
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);

    // Create a loop (5 -> 2)
    list.createLoop(1);

    // Remove loop
    list.removeLoop();

    // Print list after removing loop
    list.printList();  // Should print normally if loop removed

    return 0;
}
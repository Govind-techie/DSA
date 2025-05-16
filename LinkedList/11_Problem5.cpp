/*
Problem: Zig Zag Linked List

1. Purpose:
   - To rearrange the nodes of a linked list in zig zag fashion.
   - The final order should be: a < b > c < d > e < f ... and so on.

2. Approach:
   - Traverse the linked list and swap data or links such that:
     - The first node is less than the second,
     - The second is greater than the third,
     - The third is less than the fourth, and so on, alternating the relation at each step.

3. Example:
   - Input: 1 -> 2 -> 3 -> 4 -> 5
   - Output: 1 -> 3 -> 2 -> 5 -> 4 (one possible zig zag arrangement)

4. Complexity:
   - Time Complexity: O(n), where n is the number of nodes in the linked list.
   - Space Complexity: O(1), as no extra space is used.
*/

#include <iostream>
using namespace std;

// Node definition
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// LinkedList class to wrap operations
class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    // Insert new node at the tail
    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    // Print linked list
    void print() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

Node* splitAtMid(Node* head){ // => Divide into two halves
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while (fast != NULL && fast->next != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (prev != NULL){
        prev->next = NULL;
    }
    return slow;
}

Node* reverse(Node* head){ // => reverse linkedList function
    Node* prev = NULL;
    Node* curr = head;
    while (curr != NULL){
        Node* next = curr->next;
        curr->next = prev;
        
        prev = curr;
        curr = next;
    }

    return prev;

}


Node* zigZag(Node* head) {
    Node* rightHead = splitAtMid(head);
    Node* rightHeadRev = reverse(rightHead);

    Node* left = head;
    Node* right = rightHeadRev;
    Node* tail = right;

    while (left != NULL && right != NULL){
        Node* nextLeft = left->next;
        Node* nextRight = right->next;

        left->next = right;
        right->next = nextLeft;

        tail = right;

        left = nextLeft;
        right = nextRight;
    }

    if (right != NULL){
        tail->next = right;
    }

    return head;
}

int main() {
    LinkedList ll;

    // Sample input
    ll.insertAtTail(1);
    ll.insertAtTail(4);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(5);

    cout << "Original List: ";
    ll.print();

    // Apply zig-zag transformation
    zigZag(ll.head);

    cout << "Zig-Zag List: ";
    ll.print();

    return 0;
}
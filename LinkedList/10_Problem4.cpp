/*
Problem: Merge Sort on a Linked List

1. Purpose:
   - To sort the elements of a linked list in ascending order using the merge sort algorithm.

2. Approach:
   - Recursively divide the linked list into two halves until each sublist contains a single node.
   - Merge the sorted sublists to produce new sorted lists until only one sorted list remains.

3. Key Steps:
   - Find the middle of the linked list to split it into two halves.
   - Recursively apply merge sort on both halves.
   - Merge the two sorted halves into a single sorted list.

4. Complexity:
   - Time Complexity: O(n log n), where n is the number of nodes in the linked list.
   - Space Complexity: O(log n) due to recursive call stack.
*/

#include<iostream>
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

// LinkedList class that wraps Node operations
class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    // Insert at tail
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

    // Print list
    void print() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// Merges two sorted linked lists and returns the head of the merged list
Node* merge(Node* left, Node* right) {
    LinkedList ans;
    Node* i = left;
    Node* j = right;

    // Compare elements from both lists and insert the smaller one into 'ans'
    while (i != NULL && j != NULL){
        if (i->data <= j->data){
            ans.insertAtTail(i->data);
            i = i->next;
        } else {
            ans.insertAtTail(j->data);
            j = j->next;
        }
    }

    // Append remaining elements of left list (if any)
    while (i != NULL){
        ans.insertAtTail(i->data);
        i = i->next;
    }

    // Append remaining elements of right list (if any)
    while (j != NULL){
        ans.insertAtTail(j->data);
        j = j->next;
    }

    return ans.head; // Return the head of the merged sorted list
}

// Splits the linked list into two halves and returns the head of the second half
Node* splitAtMid(Node* head){
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    // Use slow-fast pointer approach to find mid
    while (fast != NULL && fast->next != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // Break the list into two halves
    if (prev != NULL){
        prev->next = NULL;
    }

    return slow; // 'slow' is the head of the right half
}

// Recursive merge sort function for linked list
Node* mergeSort(Node* head) {
    // Base case: empty list or single node
    if (head == NULL || head->next == NULL) return head;

    // Split the list into two halves
    Node* rightHead = splitAtMid(head);

    // Recursively sort both halves
    Node* left = mergeSort(head);
    Node* right = mergeSort(rightHead);

    // Merge the sorted halves and return
    return merge(left, right);
}

int main() {
    LinkedList ll;

    // Sample input
    ll.insertAtTail(4);
    ll.insertAtTail(2);
    ll.insertAtTail(1);
    ll.insertAtTail(3);
    ll.insertAtTail(5);

    cout << "Original List: ";
    ll.print();

    // Sort the list
    ll.head = mergeSort(ll.head);

    cout << "Sorted List: ";
    ll.print();

    return 0;
}
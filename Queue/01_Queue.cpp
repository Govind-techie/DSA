/*
Queue Data Structure - Clean Notes

1. Definition:
   - A Queue is a linear data structure that follows First In First Out (FIFO) order.
   - The element inserted first is removed first.

2. Basic Operations:
   - Enqueue (push): Add an element to the rear.
   - Dequeue (pop): Remove an element from the front.
   - Front (peek): Get the front element without removing it.
   - isEmpty(): Check if the queue is empty.

3. Common Use Cases:
   - Process scheduling
   - Handling real-time data (e.g. server requests)
   - Breadth-First Search (BFS) in graphs

4. Types of Queues:
   - Simple Queue
   - Circular Queue
   - Deque (Double-Ended Queue)
   - Priority Queue

5. Implementation:
   - Array (fixed size)
   - Linked List (dynamic size, preferred for unlimited size queues)

6. Time Complexity (Linked List Implementation):
   - Enqueue (push): O(1)
   - Dequeue (pop): O(1)
   - Peek (front): O(1)
   - isEmpty(): O(1)
*/

#include<iostream>
using namespace std;

// Template class for Node
template<class dt>
class Node {
public:
    dt data; // Stores the value of the node
    Node<dt>* next; // Pointer to the next node

    // Constructor to initialize node with data
    Node(dt val){
        data = val;
        next = NULL;
    }
};

// Template class for Queue
template<class dt>
class Queue {
    Node<dt>* head; // Points to the front of the queue
    Node<dt>* tail; // Points to the end (rear) of the queue

public:
    // Constructor initializes anty queue
    Queue(){
        head = NULL;
        tail = NULL;
    }

    // Inserts a new element at the end of the queue
    void push(dt val){
        Node<dt>* newNode = new Node<dt>(val); // Create a new node
        if (head == NULL){ // If queue is empty, head and tail are same
            head = tail = newNode;
        }else{ // Else, insert at the tail
            tail->next = newNode;
            tail = newNode;
        }   
    }

    // Removes the front element from the queue
    void pop(){
        if(empty()){ // Check if queue is empty
            cout << "Queue is empty\n";
        }else{
            Node<dt>* temp = head; // Store current head
            head = temp->next; // Move head to next node
            temp->next = NULL; // Disconnect old head node
            delete temp; // Free memory
        }
    }

    // Returns the front element of the queue
    dt front(){
        return head->data;
    }

    // Prints all elements in the queue
    void printQueue(){
        Node<dt>* temp = head;
        while (temp != NULL){
            cout << temp->data << " "; // Print data
            temp = temp->next; // Move to next node
        } 
        cout << endl;
    }

    // Checks if the queue is empty
    bool empty(){
        return (head == NULL);
    }

};

// Driver function to test the Queue implementation
int main(){
    Queue<int> q; // Create a queue of integers

    q.push(1); // Insert 1
    q.push(2); // Insert 2
    q.push(3); // Insert 3
    
    q.printQueue(); // Output: 1 2 3
    cout << q.front() << endl; // Output: 1
    
    q.pop(); // Remove 1 from front
    q.printQueue(); // Output: 2 3
    
    cout << q.front() << endl; // Output: 2
    
    q.pop(); // Remove 2
    q.pop(); // Remove 3

    // Check if queue is empty
    if(q.empty()){
        cout << "Queue is empty\n"; // Output: Queue is empty
    }else{
        cout << "Queue is NOT empty\n";
    }

    q.pop(); // Try to remove from empty queue (shows warning)

    return 0;
}
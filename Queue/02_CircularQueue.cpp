/*
Circular Queue - Clean Notes

1. Definition:
   - A Circular Queue connects the end of the queue back to the front.
   - It allows efficient use of space by reusing empty spots created by dequeue operations.

2. Basic Operations:
   - Enqueue: Add element at rear.
   - Dequeue: Remove element from front.
   - Front: Access the front element without removing it.
   - isEmpty(): front == -1
   - isFull(): (rear + 1) % size == front

3. Key Concepts:
   - Use a fixed-size array with `front` and `rear` pointers.
   - Use modulo operation to wrap around when reaching the array's end.
   - Reset front and rear to -1 when queue becomes empty.

4. Applications:
   - Round Robin CPU scheduling
   - Circular buffers (audio/video streaming, network buffers)
   - Traffic light systems

5. Time Complexity:
   - Enqueue: O(1)
   - Dequeue: O(1)
   - Front: O(1)

6. Enqueue Example:
   if ((rear + 1) % size == front) {
       // Queue is full
   } else {
       if (front == -1) front = 0;
       rear = (rear + 1) % size;
       queue[rear] = value;
   }

7. Dequeue Example:
   if (front == -1) {
       // Queue is empty
   } else {
       int removed = queue[front];
       if (front == rear) {
           front = rear = -1;  // Queue becomes empty
       } else {
           front = (front + 1) % size;
       }
   }
*/

#include <iostream>
using namespace std;

// Template-based Circular Queue using Array
template <typename T>
class Queue {
    T* arr; // dynamic array
    int capacity; // max size of queue
    int currSize; // current number of elements
    int front, rear; // front and rear pointers

public:
    Queue(int capacity) {
        this->capacity = capacity;
        arr = new T[capacity];
        currSize = 0;
        front = rear = -1;
    }

    void push(T data) { // insert element at rear
        if (currSize == capacity) {
            cout << "Queue is FULL\n";
            return;
        }
        if (currSize == 0) front = 0;
        rear = (rear + 1) % capacity; // circular increment
        arr[rear] = data;
        currSize++;
    }

    void pop() { // remove front element
        if (empty()) {
            cout << "Queue is EMPTY\n";
            return;
        }
        front = (front + 1) % capacity; // circular increment
        currSize--;
    }

    T frontVal() { // return front element
        if (empty()) {
            cout << "Queue is EMPTY\n";
            return T(); // return default value
        }
        return arr[front];
    }

    bool empty() { // check if queue is empty
        return currSize == 0;
    }

    T rearVal() { // return rear element
    if (empty()) {
        cout << "Queue is EMPTY\n";
        return T(); // default value
    }
    return arr[rear];
    }
};

int main() {
    Queue<int> q(4); // create int queue with capacity 4

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5); // Queue is FULL

    cout << "Front = " << q.frontVal() << endl;
    cout << "Front = " << q.frontVal() << endl;

    q.pop(); // remove 1
    q.pop(); // remove 2

    cout << "After 2 pops, Front = " << q.frontVal() << endl;

    q.push(5); // reuse space
    cout << "Rear = " << q.rearVal() << endl;

    q.push(6); // circular insert
    cout << "Rear = " << q.rearVal() << endl;

    cout << "Front = " << q.frontVal() << endl;

    while (!q.empty()) {
        cout << "Popped: " << q.frontVal() << endl;
        q.pop();
    }

    cout << "Queue is now empty: " << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}
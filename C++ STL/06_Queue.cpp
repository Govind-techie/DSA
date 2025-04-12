/*

Queue : A Queue is a linear data structure that follows the First In, First Out (FIFO) principle. This means that the first element added to 
the queue will be the first one to be removed.

Think of it like a line at a ticket counter: the person who gets in line first will be the first to get served. In a queue, elements are 
added at the rear (enqueue) and removed from the front (dequeue).


Commonly Used Queue Functions
1.	push(): Adds an element to the back of the queue.
2.	emplace(): Constructs and adds an element to the back of the queue.
3.	pop(): Removes the element from the front of the queue.
4.	front(): Returns the element at the front of the queue (without removing it).
5.	back(): Returns the element at the back of the queue (without removing it).
6.	size(): Returns the number of elements in the queue.
7.	empty(): Checks if the queue is empty.
8.	swap(): Swaps the contents of one queue with another.

*/

#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int>q;

    q.push(1); // Add element to the back of the queue.
    q.push(2);
    q.push(3); 
    
    cout << "Front of queue: " << q.front() << endl; // q.front() returns the value stored at the front of the queue.
    
    while(!q.empty()){ // Checks whether the queue is empty or not.
        cout << "Front of queue: " << q.front() << endl;
        q.pop(); // Removes the element from the front of the queue.
    }
    
    cout << "Is queue empty: " << q.empty() << endl; // Based on whether the queue is empty or not, it returns a boolean value: true (1) or false (0).
    
    
    queue<int>q1;

    q1.push(1); 
    q1.push(2);
    q1.push(3); 

    queue<int>q2;

    q2.swap(q1); // Swaps the entire queue of q1 to q2, and q1 becomes empty.

    cout << "Is q1 queue empty: " << q1.empty() << endl; // Checks if q1 is empty after the swap.
    cout << "Front of q2 queue: " << q2.front() << endl; // Shows the front of q2 after the swap.
    
    // Size: size function returns the number of elements in the queue.
    cout << "Size of q2 queue: " << q2.size() << endl; // Output: 3
    
    return 0;
}
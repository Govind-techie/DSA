/*

Priority Queue : A priority queue is a data structure that stores elements in order of priority, where the element with the highest 
(or lowest) priority is always at the front. It supports efficient insertion, removal, and access to the element with the highest (or lowest)
priority. Typically, it is implemented using a heap.

You can think of a priority queue like a line at a ticket counter, but with a twist: instead of everyone being served in the order they 
arrived, people with higher priority get to jump ahead of others, no matter when they arrived.

Functions Used in the Priority Queue:
1.	push(): Adds an element to the priority queue.
2.	top(): Returns the element at the top of the priority queue (the element with the highest priority).
3.	pop(): Removes the element from the top of the priority queue.
4.	empty(): Checks whether the priority queue is empty and returns a boolean value.
5.	size(): Returns the number of elements in the priority queue.
6.	swap(): Swaps the entire contents of two priority queues.

*/

#include<iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int> pq; // Default max-heap priority queue: highest element has the highest priority.

    pq.push(1); // Adds an element to the priority queue.
    pq.push(3);
    pq.push(2); 
    
    cout << "Top of priority queue: " << pq.top() << endl; // pq.top() returns the value at the top of the priority queue.
    
    while(!pq.empty()){ // Checks whether the priority queue is empty or not.
        cout << "Top of priority queue: " << pq.top() << endl;
        pq.pop(); // Removes the element from the top of the priority queue.
    }
    
    cout << "Is priority queue empty: " << pq.empty() << endl; // Returns true (1) or false (0) if the priority queue is empty.
    
    
    priority_queue<int> pq1;

    pq1.push(1); 
    pq1.push(2);
    pq1.push(3); 

    priority_queue<int> pq2;

    pq2.swap(pq1); // Swaps the entire priority queue of pq1 to pq2, and pq1 becomes empty.

    cout << "Is pq1 priority queue empty: " << pq1.empty() << endl; // Checks if pq1 is empty after the swap.
    cout << "Top of pq2 priority queue: " << pq2.top() << endl; // Shows the top of pq2 after the swap.
    
    // Size: size function returns the number of elements in the priority queue.
    cout << "Size of pq2 priority queue: " << pq2.size() << endl; // Output: 3

    // Note : In general, Priority Queue elements are arranged in descending order for top to bottom according to the priority of each elements.

  // Note: By default, priority_queue gives the highest element the highest priority (max-heap behavior), but we can create a reverse 
  // priority queue by using a custom comparator to give the lowest element the highest priority.

    priority_queue<int, vector<int>, greater<int>> q; // Creates a priority queue where the smallest element has the highest priority due to the 'greater<int>' comparator (min-heap behavior).

    q.push(1); // (Highest Priority)
    q.push(3); // (Lowest Priority)
    q.push(2); 
    
    cout << "Top of priority queue: " << q.top() << endl; // Returns top value as the lowest element which has the highest priority.
    
    while(!q.empty()){ 
        cout << "Top of priority queue: " << q.top() << endl; 
        q.pop(); 
    }

    // Note : In this priority queue, the elements are arranged in ascending order from top to bottom, where the lowest element has the highest priority.
    
    return 0;
}
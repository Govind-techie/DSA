/*
Priority Queue in C++ STL

- Provides fast access to the highest priority element (max-heap by default).
- Implemented using a heap (usually a binary heap).
- Can be configured as a min-heap using greater.

Common operations:
  push(x)   - Insert element x
  pop()     - Remove the top element
  top()     - Access the top element
  size()    - Get the number of elements
  empty()   - Check if the queue is empty

Header: <queue> (uses <vector> and <functional> internally)

Syntax:
  priority_queue<Type> pq; // Max-heap
  priority_queue<Type,vector<Type>, greater<Type>> min_pq; // Min-heap

Note: By default, the top of the STL priority queue is the element with the highest value (max-heap).
*/

#include<iostream>
#include<queue> // Priority queue is built on top of the queue container adapter and internally uses vector and functional.
using namespace std;

int main(){
    priority_queue<int>pq1; // max-heap PQ

    priority_queue<int, vector<int>, greater<int>>pq2; // min-heap PQ
    // NOTE: greater<int> is a comparator which eventually change the priority of PQ in descending order.

    // max-heap priority queue
    pq1.push(5);
    pq1.push(10);
    pq1.push(12);
    pq1.push(3);

    cout << "max-heap priority queue (ascending order)" << endl;
    while (!pq1.empty()){
        cout << "top : " << pq1.top() << endl; // O(1)
        pq1.pop(); // O(logn)
    } cout << endl;
    
    // min-heap priority queue
    pq2.push(5);
    pq2.push(10);
    pq2.push(12);
    pq2.push(3);
    
    cout << "min-heap priority queue (descending order)" << endl;
    while (!pq2.empty()){
        cout << "top : " << pq2.top() << endl; // O(1)
        pq2.pop(); // O(logn)
    }

    return 0;
}
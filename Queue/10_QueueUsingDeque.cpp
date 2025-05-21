/*
Queue Using Deque -> (IMPLEMENTATION)

1. A deque (double-ended queue) allows insertion and deletion at both ends.

2. To implement a queue using a deque:
   - Use push_back(x) to enqueue (add at rear).
   - Use pop_front() to dequeue (remove from front).
   - front() gives the front element.
   - empty() checks if the queue is empty.

3. All operations are O(1) using STL deque.

4. This approach is efficient and easy with C++ STL <deque>.
*/

#include<iostream>
#include<deque>
using namespace std;

template<class T>
class Queue {
    deque<T>dq; // underlying container to store queue elements

public: 

    void push(T val){ dq.push_back(val); } // insert element at the back of queue

    void pop(){ 
        if (empty()){ // check if queue is empty before popping
            cout << "Queue is EMPTY\n"; 
            return; 
        }
        dq.pop_front(); // remove element from front
    }

    T front(){ 
        if (empty()){ // check if queue is empty before accessing front
            cout << "Queue is EMPTY\n"; 
            return T(); // return default value of T (e.g., 0 for int)
        }
        return dq.front(); // return the front element
    }

    bool empty(){ return dq.empty(); } // check if queue is empty
};

int main() {
    Queue<int> q; // create custom queue of int type
    q.push(10); // enqueue 10
    q.push(20); // enqueue 20
    q.push(30); // enqueue 30

    while (!q.empty()) { // loop until queue becomes empty
        cout << q.front() << " "; // print front element
        q.pop(); // dequeue the front element
    } 
    cout << endl;
    return 0;
}
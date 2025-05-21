/*
Problem Statement: Interleave Two Queues

Description:
- Given two queues of equal size, interleave their elements into a single queue.
- The resulting queue should have elements in the following order: first element of first queue, first element of second queue, second element of first queue, second element of second queue, and so on.

Input:
- Two queues Q1 and Q2 of equal length.

Output:
- A single queue with elements interleaved from Q1 and Q2.

Example:
Input:
    Q1: 1 2 3
    Q2: 4 5 6

Output:
    1 4 2 5 3 6
*/

#include<iostream>
#include<queue>
using namespace std;

#include<iostream>
#include<queue>
using namespace std;

queue<int> interleave2Queues(queue<int>& org){
    queue<int> first; // store first half elements
    int n = org.size(); // total size of original queue

    for (int i = 0 ; i < n/2 ; i++){
        first.push(org.front()); // push first half into 'first'
        org.pop(); // remove from original
    }

    while (!first.empty()){
        org.push(first.front()); // push from first half
        first.pop(); // remove pushed element

        org.push(org.front()); // push from second half
        org.pop(); // remove pushed second half element
    }

    return org; // return interleaved queue
}

int main(){
    queue<int>q;
    q.push(1); // sample input
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    interleave2Queues(q); // call function

    while (!q.empty()) {
        cout << q.front() << " "; // print front element
        q.pop(); // remove printed element
    }
    cout << endl;
    
    return 0;
}
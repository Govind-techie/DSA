/*
Problem Statement: Implement a Queue using Two Stacks

Description:
- Design a class to implement a queue using two stacks.
- The queue should support the following operations:
    1. push(x): Insert element x at the end of the queue.
    2. pop(): Remove the element from the front of the queue.
    3. front(): Return the front element of the queue.
    4. empty(): Return true if the queue is empty, otherwise false.

Constraints:
- Use only standard stack operations (push, pop, top, empty).
- Do not use any STL queue or deque.

Example:
Input:

push(1)
push(2)
front() // returns 1
pop()
front() // returns 2
empty() // returns false

Output:
1
2
false
*/

#include<iostream>
#include<stack>
using namespace std;

class Queue {
    stack<int>s1;
    stack<int>s2;

public:

    void push(int val){
        // s1 -> s2
        while (!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(val);

        // s2 -> s1
        while (!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    void pop(){
        s1.pop();
    }

    int front(){
        return s1.top();
    }
    
};

int main(){

    return 0;
}
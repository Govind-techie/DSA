/*

Stack : A stack is a linear data structure that follows the Last In, First Out (LIFO) principle. This means the last element added to the 
stack is the first one to be removed.

Think of it like a stack of plates—you add plates on top, and when you need one, you take the topmost plate first.

Common Stack Functions (C++ STL)
1.	push(element) – Adds an element to the top of the stack.
2.	emplace(arguments...) – Constructs and adds an element at the top (more efficient than push).
3.	top() – Returns the top element without removing it.
4.	pop() – Removes the top element.
5.	size() – Returns the number of elements in the stack.
6.	empty() – Returns true if the stack is empty, otherwise false.
7.	swap(stack2) – Swaps the contents of two stacks.

*/

#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int>s;

    s.push(1); // push element at top of stack.
    s.push(2);
    s.push(3); 
    
    cout << "Top stack : " << s.top() << endl; // s.top() returns the value stored in the top stack.
    
    
    
    while(!s.empty()){ // Checks whether the stack is empty or not.
        cout << "Top stack : " << s.top() << endl;
        s.pop(); // Delete the top stack.
    }
    
    cout << "is stack empty : " << s.empty() << endl; // Based on stack is empty or not it returns a boolean value either true (1) or false (0).
    
    
    stack<int>s1;

    s1.push(1); 
    s1.push(2);
    s1.push(3); 

    stack<int>s2;

    s2.swap(s1); // It swaps entire stack of s1 to s2 and s1 stack get completely empty.

    cout << "is s1 stack empty : " << s1.empty() << endl;
    cout << "top of s2 stack : " << s2.top() << endl;

    
    // Size : size function returns the size of stack or no. of elements or stack stored in total
    cout << "Size of s2 stack : " << s2.size() << endl; // Output : 3
    
    return 0;
}
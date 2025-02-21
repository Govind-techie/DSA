/*

List : In STL, a list is a sequence container implemented as a doubly linked list, where each element is connected to its previous and next 
element via pointers. Unlike a vector, which provides fast random access using an index but has costly insertions/deletions in the middle, a 
list allows efficient insertions and deletions at any position but does not support direct element access using an index.


Advantages of list Being a Doubly Linked List

	1.	Efficient Insertions and Deletions : 
	•	list allows O(1) insertions and deletions at both front and back using:
	•	push_front() → Inserts an element at the beginning.
	•	push_back() → Inserts an element at the end.
	•	pop_front() → Removes the first element.
	•	pop_back() → Removes the last element.

Note: Some list-specific functions like remove(), sort(), merge(), and reverse() are not covered here since their use cases are straightforward 
and can be explored in the STL documentation for further detail. Additionally, general container functions like size() and many more have already been 
explained in the vector section, so you can refer to that for common operations.

Difference Beteween Vector and List : A vector uses contiguous memory and allows fast random access, while a list is a doubly linked list 
that allows efficient insertions and deletions but has slow random access.

*/


#include<iostream>
#include<list>
using namespace std;

int main(){
    // Initialization of a list

    list<int>l; // Initializing an empty list.
    list<int>l1 = {1,2,3,4,5};

    l.push_back(1); // Insert an element at the end of list.
    l.push_back(2);
    l.push_front(3); // Insert an element at the front of list.
    l.push_front(5);

    l.pop_back(); // Delete the last element of list
    l.pop_front(); // Delete the first element of list
    
    for (int val : l){
        cout << val << " ";
    } cout << endl;
    return 0;
}
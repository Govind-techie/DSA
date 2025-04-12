/*

Lower Bound:

The lower bound of an element in a sorted data structure (like set, map, or a sorted vector) is the first position where:
• If the element does not exist, it returns an iterator to the next greater element that maintains the order.
• It finds the given element if it exists.
• If all elements are smaller, it returns end().


Upper Bound:

The upper bound of an element in a sorted data structure (like set, map, or a sorted vector) is the first position where:
• It finds the next greater element than the given value.
• If the element exists multiple times, it returns an iterator to the element just after the last occurrence.
• If all elements are smaller, it returns end().

Note: lower_bound and upper_bound return an iterator (memory location), so we need to dereference (*) the iterator to access the actual value.

Note : Lower bound and upper bound work only on data structures that maintain a sorted order, such as set, map, and sorted vector.
*/

#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int> s;

    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(7);

    // Lower bound returns an iterator to the first element that is >= the given value.
    cout << "Lower Bound : " << *(s.lower_bound(4)) << endl; // Output: 4 (4 is present in the set)
    cout << "Lower Bound : " << *(s.lower_bound(5)) << endl; // Output: 7 (5 is not in the set, so it returns the next greater element)
    cout << "Lower Bound : " << *(s.lower_bound(8)) << endl; // Undefined behavior (8 is greater than all elements, so it returns s.end())


    // Upper bound returns an iterator to the first element that is > the given value.
    cout << "Upper Bound : " << *(s.upper_bound(4)) << endl; // Output: 7 (Next greater element after 4)
    cout << "Upper Bound : " << *(s.upper_bound(5)) << endl; // Output: 7 (5 is not in the set, so it returns the next greater element)
    cout << "Upper Bound : " << *(s.upper_bound(7)) << endl; // Undefined behavior (7 is the largest element, so it returns s.end())

     
    // Print all elements in the set
    for (int val : s) {
        cout << val << " ";
    }

    cout << endl;

    return 0;
}
/*

Multiset:  
A multiset is a data structure in C++ that allows storing duplicate elements in sorted order.  
It is similar to a set, but it does not remove duplicates automatically.

Think of it like a basket of fruits where:  
• You can add the same fruit multiple times.  
• The fruits are always arranged in a sorted manner.  

Difference between set and multiset:  
A set stores only unique elements, while a multiset allows duplicates.

*/

#include <iostream>
#include <set> // We have to include the <set> header file as multiset is a part of set STL file and does not have a separate file of its own.
using namespace std;

int main() {
    multiset<int> ms;

    ms.insert(1);
    ms.insert(2);
    ms.insert(3);
    ms.insert(4);
    ms.insert(5);

    ms.insert(1); // Unlike set, multiset allows duplicate values.

    cout << "Size: " << ms.size() << endl; // Output: 6 (Duplicate 1 is stored)

    for (int val : ms) {
        cout << val << " "; // It prints all values, including duplicates, in sorted order.
    }

    cout << endl;

    return 0;
}
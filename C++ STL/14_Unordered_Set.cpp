/*

Unordered Set:  
An unordered_set is a data structure in C++ that stores unique elements in random order using hashing for fast access.  
It provides average O(1) time complexity for insertion, deletion, and search.

Think of it like a basket where:  
• You can only add unique items.  
• The items are placed randomly, not in sorted order.  
• Finding an item is very fast on average.

Difference between set and unordered_set:  
A set stores elements in sorted order (O(log n)), while an unordered_set stores elements in random order (O(1) on average, but O(n) in worst case).


Note : The concepts of lower bound and upper bound do not apply to unordered_set as it does not maintain any specific order.
*/

#include <iostream>
#include <unordered_set> // We have to include an unordered set file separately as it is not a part of set STL file.
using namespace std;

int main() {
    unordered_set<int> us;

    us.insert(4);
    us.insert(2);
    us.insert(1);
    us.insert(5);
    us.insert(3);

    us.insert(1); // Duplicate values are not allowed.

    cout << "Size: " << us.size() << endl; // Output: 5 (No duplicate 1 stored)

    for (int val : us) {
        cout << val << " "; // Order is not guaranteed to be sorted.
    }

    cout << endl;

    return 0;
}
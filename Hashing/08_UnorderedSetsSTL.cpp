/*
Unordered Set (STL)

- unordered_set is an associative container that stores unique elements.
- It uses hashing internally for fast insertion, deletion, and lookup.
- Average time complexity for insert, search, and erase is O(1).

Key points:
  - All elements are unique (no duplicates allowed).
  - No guaranteed order of elements (unordered).
  - Provides functions like insert(), erase(), find(), and count().

Header: <unordered_set>

Example usage:
  unordered_set<int> s;
  s.insert(10);
  s.insert(20);
  s.insert(10); // Duplicate, will not be added
*/
#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    unordered_set<int> us;

    // Insert elements (duplicates are ignored)
    us.insert(1);
    us.insert(2);
    us.insert(3);
    us.insert(4);
    us.insert(5);
    us.insert(1); // Ignored
    us.insert(1); // Ignored
    us.insert(1); // Ignored

    cout << "Size: " << us.size() << endl;  // Output: 5

    // Check if 3 exists
    if (us.find(3) != us.end()) {
        cout << "3 found" << endl;
    } else {
        cout << "3 not found" << endl;
    }

    // Check if 6 exists
    if (us.find(6) != us.end()) {
        cout << "6 found" << endl;
    } else {
        cout << "6 not found" << endl;
    }

    // Erase 3
    us.erase(3);

    cout << "Size after erase: " << us.size() << endl;

    // Check if 3 exists again
    if (us.find(3) != us.end()) {
        cout << "3 found after erase" << endl;
    } else {
        cout << "3 not found after erase" << endl;
    }

    // NOTE: us.end() represent NULL

    for (auto el : us){
        cout << el << " "; // Output: 5 2 4 1 (stored unordered) 
    }
    cout << endl;
    return 0;
}

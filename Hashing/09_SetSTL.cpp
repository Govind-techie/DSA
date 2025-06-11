/*
Set (STL)

- set is an associative container that stores unique elements in sorted (ascending) order.
- Internally implemented using a balanced binary search tree (typically Red-Black Tree).
- Time complexity for insert, search, and erase is O(log n).

Key points:
  - All elements are unique (no duplicates allowed).
  - Elements are automatically sorted in increasing order.
  - Provides functions like insert(), erase(), find(), count(), and lower_bound().

Header: <set>

Example usage:
  set<int> s;
  s.insert(10);
  s.insert(20);
  s.insert(10); // Duplicate, will not be added

  for (int x : s){
      cout << x << " "; // Output: 10 20
  }
*/

#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int> s;

    // Insert elements (duplicates are ignored)
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(1); // Ignored
    s.insert(1); // Ignored
    s.insert(1); // Ignored

    cout << "Size: " << s.size() << endl;  // Output: 5

    // Check if 3 exists
    if (s.find(3) != s.end()) {
        cout << "3 found" << endl;
    } else {
        cout << "3 not found" << endl;
    }

    // Check if 6 exists
    if (s.find(6) != s.end()) {
        cout << "6 found" << endl;
    } else {
        cout << "6 not found" << endl;
    }

    // Erase 3
    s.erase(3);

    cout << "Size after erase: " << s.size() << endl;

    // Check if 3 exists again
    if (s.find(3) != s.end()) {
        cout << "3 found after erase" << endl;
    } else {
        cout << "3 not found after erase" << endl;
    }

    // NOTE: s.end() acts like NULL — returned when element is not found

    for (auto el : s){
        cout << el << " "; // Output: 1 2 4 5 (stored in sorted order) 
    }
    cout << endl;
    return 0;
}
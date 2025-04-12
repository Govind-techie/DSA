/*  
Unordered Map:  
An `unordered_map` is a key-value data structure in C++ where data is stored randomly in memory using hashing for fast access.  

Think of it like a dictionary**:  
- You look up a word (key) → It instantly gives you the meaning (**value**).  
- The words (keys) are **not stored in order**, but you can quickly find any word.  

Key Features:  
Fast access: O(1) on average (uses hashing).  
Keys are unique: No duplicate keys allowed.  
Random order: Elements are **not** stored in sorted order.  

Note:
Most commonly used functions in unordered_map (like insert, erase, find, size, empty, etc.)
are the same as in map and have already been explained in detail in the map section.
This section mainly focuses on the key differences between map and unordered_map and its different use cases.
*/

#include <iostream>
#include <unordered_map> // Separate header file needed for unordered_map.
using namespace std;

int main() {
    unordered_map<string, int> m;

    // Insert key-value pairs
    m.emplace("tv", 30); // In unordered map we can't store duplicate key value pair unlike multimap.
    m.emplace("laptop", 40); 
    m.emplace("tablet", 20); 

    // Print all key-value pairs:
    for (auto p : m) {
        cout << p.first << " : " << p.second << endl; // In unordered map the value does not print according to alphabetic order unlike map.
    } 

    /*  
    Map vs. Unordered Map: 
    - `map` stores keys in sorted order (O(log n)).  
    - `unordered_map` stores keys in random order (O(1) on average, faster).  
    */

    return 0;
}
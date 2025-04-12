/*  
Multimap:  
A `multimap` is a data structure that allows multiple values to be associated with the same key.  
Unlike `map`, which stores unique keys, `multimap` allows duplicate keys.  

Example:  
If a store sells the same product at different prices, a `multimap` can store multiple prices for the same product name.  

Note:  
Most commonly used functions in `multimap` (like insert, erase, find, size, empty, etc.)  
are the same as in `map` and have already been explained in detail in the `map` section.  
This section mainly focuses on the key differences between `map` and `multimap`.  
*/

#include <iostream>
#include <map> // Multimap is part of the map STL, so no extra header is needed.
using namespace std;

int main() {
    multimap<string, int> m;

    // m["tv"] = 20; // Error: Square bracket notation is not allowed in multimap.

    // To insert key-value pairs, use emplace() or insert():
    m.emplace("tv", 20);  // Multimap allows duplicate keys.
    m.emplace("tv", 30);
    m.emplace("tv", 40);
    m.emplace("tv", 20);  // Duplicate key-value pair

    // Print all key-value pairs:
    for (auto p : m) {
        cout << p.first << " : " << p.second << endl;
    }

    // Difference between Map and Multimap:  
    // `map` stores unique keys.  
    // `multimap` allows duplicate keys.  

    // Erasing a specific occurrence of "tv":
    m.erase(m.find("tv")); // Removes only the first occurrence of "tv" (smallest iterator).
    
    // Erasing all occurrences of "tv":
    m.erase("tv"); // Removes all key-value pairs where key == "tv".

    cout << "Is multimap empty? " << m.empty() << endl; // Will print 1 (true) since all values were erased.

    return 0;
}
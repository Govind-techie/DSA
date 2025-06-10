/*
Hashing in Data Structures

- Hashing is a technique to map data (keys) to fixed-size values (hash codes) for fast access.
- Used in data structures like hash tables, hash maps, and sets.

Key points:
  1. Hash Function: Converts a key to an index.
  2. Collision: When two keys map to the same index.
  3. Applications: Fast lookup, duplicate checking, caching, etc.
  4. Time Complexity: Average O(1) for insert/search/delete.
  5. Load Factor: Ratio of elements to table size; affects performance.

Note:
- C++ STL provides unordered_map and unordered_set which use hashing internally.
*/

#include<iostream>
#include<unordered_map> // (HashTable STL Container)
using namespace std;

int main(){
    // Initialisation
    unordered_map<string, int> hashTable;

    // Insertion (Average Time Complexity: O(1))
    hashTable["apple"] = 5;
    hashTable["banana"] = 3;
    hashTable["orange"] = 7;

    // Search (Average Time Complexity: O(1))
    if(hashTable.find("banana") != hashTable.end()) {
        cout << "banana found, value = " << hashTable["banana"] << endl;
    } else {
        cout << "banana not found" << endl;
    }

    // Deletion (Average Time Complexity: O(1))
    hashTable.erase("apple");

    // Traversal (Time Complexity: O(n))
    cout << "Current elements in hashTable:" << endl;
    for(auto &pair : hashTable) {
        cout << pair.first << " : " << pair.second << endl;
    }

    /*
    NOTE: Most hash table operations (insert, search, delete) have average-case time complexity O(1).
    However, in rare cases with many collisions, the time complexity can degrade to O(n).
    */

    return 0;
}
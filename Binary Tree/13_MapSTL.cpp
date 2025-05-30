/*
Map in C++ STL

- A map is an associative container that stores key-value pairs.
- Each key is unique; values can be duplicated.
- Keys are automatically sorted (by default, in ascending order).
- Implemented as a balanced binary search tree (usually Red-Black Tree).

Syntax:
    map<key_type, value_type> mapName;

Common Operations:
- insert({key, value})   : Insert a key-value pair.
- erase(key)             : Remove element by key.
- find(key)              : Returns iterator to key, or map.end() if not found.
- [] operator            : Access or insert value by key.
- size()                 : Returns number of elements.
- clear()                : Removes all elements.

Example:
    map<int, string> m;
    m[1] = "apple";
    m[2] = "banana";
    m.insert({3, "cherry"});

    // Iterate over map
    for (auto it : m) {
        cout << it.first << " " << it.second << endl;
    }

Notes:
- If you access a key that does not exist using [], it will be created with a default value.
- Use unordered_map if you do not need sorted keys and want faster average access (hash table).
*/

#include<iostream>
#include<map>
#include<string>
using namespace std;

int main() {
    map<int, string> m;

    // Inserting key-value pairs into the map
    m[12] = "ABC";
    m[13] = "XYZ";
    m[14] = "ABC";

    // NOTE: Keys in a map are unique. Values can be duplicated across different keys.
    // NOTE: Accessing a non-existing key will insert it into the map with a default value.

    cout << m[12] << "\n";  // Output: ABC (value associated with key 12)
    cout << m[14] << "\n";  // Output: ABC (value associated with key 14)

    // Accessing a non-existent key inserts it with an empty string (default value for string)
    cout << m[100] << endl;  // Output: (empty line)

    // Assigning a value to key 100
    m[100] = "PQR";
    cout << m[100] << endl;  // Output: PQR

    // Updating the value associated with an existing key
    m[13] = "ABC";  // Overwrites "XYZ" with "ABC"

    // Check if a key exists in the map using count()
    cout << m.count(13) << endl;  // Output: 1 (key 13 exists)
    cout << m.count(15) << endl;  // Output: 0 (key 15 does not exist)

    // Iterating through all key-value pairs in the map
    for (auto it : m) {
        cout << "key = " << it.first << ", value = " << it.second << endl;
    }

    /*
    Output:
    key = 12, value = ABC
    key = 13, value = ABC
    key = 14, value = ABC
    key = 100, value = PQR
    */

    // NOTE: The 'auto' keyword automatically infers the type of the iterator in the loop.

    return 0;
}
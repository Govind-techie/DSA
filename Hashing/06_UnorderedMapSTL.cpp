/*
Unordered_map (STL)

- unordered_map is an associative container that stores key-value pairs.
- It uses hashing internally for fast access, insertion, and deletion.
- Average time complexity for insert, search, and erase is O(1).

Key points:
  - Keys are unique (no duplicates allowed).
  - No guaranteed order of elements (unordered).
  - Provides functions like insert(), erase(), find(), and operator[].

Header: <unordered_map>

Example usage:
  unordered_map<string, int> mp;
  mp["apple"] = 5;
  mp["banana"] = 3;
*/

#include<iostream>
#include<unordered_map>
#include<utility>
#include<string>
using namespace std;

int main(){
    unordered_map<string, int> um;

    // Insert key-value pair — Avg: O(1), Worst: O(n)
    um["India"] = 150;
    cout << um["India"] << endl;

    // Declare key without value (default initializes to 0)
    um["Japan"];

    // Check if a key exists — returns 1 (true) or 0 (false)
    cout << um.count("India") << endl;  // 1
    cout << um.count("China") << endl;  // 0

    // Add more key-value pairs
    um["Japan"] = 10;
    um["Canada"] = 30;
    um["UK"] = 45;
    um["China"] = 150;

    // Iterate through map and print key-value pairs
    for (pair<string, int> country : um){
        cout << "(" << country.first << "," << country.second << ")" << endl;
    }

    /*
    Note: unordered_map does not maintain insertion or sorted order.
    Any order you observe is due to internal hashing and is not guaranteed.
    Using pair<string, int> in the loop does NOT cause sorting by key.
    */

    // Erase a key
    um.erase("China");
    cout << um.count("China") << endl;  // 0 (false)

    // Update value of an existing key
    cout << um["India"] << endl;  // 150
    um["India"] = 140;            // Updates value, key stays unique
    cout << um["India"] << endl;  // 140

    return 0;
}
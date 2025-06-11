/*
Map (STL)

- map is an associative container that stores key-value pairs in sorted order by keys.
- It uses a self-balancing Binary Search Tree (like Red-Black Tree) internally.
- Average and worst-case time complexity for insert, search, and erase is O(log n).

Key points:
  - Keys are unique (no duplicates allowed).
  - Elements are stored in increasing order of keys (sorted).
  - Provides functions like insert(), erase(), find(), and operator[].

Header: <map>

Example usage:
  map<string, int> mp;
  mp["apple"] = 5;
  mp["banana"] = 3;
*/

#include<iostream>
#include<map>
#include<utility>
#include<string>
using namespace std;

int main(){
    map<string, int> mp;

    // Insert key-value pair — O(log n)
    mp["India"] = 150;
    cout << mp["India"] << endl;  // Output: 150

    // Insert key without assigning value — default-initialized to 0
    mp["Japan"];
    cout << mp["Japan"] << endl;  // Output: 0

    // Check if key exists — returns 1 (true) or 0 (false)
    cout << mp.count("India") << endl;  // Output: 1
    cout << mp.count("China") << endl;  // Output: 0

    // Add more key-value pairs
    mp["Japan"] = 10;
    mp["Canada"] = 30;
    mp["UK"] = 45;
    mp["China"] = 150;

    // Iterate through the map — keys printed in sorted order
    for (pair<string, int> country : mp){
        cout << "(" << country.first << ", " << country.second << ")" << endl;
    }

    /*
    Note:
    - Keys are printed in sorted order because map uses balanced BST (Red Black Tree) internally.
    - If you need faster average operations without sorted keys, use unordered_map.
    */

    // Erase a key — O(log n)
    mp.erase("China");
    cout << mp.count("China") << endl;  // Output: 0

    // Update value of an existing key — O(log n)
    cout << mp["India"] << endl;  // Output: 150
    mp["India"] = 140;
    cout << mp["India"] << endl;  // Output: 140

    return 0;
}
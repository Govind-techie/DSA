/*
Hash Function in Hashing

- A hash function converts a key into a fixed-size integer (hash code).
- Used to determine the index for storing data in a hash table.
- A good hash function distributes keys uniformly to minimize collisions.

Common points:
  - Should be fast to compute.
  - Should minimize collisions (different keys mapping to same index).
  - Depends on data type (integers, strings, etc).

Examples:
  For integers: hash = key % table_size;
  For strings: Combine ASCII values and use modulo.

Note: The quality of the hash function directly affects the performance of hashing-based data structures.
*/

#include<iostream>
#include<vector>
using namespace std;

// Basic hash function: returns index for a given key
int hashFunction(int key, int tableSize) {
    return key % tableSize;
}
// NOTE: Taking key % tableSize ensures the result (index) is always in the range 0 to tableSize - 1.

int main(){
    int n = 10; // Size of hash table
    vector<int> hashTable(n, -1); // Initialize with -1 (empty)

    int key = 23;
    int index = hashFunction(key, n); // Use hash function to get index

    hashTable[index] = key; // Store key at computed index

    cout << "Key " << key << " stored at index " << index << endl;

    // Print hash table
    cout << "Hash Table: ";
    for(int i = 0; i < n; i++) {
        cout << hashTable[i] << " ";
    }
    cout << endl;

    return 0;
}
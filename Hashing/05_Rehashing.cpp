/*
Rehashing in Hash Tables

- Rehashing is the process of resizing the hash table and re-inserting all existing elements.
- It is used to maintain efficient performance as the number of elements grows.

Common points:
  - Triggered when the load factor (number of elements / table size) exceeds a threshold (commonly > 1).
  - The table size is usually doubled during rehashing.
  - All existing keys are re-inserted using the new hash function (since the table size has changed).
  - Helps keep insert/search/delete operations close to O(1) time.

Example:
  - If a table of size 5 becomes full, create a new table of size 10 and re-insert all elements.

Note: Rehashing is an expensive operation (O(n)), but it happens rarely and ensures good average-case performance.
*/
#include<iostream>
#include<vector>
using namespace std;

/*
This function is a simple hash function:
It maps a key to an index in the table using modulo operator.
*/
int hashFunction(int key, int tableSize) {
    return key % tableSize;
}

/*
Function to rehash the old hash table into a new one with double the size.
It reinserts all existing keys into the new table.
*/
void rehash(vector<int>& oldTable, vector<int>& newTable) {
    for (int i = 0; i < oldTable.size(); i++) {
        if (oldTable[i] != -1) {
            int key = oldTable[i];
            int idx = hashFunction(key, newTable.size());
            
            // Linear probing in case of collision
            while (newTable[idx] != -1) {
                idx = (idx + 1) % newTable.size();
            }
            newTable[idx] = key;
        }
    }
}

int main() {
    int initialSize = 4;
    vector<int> hashTable(initialSize, -1); // -1 means empty

    // Sample keys to insert
    vector<int> keys = {10, 20, 30, 40, 50};

    int count = 0;
    for (int key : keys) {
        // If table is full, trigger rehashing
        if (count == hashTable.size()) {
            cout << "Rehashing..." << endl;
            vector<int> newTable(hashTable.size() * 2, -1);
            rehash(hashTable, newTable);
            hashTable = newTable;
        }

        // Insert key into hash table using linear probing
        int idx = hashFunction(key, hashTable.size());
        while (hashTable[idx] != -1) {
            idx = (idx + 1) % hashTable.size();
        }
        hashTable[idx] = key;
        count++;
    }

    // Display final hash table
    cout << "Final Hash Table: ";
    for (int i = 0; i < hashTable.size(); i++) {
        cout << hashTable[i] << " ";
    }
    cout << endl;

    return 0;
}
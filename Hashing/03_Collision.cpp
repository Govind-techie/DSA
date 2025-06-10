/*
Collision in Hashing

- A collision occurs when two different keys produce the same hash code (index) in a hash table.
- Collisions are unavoidable due to limited table size and many possible keys.

Common points:
  - Collisions must be handled to maintain correct data storage and retrieval.
  - Good hash functions reduce, but do not eliminate, collisions.
  - Collision handling methods:
      1. Chaining: Store multiple elements at the same index using a list or vector.
      2. Open Addressing: Find another open slot (linear probing, quadratic probing, double hashing).

Examples:
  - Inserting keys 5 and 15 into a table of size 10: both hash to index 5 (5 % 10 = 5, 15 % 10 = 5).

Note: Efficient collision handling is essential for maintaining fast operations in hash-based data structures.
*/

#include<iostream>
#include<vector>
using namespace std;

/*
- A collision occurs when two different keys produce the same hash code (index) in a hash table.
- Collisions are unavoidable due to limited table size and many possible keys.
*/

// Function to demonstrate collision in hashing
void showCollision(int key1, int key2, int tableSize) {
    int index1 = key1 % tableSize;
    int index2 = key2 % tableSize;

    cout << "Index for key " << key1 << " : " << index1 << endl;
    cout << "Index for key " << key2 << " : " << index2 << endl;

    if(index1 == index2) {
        cout << "Collision occurs: Both keys map to the same index " << index1 << endl;
    } else {
        cout << "No collision: Keys map to different indices." << endl;
    }
}

int main(){
    int n = 10;
    int key1 = 5;
    int key2 = 15;
    showCollision(key1, key2, n);
    return 0;
}
/*
Custom Hash Table Implementation

This code implements a basic Hash Table using:
- Separate Chaining to handle collisions (via linked lists)
- A custom hash function for string keys
- Rehashing to maintain efficiency when the load factor increases

Concepts Covered:

1. Hash Table Basics:
   - Maps string keys to int values.
   - Fast average-case operations: insert, search, and delete in O(1) time.

2. Separate Chaining:
   - Each bucket (index) of the table stores a linked list to handle collisions.
   - All key-value pairs that hash to the same index are stored in the same chain.

3. Custom Hash Function:
   - Uses the sum of squares of ASCII values of characters in the key.
   - Modulo operation ensures the index lies within table bounds.

4. Load Factor and Rehashing:
   - Load factor (lambda) = currSize / tableSize.
   - If lambda > 1, the table is rehashed (i.e., doubled in size and all keys reinserted).
   - Ensures time complexity stays near O(1) as size grows.

5. Linked List (Node Class):
   - Each node stores: key, value, and next pointer.
   - Recursive destructor ensures memory is cleaned when nodes are deleted.

6. Functionalities Implemented:
   - insert(string key, int val)      - Adds a key-value pair  
   - erase(string key)                - Deletes a key from the table  
   - exist(string key)                - Checks if key exists (returns true or false)  
   - search(string key)               - Returns value associated with key or -1 if not found  
   - printHashTable()                 - Prints the entire hash table (each index and its chain)

Time and Space Complexity:
- Insert/Search/Delete (average case): O(1)
- Insert/Search/Delete (worst case): O(n) when all elements hash to the same index
- Rehashing: O(n), but happens rarely (amortized constant time)

Usage Example (in main):
- Inserts countries with population values.
- Searches and checks for existence.
- Demonstrates deletion and automatic rehashing.
- Prints the internal structure of the hash table after operations.
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

// Node class for Linked List used in HashTable chaining
class Node{
public:
    string key;
    int val;
    Node* next;

    Node(string key, int val){
        this->key = key;
        this->val = val;
        next = NULL; // Initially next is NULL
    }

    // Recursive destructor to delete entire linked list from this node
    ~Node(){
        if (next != NULL){
            delete next;
        }
    }
};

class HashTable{
    vector<Node*> ht; // Array of pointers to Node (chaining)
    int tableSize;    // Total size of the hash table
    int currSize;     // Current number of elements in the hash table
public:
    // Constructor — O(n)
    HashTable(int tableSize){
        this->tableSize = tableSize;
        ht.resize(tableSize, NULL);
        currSize = 0;
    }

private:
    // Hash Function — O(L), where L is length of the key
    int hashFunction(string key){
        int hash = 0;
        for (char ch : key){
            hash = (hash + (int(ch) * int(ch))) % tableSize; // Sum of squares of characters
        }
        return hash % tableSize; // Ensures index is within table size
    }

    // Rehash Function — O(n), where n is the number of elements in the table
    void rehash(){
        vector<Node*> oldHt = ht;
        int oldTableSize = tableSize;
        tableSize *= 2;

        ht.clear();
        ht.resize(tableSize, NULL);
        currSize = 0;

        for (int i = 0; i < oldTableSize; i++){
            Node* temp = oldHt[i];
            while (temp != NULL){
                insert(temp->key, temp->val); // O(1) amortized per insert
                temp = temp->next;
            }
            if (oldHt[i] != NULL){
                delete oldHt[i]; // Deletes entire linked list at index
            }
        }
    }

public:
    // Insert — O(1) average case, O(n) worst case (if rehashing or key found deep in chain)
    void insert(string key, int val){
        int idx = hashFunction(key);
        Node* temp = ht[idx];

        // First, check if key already exists — if yes, update value
        while (temp != NULL){
            if (temp->key == key){
                temp->val = val; // Update existing value
                return;
            }
            temp = temp->next;
        }

        // Key does not exist — insert at head
        Node* newNode = new Node(key, val);
        newNode->next = ht[idx];
        ht[idx] = newNode;
        currSize++;

        double lambda = currSize / double(tableSize);
        if (lambda > 1){
            cout << "rehasing.." << endl;
            rehash();
        }
    }

    // Erase — O(1) average case, O(n) worst case (linked list traversal)
    void erase(string key){
        int idx = hashFunction(key);
        Node* curr = ht[idx];
        Node* prev = NULL;

        while (curr != NULL){
            if (curr->key == key){
                if (prev == NULL){
                    ht[idx] = curr->next;
                } else {
                    prev->next = curr->next;
                }
                curr->next = NULL;
                delete curr;
                currSize--;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    // Exist — O(1) average case, O(n) worst case (search linked list)
    bool exist(string key){
        int idx = hashFunction(key);
        Node* temp = ht[idx];
        while (temp != NULL){
            if (temp->key == key){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Search — O(1) average case, O(n) worst case (search linked list)
    int search(string key){
        int idx = hashFunction(key);
        Node* head = ht[idx];

        while (head != NULL){
            if (head->key == key){
                return head->val;
            }
            head = head->next;
        }
        return -1; // Key not found
    }

    // Print Hash Table — O(n), where n is total number of nodes in all chains
    void printHashTable(){
        for (int i = 0 ; i < ht.size() ; i++){
            cout << "idx" << i << " -> ";
            Node* temp = ht[i];
            while (temp != NULL){
                cout << "(" << temp->key << "," << temp->val << ")" << " -> ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main(){
    HashTable ht(4); // Create hash table with initial size 4

    ht.insert("India", 150);
    ht.insert("China", 150);
    ht.insert("Japan", 30);
    ht.insert("USA", 40);
    ht.insert("Canada", 20); // This may trigger rehashing

    cout << ht.exist("Japan") << endl;  // Should print 1 (true)
    cout << ht.search("Japan") << endl; // Should print 30

    ht.erase("China");                  // Delete key "China"
    cout << ht.exist("China") << endl;  // Should print 0 (false)

    ht.printHashTable();
    return 0;
}
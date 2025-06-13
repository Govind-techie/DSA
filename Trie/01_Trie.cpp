/*
Trie (Prefix Tree)

- A Trie is a tree-like data structure used for efficient retrieval of keys in a dataset of strings.
- Commonly used for autocomplete, spell checking, and prefix-based search.
- Each node represents a character of a string.
- The root node is typically empty, and each path down the tree represents a word or prefix.
- Supports operations like insert, search, and delete for strings.

Typical Trie Node Structure:
    - Array or map of child pointers (one for each possible character).
    - Boolean flag to mark the end of a word.

Example Operations:
    - Insert a word into the Trie.
    - Search for a word or prefix in the Trie.
    - Delete a word from the Trie (optional/advanced).

Note: A Trie is a k-ary tree (unlike a binary tree),
where each node can have multiple children — specifically
26 in the case of a prefix tree for lowercase English letters.

Use Case:
• Used for Retrieval Queries
• Used generally for Insert & Search ops
• Searches in O(L), L = key length but uses extra space.
*/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

// Node class represents each character node in the Trie
class Node {
public:
    unordered_map<char, Node*> child; // Maps character to its corresponding child node
    bool endOfWord; // Marks the end of a complete word

    Node() {
        endOfWord = false; // By default, it's not the end of any word
    }
};

class Trie {
    Node* root; // Root node of the Trie

public:
    Trie() {
        root = new Node(); // Initialize Trie with an empty root
    }

    // Insertion
    void insert(string key) { // Time complexity: O(L), where L is length of the word
        Node* temp = root;
        for (char ch : key) {
            if (!temp->child.count(ch)) { // If the character doesn't exist as a child
                temp->child[ch] = new Node(); // Create a new node for this character
            }
            temp = temp->child[ch]; // Move to the next node
        }
        temp->endOfWord = true; // Mark the end of the word
    }

    // Search
    bool search(string key) { // Time complexity: O(L), where L is length of the word
        Node* temp = root;
        for (char ch : key) {
            if (!temp->child.count(ch)) { // If any character not found, word doesn't exist
                return false;
            }
            temp = temp->child[ch]; // Move to the next node
        }
        return temp->endOfWord; // Return true only if it's the end of a valid word
    }
};

int main() {
    vector<string> words = {"the", "a", "there", "their", "any", "thee"};
    Trie t;

    // Insert all words into the Trie
    for (string key : words) {
        t.insert(key);
    }

    // Search results
    cout << t.search("their") << endl; // Output: 1 (true) — "their" exists in the Trie
    cout << t.search("thei") << endl;  // Output: 0 (false) — "thei" is a prefix but not a complete word

    // Explanation: "thei" exists as a path, but not marked as end of word (endOfWord = false)
    return 0;
}
/*
Unique Prefix Problem

Given a list of words, find the shortest unique prefix for each word.
A unique prefix is the smallest prefix of a word that is not shared with any other word in the list.

Example:
Input: ["dog", "dove", "duck"]
Output: ["dog", "dov", "du"]
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include<string>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> child;
    bool endOfWord;
    int freq;

    Node() {
        endOfWord = false;
        freq = 0; // Node except root should have freq 0
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
        root->freq = -1; // root freq -1 as no char in root
    }

    void insert(string word) {
        Node* curr = root;
        for (char ch : word) {
            if (!curr->child[ch]) {
                curr->child[ch] = new Node();
            }
            curr = curr->child[ch];
            curr->freq++; // count of how many words have same char
        }
        curr->endOfWord = true;
    }

    Node* getRoot() {
        return root;
    }
};

// This function finds the shortest unique prefix for a given word
string helper(string s, Node* root) {
    Node* curr = root;
    string prefix = "";

    for (int i = 0; i < s.length(); i++) {
        prefix += s[i];               // Add current character to prefix
        curr = curr->child[s[i]];     // Move to the next node

        // If this character is only used by one word, it's unique
        if (curr->freq == 1) {
            return prefix;
        }
    }

    // If no unique point is found, return full word as prefix
    return prefix;
}

// This function returns a list of shortest unique prefixes for each word
vector<string> uniquePrefix(vector<string>& dict) {
    Trie t;
    vector<string> res;

    // Insert all words into the Trie
    for (string word : dict) {
        t.insert(word);
    }

    Node* root = t.getRoot();  // Get the root of the Trie

    // For each word, find its unique prefix using helper function
    for (string word : dict) {
        res.push_back(helper(word, root));
    }

    return res;
}

int main() {
    vector<string> dict = {"dog", "dove", "dock"};
    vector<string> result = uniquePrefix(dict);

    for (string prefix : result) {
        cout << prefix << endl;
    }

    return 0;
}
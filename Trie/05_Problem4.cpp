/*
Count Unique Substrings Problem

Given a string s, count the total number of unique substrings of s.

Example:
Input: s = "ababa"
Output: 10
Explanation: The unique substrings are: "a", "b", "ab", "ba", "aba", "bab", "ababa", "bab", "aba",
*/
#include <iostream>
#include <unordered_map>
#include<string>
#include <vector>
using namespace std;


class Node {
public:
    unordered_map<char, Node*> child; // edges to next characters
    bool endOfWord; // true if a word ends here

    Node() : endOfWord(false) {}
};


class Trie {
    Node* root; // root of the trie
public:
    Trie() { root = new Node(); }

    void insert(const string& key) {
        Node* cur = root;
        for (char ch : key) {
            if (!cur->child.count(ch)) // create node if missing
                cur->child[ch] = new Node();
            cur = cur->child[ch]; // move to next char
        }
        cur->endOfWord = true; // mark end of word
    }

    bool search(const string& key) {
        Node* cur = root;
        for (char ch : key) {
            if (!cur->child.count(ch)) return false;
            cur = cur->child[ch];
        }
        return cur->endOfWord;
    }

    Node* getRoot() { return root; }

    int countNodes(Node* node) {
        int total = 1; // count this node
        for (auto& [ch, nxt] : node->child)
            total += countNodes(nxt); // add all children
        return total;
    }
};

int countUniqueSubstr(const string& str) {
    Trie t;
    for (size_t i = 0; i < str.size(); ++i)
        t.insert(str.substr(i)); // insert suffix

    return t.countNodes(t.getRoot());
}

int main() {
    string s = "ababa";
    cout << "Unique substrings in \"" << s << "\": "
         << countUniqueSubstr(s) << '\n'; // expected 9
    return 0;
}
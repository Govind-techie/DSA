/*
StartsWith Problem

Given a list of words, check if any word in the list starts with a given prefix.

Example:
Input: words = ["apple", "banana", "grape"], prefix = "app"
Output: true
*/

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> child;
    bool endOfWord; 

    Node() {
        endOfWord = false;
    }
};

class Trie {
    Node* root; 

public:
    Trie() {
        root = new Node(); 
    }

    // Insertion
    void insert(string key) {
        Node* temp = root;
        for (char ch : key) {
            if (!temp->child.count(ch)) { 
                temp->child[ch] = new Node(); 
            }
            temp = temp->child[ch];
        }
        temp->endOfWord = true; 
    }

    // Search
    bool search(string key) {
        Node* temp = root;
        for (char ch : key) {
            if (!temp->child.count(ch)) { 
                return false;
            }
            temp = temp->child[ch]; 
        }
        return temp->endOfWord; 
    }

    bool startsWith(string prefix){
        Node* curr = root;
    
        for (char ch : prefix){
            if (!curr->child.count(ch)){
                return false;
            }
            curr = curr->child[ch];
        }
        return true;
    }
};



int main() {
    Trie t;

    t.insert("apple"); // Add word apple
    cout << t.search("apple") << endl;   // true 
    cout << t.startsWith("app") << endl; // true => app is prefix of apple

    return 0;
}
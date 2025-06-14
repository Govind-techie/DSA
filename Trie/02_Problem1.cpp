/*
Problem: Word Break Problem

Given a string s and a list of words (dictionary), 
check if s can be split into a sequence of one or more dictionary words.

Example:
    s = "applepenapple"
    dict = ["apple", "pen"]
    Output: true
    Explanation: "apple pen apple" is a valid split.

Return true if possible, else false.

*/

#include<iostream>
#include<vector>
#include<string>
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
};

bool helper(string s, Trie&t, int st){
    if (st == s.length()) return true; // empty string
    string word = "";
    for (int i = st ; i < s.length() ; i++){
        word += s[i];
        if (t.search(word)){
            if (helper(s,t,i+1)) return true;
        }
    }

    return false;
}

bool wordBreak(string s, vector<string>&dict){
    Trie t;
    for (string str : dict) t.insert(str);
    return helper(s,t,0);
}

int main(){
    vector<string>dict = {"Data","Structure","And","Algorithm"};
    string s = "DataStructureAndAlgorithm";
    
    cout << wordBreak(s,dict) << endl;
    return 0;
}